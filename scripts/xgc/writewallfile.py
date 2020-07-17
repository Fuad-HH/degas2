#!/usr/bin/env python3
# This script generates a .aif wall file given .node and .ele files
# Nodes in wallfile are ordered clockwise
# George Wilkie, gwilkie@pppl.gov
import sys
import numpy as np
import matplotlib.pyplot as plt

arg = sys.argv[1]
nodefilename= arg+".node"
elefilename= arg+".ele"
aiffilename= arg+".aif"
pltfile= arg+".pdf"

iline =0
nwall = 0
file = open(nodefilename)
Rstring = []
Zstring = []
for line in file:
    if iline == 0:
        nnode = int(line.split()[0])
        Rarray = np.zeros(nnode)
        Zarray = np.zeros(nnode)
    elif iline+1 <= nnode:
        Rarray[iline-1] = line.split()[1]
        Zarray[iline-1] = line.split()[2]
        Rstring.append(line.split()[1])
        Zstring.append(line.split()[2])

        wallflag = int(line.split()[3])
        if wallflag == 1:
            nwall +=1
    iline+=1
file.close()

Rwall = np.zeros(nwall)
Zwall = np.zeros(nwall)
wallnodes = [-1]*nwall

iline =0
iwall = 0
file = open(nodefilename)
for line in file:
    if iline+1 <= nnode and iline > 0:
        wallflag = int(line.split()[3])
        if wallflag == 1:
            wallnodes[iwall] = int(line.split()[0])
            Rwall[iwall] = line.split()[1]
            Zwall[iwall] = line.split()[2]
            iwall += 1
    iline+=1
file.close()

# Checks if a triangle of nodes is a "wall triangle" by checking if
# exactly two of the nodes are among the wall nodes. Return an error 
# if three are found.
def nwallnodes(nodes,wallnodes):
    icount = 0
    for node in nodes:
        if node in wallnodes:
            icount += 1
    return icount

# Finds the next node on the boundary of the mesh. 
# Flag "first" is used to ensure a common direction (here, clockwise starting at the low field side)
# Does this by cycling through each "wall triangle" (see below) adjacent to current_node
# Then, finds the next node which satisfies the following conditions:
#   a) is not the previous node, and
#   b) follows a line segment that is shared with no other triangle
# Also checks to make sure not more than one next_node is found
def find_next_node(current_node,prev_node,wallnodes,walltriangles,Zvals,first):

    # Indices of the triangles that share current_node
    adjacent_wall_triangles = []
    nwalltriangles = np.shape(walltriangles)[0]
    for itri in range(nwalltriangles):
        if current_node in walltriangles[itri]:
            adjacent_wall_triangles.append(itri)

    n_adjacent_triangles = np.shape(adjacent_wall_triangles)[0]

    next_node = -1
    # Loop through the adjacent wall triangles that share the current node
    for itri in range(n_adjacent_triangles):

        tri_idx = adjacent_wall_triangles[itri]

        # Which vertex of this triangle is the current_node?
        vertex_idx = walltriangles[tri_idx].index(current_node)

        # Line segments of this triangle that share this vertex
        segments = []
        segments.append( [current_node,walltriangles[tri_idx][(vertex_idx+1)%3]] )
        segments.append( [current_node,walltriangles[tri_idx][(vertex_idx+2)%3]] )

        # Create list of adjacent triangles that excludes the one under consideration
        other_adjacent_triangles = adjacent_wall_triangles.copy()
        other_adjacent_triangles.pop(itri)
        
        other_adjacent_triangle_vertices = []
        for other_triangle_idx in other_adjacent_triangles:
            other_adjacent_triangle_vertices.append(walltriangles[other_triangle_idx][0])
            other_adjacent_triangle_vertices.append(walltriangles[other_triangle_idx][1])
            other_adjacent_triangle_vertices.append(walltriangles[other_triangle_idx][2])

        # Loop through segments that share the current node
        for segment in segments:
            # If there are not any other wall triangles that share this segment, we have found a candidate

            if (segment[1] in wallnodes) and (not (segment[1] in other_adjacent_triangle_vertices)) and (segment[1] != prev_node): 
                if first:
                    # Ensure we start by going clockwise from the low field side
                    if Zvals[segment[1]] > Zvals[current_node]:
                        next_node=segment[1]
                        first = False
                elif (next_node != -1):
                    sys.exit("Found multiple candidates for next_node. Logic of code fails.")
                else:
                    next_node = segment[1]

    if next_node == -1:
        sys.exit("Could not find a candidate next_node.")

    return next_node

iline =0
iwall = 0
walltrianglenodes = []
walltriangleidx = []
file = open(elefilename)
for line in file:
    if iline == 0:
        nele = int(line.split()[0])
    elif iline+1 <= nele:
        trianglenodes = [-1]*3
        trianglenodes[0] = int(line.split()[1])
        trianglenodes[1] = int(line.split()[2])
        trianglenodes[2] = int(line.split()[3])
        triangleidx = int(line.split()[0])

        # nwallnodes = 1 doesn't give us any info about which node comes next, keep it out of array of wall triangles.
        if nwallnodes(trianglenodes,wallnodes) >= 2:
            walltriangleidx.append(triangleidx)
            walltrianglenodes.append(trianglenodes)
            iwall+=1
    iline+=1
file.close()

# Start at innermost (least R) node and go clockwise
inner=np.argmin(Rwall)
current_node = wallnodes[inner]
prev_node = current_node
first = True
wall_nodes_ordered = []
for i in range(nwall):
    wall_nodes_ordered.append(current_node)

    next_node = find_next_node(current_node,prev_node,wallnodes,walltrianglenodes,Zarray,first)
    prev_node = current_node
    current_node = next_node
    first = False

if current_node != wall_nodes_ordered[0]:
    sys.exit("Boundary does not close in on itself")

Rwall = []
Zwall = []
for i in range(nwall):
    Rwall.append(Rarray[wall_nodes_ordered[i]-1])
    Zwall.append(Zarray[wall_nodes_ordered[i]-1])

#plt.scatter(Rarray,Zarray,c='g',marker='.')
plt.plot(Rwall,Zwall,"-")

plt.xlabel("R")
plt.ylabel("Z")
plt.savefig(pltfile)
plt.close()

f = open(aiffilename,"w")
f.write("1\n")
f.write(str(np.size(Rwall))+"\n")
for idx in wall_nodes_ordered:
    f.write(Rstring[idx]+" "+Zstring[idx]+"\n")
f.close()


