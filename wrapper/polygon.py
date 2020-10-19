import numpy as np
import copy
import sys

# A polygon is an ordered set of vertices, connected by segments which close in on itself.
class Polygon:
    numPolygons = 0 # Polygons start counting from 1

    def __init__(self,increment=True):
        self.vertices = []
        if increment:
            Polygon.numPolygons += 1
        self.id = Polygon.numPolygons

    def add_vertex(self,vertex):
        self.vertices.append(vertex)

    def clear_numPolygon():
        Polygon.numPolygons = 0

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

    # Writes the polygon to file f
    # If debug, include lines that output polygons to poly.X.dat files
    def write_plasma_polygon_dg2d(self,f,debug=False):
        f.write("new_zone plasma\n")
        f.write("new_polygon\n")
        f.write("  stratum "+str(self.id)+"\n")
        for vertex in self.vertices:
            f.write("  wall "+str(vertex.id[0]+1)+" "+str(vertex.id[1])+" "+str(vertex.id[1])+"\n")

        if debug:
            f.write("  print_polygon poly."+str(self.id)+".dat\n")
            f.write("  clear_polygon\n")
        else:
            f.write("  triangulate_to_zones\n")
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

        print(closest_idxs)

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
    def write_solid_polygon_dg2d(self,stratum,f,material,recyc,debug=False):
        f.write("new_zone solid\n")
        f.write("new_polygon\n")
        f.write("  stratum "+str(stratum)+"\n")
        f.write("  material "+material+"\n")
        f.write("  recyc_coef "+str(recyc)+"\n")
        f.write("  wall "+str(self.id)+" 0 1 \n ")
        f.write("  outer 0 1 \n")
        f.write("  wall "+str(self.id)+" 0 0 \n ")
        if debug:
            f.write("  print_polygon poly."+str(stratum)+".dat\n")
            f.write("  clear_polygon\n")
        else:
            f.write("  triangulate_to_zones\n")
        f.write("\n")
 
        f.write("new_zone solid\n")
        f.write("new_polygon\n")
        f.write("  stratum "+str(stratum+1)+"\n")
        f.write("  material "+material+"\n")
        f.write("  recyc_coef "+str(recyc)+"\n")
        f.write("  wall "+str(self.id)+" 1 * \n ")
        f.write("  wall "+str(self.id)+" 0 0 \n ")
        f.write("  outer 1 2 3 4\n")
        f.write("  wall "+str(self.id)+" 1 1 \n ")
        if debug:
            f.write("  print_polygon poly."+str(stratum+1)+".dat\n")
            f.write("  clear_polygon\n")
        else:
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
