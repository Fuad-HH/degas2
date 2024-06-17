import matplotlib.tri as mtri
import numpy as np
from tqdm import tqdm
import sys
from multiprocessing import Pool

# Generate a geometry.nc file for a large mesh

# Gets triangulation object from triangle files .node and .ele. Start here.
def get_triangulation(trifile_base):
    f=open(trifile_base+".node","r")
    nnode=int(f.readline().split()[0])
    rz=np.zeros([nnode,2])
    for i in range(0,nnode):
        line=f.readline().split()
        rz[i,0]=float(line[1])
        rz[i,1]=float(line[2])
    f.close()

    f=open(trifile_base+".ele","r")
    ntri=int(f.readline().split()[0])
    conn=np.zeros([ntri,3],dtype=int)
    for i in range(0,ntri):
        line=f.readline().split()
        conn[i,0]=int(line[1])-1
        conn[i,1]=int(line[2])-1
        conn[i,2]=int(line[3])-1
    f.close()

    triang = mtri.Triangulation(rz[:,0],rz[:,1],conn)
    return triang, rz, conn

# Generate an equation for a cone for every pair of points x1 and x2 (size [Nsurfs,2]).
# Returns [Nsurfs,10]  coefficients
# Generate boundaries array
# Generate boundaries array
# Vectorized
# x
def gen_cones(x0,x1):
   Nsurfs = np.shape(x1)[0] 
   coeffs = np.zeros([Nsurfs,10])

   eps = 1.0e-8
   eps_angle = np.sqrt(2.0*1.0e-10)

   cylcond = (np.abs(x1[:,0]-x0[:,0]) < eps_angle*np.abs(x1[:,1]-x0[:,1])) 
   cylcond = np.logical_or(cylcond, (np.abs(x1[:,0]-x0[:,0]) < eps))
   print(sum(cylcond))

   if any (np.where(cylcond, 1.0, np.abs(x1[:,0]-x0[:,0])) < eps):
       print("ERROR: unexpected zero denominator")
   m = np.divide((x1[:,1]-x0[:,1]),(x1[:,0]-x0[:,0]),out=np.ones_like(x1[:,0]),where=np.logical_not(cylcond))
   m2 = m*m
   b = np.where(cylcond, 0.0, x1[:,1] - m*x1[:,0])

   c0 = np.where( cylcond , -x0[:,0]**2, -b**2)
    

   coeffs[:,0] = c0
   coeffs[:,3] = 2.0*b
   coeffs[:,4] = m2
   coeffs[:,5] = m2
   coeffs[:,6] = np.where(cylcond,np.zeros(Nsurfs),np.ones(Nsurfs))

   return coeffs

if (len(sys.argv) > 1):
    tribase = str(sys.argv[1])

    triang,rz,conn=get_triangulation(tribase)

    # For every pair of connected points, there's only one edge. A good proxy for surfaces.
    edges = triang.edges
    edgelist = edges.tolist()
    Nedge = len(edges[:,0])
    rzedges1 = rz[edges[:,0],:]
    rzedges2 = rz[edges[:,1],:]
    coeffs = gen_cones(rzedges1,rzedges2)
    # We now have surface_coeffs array!

    # Now, map to triangles
    # Brute force: search for point pair in edges array
    Ntri = len(conn[:,0])
#    edgemap = np.zeros([Ntri,3],dtype=int)

#    def populate_edge_map(itri):
#        for iedge in range(0,3):
#            idx1 = iedge
#            idx2 = (iedge+1)%3
#            # Every pair in edges array has indices in decreasing order
#            edgemap[itri,iedge] = edgelist.index([max(conn[itri,idx1],conn[itri,idx2]),min(conn[itri,idx1],conn[itri,idx2])])
#
    print("Getting triangle edges...")
#    pool = Pool()
#    pool.imap(populate_edge_map,tqdm(range(0,Ntri)))
#    for itri in range(0,Ntri):
#        populate_edge_map(itri)
#    for itri in tqdm(range(0,Ntri)):
#        populate_edge_map(itri)
#    for itri in tqdm(pool.imap(populate_edge_map,range(0,Ntri))):
#        populate_edge_map(itri)

    def populate_edge_map(iedge):
        candidates = np.argwhere(conn == edges[iedge,0])[:,0]
        new_candidates = np.argwhere(conn[candidates,:] == edges[iedge,1])[:,0]
#        print(iedge, candidates, new_candidates)
        tri_idxs = candidates[new_candidates]
        if len(tri_idxs) > 2:
            print("ERROR: more than 2 triangles adjacent to an edge; doesn't make sense")
        if len(tri_idxs) == 0:
            print("ERROR: could not find a triangle with this edge")
        for itri in range(0,len(tri_idxs)):
            if (edgemap[itri,0] < 0):
                edgemap[itri,0] = iedge
            elif (edgemap[itri,1] < 0):
                edgemap[itri,1] = iedge
            elif (edgemap[itri,2] < 0):
                edgemap[itri,2] = iedge

#    edgemap = -1.0*np.ones([Nedge,3],dtype=int)
#    pool = Pool()
#    pool.imap(populate_edge_map,tqdm(range(0,Nedge)))

#    for iedge in tqdm(range(0,Nedge)):
#        populate_edge_map(iedge)
#    np.save("edgemap.npz",edgemap)
    edgemap = np.load("edgemap.npy")
    edgemap = np.array(edgemap,dtype=int)

    coeffs_all = np.zeros([Nedge+4+2*Ntri,10])
    coeffs_all[4:Nedge+4,:] = coeffs
    
    # Universal cell is first 4 surfaces
    # Next Nedge surfaces are the triangle edges
    # Next 2*NTri surfaces are cut surfaces

    # Every cell gets two cut surfaces: at minimum and maximum z
    boundaries = np.zeros(4+Nedge+2*Ntri,dtype=int)
    cells = np.zeros([Ntri,4],dtype=int)
    print("Building surface linking...")
    for i in tqdm(range(0,Ntri)):
        zmin=np.min(rz[edgemap[i,:],1])
        zmax=np.max(rz[edgemap[i,:],1])
        cells[i,0] = 4+i*5
        cells[i,1] = 5
        cells[i,2] = 3
        cells[i,3] = -1
        coeffs_all[2*i+4+Nedge,:] = [zmin,0,0,1.0,0,0,0,0,0,0]
        coeffs_all[2*i+1+4+Nedge,:] = [zmax,0,0,1.0,0,0,0,0,0,0]
        # TODO: fix sign on first three elements here:
        boundaries[4+i*5:4+(i+1)*5] = [4+edgemap[i,0],4+edgemap[i,1],4+edgemap[i,2],2*i+4+Nedge,-(2*i+1+4+Nedge) ]




