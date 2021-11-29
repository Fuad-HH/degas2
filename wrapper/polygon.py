import numpy as np
import copy
import sys
import matplotlib.pyplot as plt

# A polygon is an ordered set of vertices, connected by segments which close in on itself.
class Polygon:
    numPolygons = 0 # Polygons start counting from 1

    def __init__(self,increment=True):
        self.vertices = []
        self.id = Polygon.numPolygons
        if increment:
            Polygon.numPolygons += 1
        self.alongwall = False

    # Polygons are equal if their vertices are equal
    def __eq__(self,other):
        return self.vertices == other.vertices

    def __ne__(self,other):
        return self.vertices != other.vertices

    def add_vertex(self,vertex):
        self.vertices.append(vertex)

    def clear_numPolygon():
        Polygon.numPolygons = 0

    def get_n_wallnodes(self):
        nwallnodes = 0
        for vertex in self.vertices:
            if vertex.wall:
                nwallnodes += 1
        return nwallnodes

    def get_first_wallnode(self):
        # Expects one contiguous set of nodes that are designated as wall nodes
        # Also expects at least one node that is not a wall node.
        first = -1
        count = 0
        nvertex = len(self.vertices)
        wallarray = [0]*nvertex 
        idx = 0
        for idx in range(0,nvertex):
            if self.vertices[idx].wall:
                count += 1
                if not self.vertices[idx-1].wall:
                    first = idx
        if first == -1 and (count < len(self.vertices)):
            sys.exit("Error: get_first_wallnode could not find the first wall node.")
        return first

    def reorder_wallnodes_first(self):
        nwallnodes = self.get_n_wallnodes()
        nvertex = len(self.vertices)
        if nwallnodes >= 1:
            first = self.get_first_wallnode()
            temp = copy.deepcopy(self.vertices)
            for idx in range(0,nvertex):
                temp[idx] = self.vertices[(idx+first)%nvertex]
            self.vertices = copy.deepcopy(temp)

        # use return value if expecting more than one wall segment
        return nwallnodes 

    # Linearly extrapolate the last two vertices defined for this polygon
    # and find the point on the specified surface which is closest to said line.
    # Returns index of said point
    def get_next_vertex_extrapolated_to_wall(self,wall):
        # These last two points defined thus far for the polygon define
        # the line to which we are seeking the closest point on wall
        point1 = self.vertices[-2].coords
        point2 = self.vertices[-1].coords

        dir = [np.sign(point2[0]-point1[0]),np.sign(point2[1]-point1[1])]

        first = True
        idx = 0
        closest_idx = 0
        for vertex in wall.vertices:
            # Only check points that are on the correct half-plane according to 
            # the directionality of the last two points
            if ( (dir[0]*(vertex.coords[0] - point1[0])>0) or (dir[0] == 0)) and \
               ( (dir[1]*(vertex.coords[1] - point1[1])>0) or (dir[1] == 0)):
                current_distance_sq = ( (point2[1]-point1[1])*(point1[0]-vertex.coords[0] )
                    - (point2[0]-point1[0])*(point1[1]-vertex.coords[1] ) )**2 \
                    / ( (point2[1]-point1[1])**2 + (point2[0]-point1[0])**2 )
                    
                if first:
                    closest_vertex=vertex
                    closest_idx = idx
                    closest_distance_sq = current_distance_sq
                    first = False
                elif current_distance_sq < closest_distance_sq:
                        closest_vertex = vertex
                        closest_idx = idx
                        closest_distance_sq = current_distance_sq
            idx +=1

        return closest_idx

    # Adds surfaces to construct a polygon. Entire is an array to determine which surfaces
    # get added in their entirity. 
    # If entire[i] = True, the entire surface[i] gets added (e.g. an open or closed flux surface)
    # If entire[i] = False, only a subset that gets added. Which points to add are determined by 
    #                extrapolating from the previous and next entire surface
#    def construct_from_surfaces(self,surfaces,entire):
#        if (len(surfaces) == 2) and surfaces[0].closed and surfaces[1].closed:
#            # To deal with two closed surfaces, connect the first points of each to form polygon
#        else:
#            reverse = False
#            for isurf in range(0,len(surfaces)):
#                if entire[isurf]:
#                    for vertex in surfaces[isurf].vertices:
#                        self.add_vertex(vertex)
#                    # Reverse direction for next entire surface
#                    reverse = not reverse 
#                else:
#                    if isurf == 0:
#                        print("Error. Need to start with an entire surface in call to construct_from_surfaces. Don't know how to begin defining polygon.")
#                        sys.exit(1)
#                    idx = self.add_next_vertex_extrapolated_to_wall(surfaces[isurf])

    # wallnodes is a collection of integer identifiers that make up the outer wall
    # they must go *counter*-clockwise, start with the innermost, share a common wall (wallid)

    def close_in_universal_cell(f,wallnodes,wallid,stratum,material,recyc,debug=False,clockwise=False,walltemp=300.0):
        f.write("new_zone solid\n")
        f.write("new_polygon\n")
        f.write("  material "+material+"\n")
        f.write("  recyc_coef "+str(recyc)+"\n")
        f.write("  temperature "+str(walltemp)+"\n")
        f.write("  stratum "+str(stratum)+"\n")
        f.write("  outer 0 1\n")
        if clockwise:
            f.write("  wall "+str(wallid+1)+" "+\
                str(wallnodes[0].id)+" "+\
                str(wallnodes[0].id)+"\n")
            f.write("  wall "+str(wallid+1)+" "+\
                str(wallnodes[-1].id)+" "+\
                str(wallnodes[-1].id)+"\n")
        else:
            f.write("  wall "+str(wallid+1)+" "+\
                str(wallnodes[0].id)+" "+\
                str(wallnodes[0].id)+"\n")
            f.write("  wall "+str(wallid+1)+" "+\
                str(wallnodes[1].id)+" "+\
                str(wallnodes[1].id)+"\n")
        if debug:
            f.write("  print_polygon poly.out1.dat\n")
            f.write("  clear_polygon\n")
        else:
            f.write("  triangulate_polygon\n")
        f.write("\n")
        #f.write("new_zone solid\n")
        f.write("new_polygon\n")
        f.write("  material "+material+"\n")
        f.write("  recyc_coef "+str(recyc)+"\n")
        f.write("  temperature "+str(walltemp)+"\n")
        f.write("  stratum "+str(stratum)+"\n")
        f.write("  outer 1 2 3 4\n")
        if clockwise:
            for node in wallnodes[::-1]:
                f.write("  wall "+str(wallid+1)+" "+\
                    str(node.id)+" "+\
                    str(node.id)+"\n")
        else:
            for node in wallnodes[1:]:
                f.write("  wall "+str(wallid+1)+" "+\
                    str(node.id)+" "+\
                    str(node.id)+"\n")
        if debug:
            f.write("  print_polygon poly.out2.dat\n")
            f.write("  clear_polygon\n")
        else:
            f.write("  triangulate_polygon\n")
        f.write("\n")


    # Writes the polygon to file f
    # If debug, include lines that output polygons to poly.X.dat files
    def write_plasma_polygon_dg2d(self,f,stratum=None,wallid=None,commonzone=False,minarea=-1.0,debug=False,newzone=True):
        if not wallid:
            wallnum = self.id+1 
        if not stratum:
            stratum = self.id+1

        if newzone:
            f.write("new_zone plasma\n")
        f.write("new_polygon\n")
        f.write("  stratum "+str(stratum)+"\n")
        for vertex in self.vertices:
            if not vertex.wall_id:
                f.write("  wall "+str(wallid)+" "+str(vertex.id)+" "+str(vertex.id)+"\n")
            else:
                f.write("  wall "+str(vertex.wall_id)+" "+str(vertex.id)+" "+str(vertex.id)+"\n")

        if debug:
            f.write("  print_polygon poly."+str(self.id)+".dat\n")
            f.write("  clear_polygon\n")
        elif commonzone:
            f.write("  triangulate_polygon\n")
        else:
            f.write("  triangulate_to_zones\n")
        if minarea > 0.0:
            f.write("  triangle_area "+str(minarea)+"\n")

        f.write("\n")

    def plotpolygon(self,hold=False):
        import matplotlib.pyplot as plt
        R = []
        Z = []
        for vertex in self.vertices:
            R.append(vertex.coords[0])
            Z.append(vertex.coords[1])

        #plt.clf()
        plt.plot(R,Z,"+-")
        #plt.show()

    def plot_polygons(polys):
        import matplotlib.pyplot as plt

        plt.clf()
        for poly in polys:
            R = []
            Z = []
            for vertex in poly.vertices:
                R.append(vertex.coords[0])
                Z.append(vertex.coords[1])
            plt.plot(R,Z,"+-")
        plt.show()



    def plot_polygons(polys):
        import matplotlib.pyplot as plt

        plt.clf()
        for poly in polys:
            R = []
            Z = []
            for vertex in poly.vertices:
                R.append(vertex.coords[0])
                Z.append(vertex.coords[1])
            plt.plot(R,Z,"+-")
        plt.show()
    
    def add_wall_segment(self,wall,begin_idx,end_idx,backward=False):
        if backward:
            begin=begin_idx
            end=end_idx-1
            step=-1
        else:
            begin=begin_idx
            end=end_idx+1
            step=1
        for vertex in wall.vertices[begin:end:step]:
            self.add_vertex(vertex)
 
    def add_whole_surface(self,surf,backward=False):
        if backward:
            begin=-1
            end=None
            step=-1
        else:
            begin=0
            end=None
            step=1
        for vertex in surf.vertices[begin:end:step]:
            self.add_vertex(vertex)
            

# A surface is also an ordered set of vertices, but can be open or closed
# The vertices that make up various surfaces are combined to make a polygon
class Surface:
    numSurfaces = 0
    def __init__(self,id_in):
        self.vertices = []
        Surface.numSurfaces +=1
        self.id = Surface.numSurfaces
        self.closed = True

    def make_open(self):
        self.closed = False
    def make_closed(self):
        self.closed = True

    # Find the N vertices on surface that are closest to given vertex
    def get_N_closest_vertices(self,N,vertex_in):
        surf_use = copy.deepcopy(self)
        closest_idxs = []
        for i in range(0,N):
            first = True
            for iv in range(0,len(self.vertices)):
                distance_sq = (surf_use.vertices[iv].coords[0]-vertex_in.coords[0])**2 + \
                        (surf_use.vertices[iv].coords[1]-vertex_in.coords[1])**2 
                if first:
                    first=False
                    closest_distance_sq= distance_sq
                    closest_vertex_idx = iv
                    closest_vertex = self.vertices[iv]
                elif distance_sq < closest_distance_sq:
                    closest_distance_sq= distance_sq
                    closest_vertex_idx = iv
                    closest_vertex = self.vertices[iv]
            closest_idxs.append(closest_vertex_idx)
            surf_use.vertices[closest_vertex_idx].coords = [np.nan]*2
        return closest_idxs


    def add_vertex(self,vertex):
        self.vertices.append(vertex)

    # Take the given index, and add it the surface at the appropriate point
    # (as determined by the two closest vertices on the surface)
    def insert_vertex_into_surface(self,vertex_in):
        closest_idxs = self.get_N_closest_vertices(2,vertex_in)

        if not abs(closest_idxs[1] - closest_idxs[0]) == 1:
            print("Error: could not find two adjacent indices in which to insert new point.")
            sys.exit(1)

        self.vertices.insert(max(closest_idxs),vertex_in)

        return max(closest_idxs)

    def clear_numSurface():
        Surface.numSurfaces=0

    # Return two polygons defined by two closed surfaces.
    def genpolys_from_two_closed_surfs(inner,outer):
        poly1 = Polygon(increment=False)
        poly1.add_vertex(outer.vertices[0])
        poly1.add_vertex(outer.vertices[1])
        poly1.add_vertex(inner.vertices[1])
        poly1.add_vertex(inner.vertices[0])
        poly1.add_vertex(outer.vertices[0])

        poly2 = Polygon(increment=False)
        for vertex in inner.vertices[1:]:
            poly2.add_vertex(vertex)
        poly2.add_vertex(inner.vertices[0])
        poly2.add_vertex(outer.vertices[0])
        for vertex in outer.vertices[-1:0:-1]:
            poly2.add_vertex(vertex)
        poly2.add_vertex(inner.vertices[1])

        return poly1, poly2
            
    # Here we wish to include the whole surface and the wall between where it intersects
    def genpoly_from_rightwall_and_surface(wall,surface):

        poly = Polygon(increment=False)
        poly.add_whole_surface(surface,backward=True)

        wallidx_intersect_upper = poly.get_next_vertex_extrapolated_to_wall(wall)
        dummy = Polygon(increment=False)
        dummy.add_whole_surface(surface)
        wallidx_intersect_lower = dummy.get_next_vertex_extrapolated_to_wall(wall)

        poly.add_wall_segment(wall,wallidx_intersect_upper,wallidx_intersect_lower,backward=True)
        
        poly.add_vertex(surface.vertices[-1])

        return poly
    
    def genpoly_from_two_open_surfs(inner,outer,wall):

        poly = Polygon(increment=False)
        poly.add_whole_surface(outer)

        wallidx_intersect_br = poly.get_next_vertex_extrapolated_to_wall(wall)
        dummy = Polygon(increment=False)
        dummy.add_whole_surface(inner)
        wallidx_intersect_bl = dummy.get_next_vertex_extrapolated_to_wall(wall)

        poly.add_wall_segment(wall,wallidx_intersect_br,wallidx_intersect_bl,backward=True)

        poly.add_whole_surface(inner,backward=True)
        wallidx_intersect_ul = poly.get_next_vertex_extrapolated_to_wall(wall)
        dummy = Polygon(increment=False)
        dummy.add_whole_surface(outer,backward=True)
        wallidx_intersect_ur = dummy.get_next_vertex_extrapolated_to_wall(wall)

        poly.add_wall_segment(wall,wallidx_intersect_ul,wallidx_intersect_ur,backward=True)
       
        poly.add_vertex(outer.vertices[0])

        return poly



    # Creates the outer polygon from the solid wall Surface, writes it to file f
    # If debug, include lines that output polygons to poly.X.dat files
    def write_solid_polygon_dg2d(self,stratum,f,material,recyc,walltemp=300.0,debug=False,clockwise=False):
        f.write("new_zone solid\n")
        f.write("new_polygon\n")
        f.write("  stratum "+str(stratum)+"\n")
        f.write("  material "+material+"\n")
        f.write("  recyc_coef "+str(recyc)+"\n")
        f.write("  temperature "+str(walltemp)+"\n")
        f.write("  wall "+str(self.id)+" 0 1 \n ")
        f.write("  outer 1 0 \n")
        f.write("  outer 0 1 \n")
        f.write("  wall "+str(self.id)+" 0 0 \n ")
        if debug:
            f.write("  print_polygon poly."+str(stratum)+".dat\n")
            f.write("  clear_polygon\n")
        else:
            f.write("  triangulate_polygon\n")
        f.write("\n")
 
        f.write("new_zone solid\n")
        f.write("new_polygon\n")
        f.write("  stratum "+str(stratum+1)+"\n")
        f.write("  material "+material+"\n")
        f.write("  recyc_coef "+str(recyc)+"\n")
        f.write("  temperature "+str(walltemp)+"\n")
        f.write("  wall "+str(self.id)+" 1 * \n ")
        f.write("  wall "+str(self.id)+" 0 0 \n ")
        f.write("  outer 1 2 3 4\n")
        f.write("  wall "+str(self.id)+" 1 1 \n ")
        if debug:
            f.write("  print_polygon poly."+str(stratum+1)+".dat\n")
            f.write("  clear_polygon\n")
        else:
            f.write("  triangulate_polygon\n")
        f.write("\n")

    def write_solid_polygon_with_exit(self,stratum,f,exitnodes,material,recyc,walltemp=300.0,debug=False):
        f.write("new_zone exit\n")
        f.write("new_polygon\n")
        f.write("  stratum "+str(stratum)+"\n")
        f.write("  wall "+str(self.id)+" "+str(exitnodes[0])+" "+str(exitnodes[1])+"\n")
        f.write("  outer 2 3 \n")
        if debug:
            f.write("  print_polygon poly."+str(stratum)+".dat\n")
            f.write("  clear_polygon\n")
        else:
            f.write("  triangulate_polygon\n")
        f.write("\n")
 
        f.write("new_zone solid\n")
        f.write("new_polygon\n")
        f.write("  stratum "+str(stratum+1)+"\n")
        f.write("  material "+material+"\n")
        f.write("  recyc_coef "+str(recyc)+"\n")
        f.write("  temperature "+str(walltemp)+"\n")
        f.write("  wall "+str(self.id)+" "+str(exitnodes[1])+" * \n")
        f.write("  wall "+str(self.id)+" 0 "+str(exitnodes[0])+"\n ")
        f.write("  outer 3\n")
        f.write("  outer 0 1 2\n")
        if debug:
            f.write("  print_polygon poly."+str(stratum+1)+".dat\n")
            f.write("  clear_polygon\n")
        else:
            f.write("  triangulate_polygon\n")
        f.write("\n")
        
    def plot_surfaces(surfs):
        for surf in surfs:
            R = []
            Z = []
            for vertex in surf.vertices:
                R.append(vertex.coords[0])
                Z.append(vertex.coords[1])
            plt.plot(R,Z,"+-")
            plt.plot(R[0],Z[0],"o")
        plt.show()

class Vertex:
    def __init__(self,id_in,R,Z):
        self.coords = [R,Z]
        self.id = id_in 
        self.wall = False
        self.wall_id = None

    # Nodes are the same the coordinates are equal
    def __eq__(self,other):
        if not isinstance(other,Vertex):
            return NotImplemented
        return (self.coords[0] == other.coords[0]) and (self.coords[1] == other.coords[1])

    def __ne__(self,other):
        if not isinstance(other,Vertex):
            return NotImplemented
        return not ( (self.coords[0] == other.coords[0]) and (self.coords[1] == other.coords[1]) )

def infer_wall_nodes(internal_triangles, external_triangles):
    wallnodes = []

    for tri_ext in external_triangles:
        for ext_node in tri_ext.vertices:
                for tri_int in internal_triangles:
                    if ext_node in tri_int.vertices and not ext_node in wallnodes:
                        wallnodes.append(ext_node)
                        wallnodes[-1].id = ext_node.id
                        ext_node.wall = True

    return wallnodes

def purge_invalid_nodes(allnodes,valid_tris):
    valid_nodes = []
    for node in allnodes:
        valid = False
        for tri in valid_tris:
            if node in tri.vertices:
                valid = True
        if valid:
            valid_nodes.append(node)
    return valid_nodes

def find_next_wall_node(current_node,prev_node,wallnodes,walltriangles,first):

    # Collect triangles that share current_node
    adjacent_wall_triangles = []
    nwalltriangles = np.shape(walltriangles)[0]
    for tri in walltriangles:
        if current_node in tri.vertices:
            adjacent_wall_triangles.append(tri)

    n_adjacent_triangles = len(adjacent_wall_triangles)

#    print("current_node = %d"%current_node.id)

    next_node = -1
    # Loop through the adjacent wall triangles that share the current node
    for tri in adjacent_wall_triangles:
#        print(tri.id)
        # Create list of adjacent triangles that excludes the one under consideration
        other_adjacent_triangles = copy.deepcopy(adjacent_wall_triangles)
        other_adjacent_triangles.remove(tri)
        
#        other_adjacent_triangle_vertices = []
#        other_adjacent_triangle_vertices = []
#        for other_triangle in other_adjacent_triangles:
#            other_adjacent_triangle_vertices.append(other_triangle.vertices[0])
#            other_adjacent_triangle_vertices.append(other_triangle.vertices[1])
#            other_adjacent_triangle_vertices.append(other_triangle.vertices[2])


        # Which vertex of this triangle is the current_node?
        vertex_idx = tri.vertices.index(current_node)

        # Line segments of this triangle that share this vertex
        segments = []
        segments.append( [current_node,tri.vertices[(vertex_idx+1)%3]] )
        segments.append( [current_node,tri.vertices[(vertex_idx+2)%3]] )

        # Loop through segments that share the current node
        for segment in segments:
            # If there are not any other wall triangles that share this segment, we have found a candidate

            segment_shared_with_another_triangle = False
            for othertri in other_adjacent_triangles:
                if segment[1] in othertri.vertices:
                    segment_shared_with_another_triangle = True
                    if not segment[0] in othertri.vertices[:]:
                        sys.exit("Something's very wrong in find_next_wall_node.")
            if (segment[1] in wallnodes) and (not segment_shared_with_another_triangle):
                if first:
                    # Ensure we start by going counterclockwise from the low field side
                    if segment[1].coords[1] < current_node.coords[1]:
                        next_node=segment[1]
                elif (segment[1] != prev_node):
                    if (next_node != -1):
                        sys.exit("Found multiple candidates for next_node. Logic of code fails.")
                    next_node = segment[1]

    if next_node == -1:
        sys.exit("Could not find a candidate next_node.")

    return next_node

# WallVertex is a special case of Vertex, where the vertex ID is an array
# that specifies the Surface ID and vertex ID within that surface. 
class WallVertex(Vertex):
    def __init__(self,wallid,vertexid,R,Z):
        self.id = [wallid,vertexid]
        super().__init__(self.id,R,Z)



