#the syntax of this file is :
#keyword [args] where keyword and args can be --
# keyword	      arguments
# degasfile : 	     1 filename for degas input
#mindensity :        density of electrons (m-3) as cutoff for selecting zones.
#minx:               minimum x value (cm) as cutoff for gridx
#minz: 		     minimum z value (cm) as cutoff for gridz
#grid                start(vert bound.),stop(vert. bound), start (hor. bound),
#		     stop (hor. bound) [all indices in grid array]
#new_zone	     plasma or solid or vacuum
#new_polygon	     nil
#define_polygon      nil
#edge 		     start(vert bound.),stop(vert. bound), start (hor. bound),
#		     stop (hor. bound) 	[all indices in grid array]
#		     1 pair of indices must be identical for edge.
#wall		     wall number, starting point index,stopping point index
#uedgefile 		specify a uedge input file
#mesh rmin rmax zmin zmax [ymin ymax]	generate geometry based on uedge data.
#lines with a "#" in col 1 are comments, empty lines are ignored.
#all inputs below this line

symmetry plane
uedgefile ../examples/Eirene_bench_difft_physics/uedata_rs_recom.u
null_type 1
material mo
mesh -0.015 0.045 -0.01 1.1 0.0 1.0
end

