import numpy as np
import copy

# A polygon is an ordered set of vertices, connected by segments which close in on itself.
class Polygon:
    numPolygons = 0 # Polygons start counting from 1

    def __init__(self,increment=True):
        self.vertices = []
        if increment:
            Polygon.numPolygons += 1
        self.id = Polygon.numPolygons

    def addvertex(self,vertex):
        self.vertices.append(vertex)

    def clear_numPolygon():
        Polygon.numPolygons = 0

    # Linearly extrapolate the last two vertices defined for this polygon
    # and find the point on the specified surface which is closest to said line.
    # Returns index of said point
    def get_next_vertex_extrapolated_to_wall(self,wall):
        point1 = self.vertices[-1]
        point2 = self.vertices[-2]

        dir = [int( (point2[0]-point1[0])/abs(point2[0]-point1[0])),
                int((point2[1]-point1[1])/abs(point2[1]-point1[1])) ]

        first = True
        idx = 0
        for vertex in wall.vertices:
            # Only check points that are on the correct half-plane according to 
            # the directionality of the last two points
            if ((dir[0]*vertex.coords[0]) > point1[0]) and ((dir[1]*vertex.coords[1]) > point1[1]):
                current_distance_sq = ( (point2[1]-point1[1])*vertex.coords[0] 
                    - (point2[0]-point1[0])*vertex.coords[1] 
                    + point2[0]*point1[1] - point2[1]*point1[0])**2 \
                    / ( (point2[1]-point1[1])**2 + (point2[0]-point1[0])**2 )
                    
                if first:
                    closest_vertex=vertex
                    closest_distance_sq = current_distance_sq
                    first = False
                elif current_distance_sq < cloest_distance_sq:
                        closest_vertex = vertex
                        closest_distance_sq = current_distance_sq
            idx +=1

        return idx-1

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
#                        sys.exit(0)
#                    idx = self.add_next_vertex_extrapolated_to_wall(surfaces[isurf])

    # Writes the polygon to file f
    # If debug, include lines that output polygons to poly.X.dat files
    def write_plasma_polygon_dg2d(self,f,debug=False):
        f.write("new_zone plasma\n")
        f.write("new_polygon\n")
        f.write("  stratum "+str(self.id)+"\n")
        for vertex in self.vertices:
            f.write("  wall "+str(vertex.id[0])+" "+str(vertex.id[1])+" "+str(vertex.id[1])+"\n")

        if debug:
            f.write("  print_polygon poly."+str(self.id)+".dat\n")
        f.write("  triangulate_to_zones\n")
        f.write("\n")


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
        first = True
        surf_use = copy.deepcopy(self)
        closest_idxs = []
        for i in range(0,N):
            for iv in len(self.vertices):
                distance_sq = (self.vertices[iv].coords[0]-vertex_in[0])**2 + \
                        (self.vertices[iv].coords[1]-vertex_in[1])**2 
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
            surf_use.vertices = surf_use.vertices.remove[closest_vertex]
        return closest_idxs


    def addvertex(self,vertex):
        self.vertices.append(vertex)

    # Take the given index, and add it the surface at the appropriate point
    # (as determined by the two closest vertices on the surface)
    def insert_vertex_into_surface(self,vertex_in):
        closest_idxs = self.get_N_closest_vertices(2,vertex_in)

        if closest_idxs[1] > closest_idxs[0]:
            idx_use = closest_idxs[1]
        else:
            idx_use = closest_idxs[0]
            self.vertices.insert(closest_idxs[0],vertex_in)
        self.vertices.insert(idx_use,vertex_in)

        return idx_use

    def clear_numSurface():
        Surface.numSurfaces=0

    # Creates the outer polygon from the solid wall Surface, writes it to file f
    # If debug, include lines that output polygons to poly.X.dat files
    def write_solid_polygon_dg2d(self,poly_idx,f,material,recyc,debug=False):
        f.write("new_zone solid\n")
        f.write("new_polygon\n")
        f.write("  stratum "+str(poly_idx)+"\n")
        f.write("  material "+material+"\n")
        f.write("  recyc_coef "+str(recyc)+"\n")
        for vertex in self.vertices:
            f.write("  wall "+str(vertex.id[0])+" "+str(vertex.id[1])+" "+str(vertex.id[1])+"\n")
        f.write("  wall "+str(self.id)+" "+str(self.vertices[0].id[1])+" "+str(self.vertices[0].id[1])+"\n")
        f.write("  outer 0 1 2 3 4\n")
        f.write("  wall "+str(self.id)+" "+str(self.vertices[0].id[1])+" "+str(self.vertices[0].id[1])+"\n")

        if debug:
            f.write("  print_polygon poly."+str(self.id)+".dat\n")
            f.write("  clear_polygon\n")
        f.write("  triangulate_to_zones\n")
        f.write("\n")
        


class Vertex:
    def __init__(self,id_in,R,Z):
        self.coords = [R,Z]
        self.id = id_in 

# WallVertex is a special case of Vertex, where the vertex ID is an array
# that specifies the Surface ID and vertex ID within that surface. 
class WallVertex(Vertex):
    def __init__(self,wallid,vertexid,R,Z):
        self.id = [wallid,vertexid]
        super().__init__(self.id,R,Z)
