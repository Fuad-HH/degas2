from polygon import *

class Source:
    def __init__(self,nflights,stype,species,rootspecies=None,specify_flux=True,sourcefile="sourcefile",pufftemp=None,strength=None,stratum=None,segment=None,puffexp=None):
        self.nflights = nflights
        self.type = stype
        self.species = species
        if not rootspecies:
            self.rootspecies = self.species
        else:
            self.rootspecies = rootspecies
        if specify_flux == True:
            self.specify_units = "specify_flux"
        else:
            self.specify_units = "specify_current"
#        if stype == "puff":
        if pufftemp:
            self.pufftemp = pufftemp
        else:
            self.pufftemp=None
        if puffexp != None:
            self.puffexp = puffexp
        else:
            self.puffexp = None

        if strength:
            self.strength=strength
            self.stratum=stratum
            self.segment=segment
            self.sourcefile=None
        else:
            self.sourcefile = sourcefile
            self.strength=None
            

def write_db_input(source_groups,plasmafile="plasmafile.txt",filename="db.in"):
    Nsource=len(source_groups)
    f = open(filename,"w") 
    f.write("plasma_file "+plasmafile+"\n")
    for i in range(0,Nsource):
        f.write("new_source_group\n")
        f.write("  source_type "+source_groups[i].type+"\n")
        f.write("  source_geom surface\n")
        f.write("  source_species "+source_groups[i].species+"\n")
        f.write("  source_root_sp "+source_groups[i].rootspecies+"\n")
        f.write("  "+source_groups[i].specify_units+"\n")
        if not source_groups[i].strength:
            f.write("  source_file "+source_groups[i].sourcefile+" row\n")
        else:
            f.write("  source_stratum "+str(source_groups[i].stratum)+"\n")
            f.write("  source_segment "+str(source_groups[i].segment)+"\n")
            f.write("  source_strength "+str(source_groups[i].strength)+"\n")

        if source_groups[i].pufftemp != None:
            f.write("  source_puff_temp "+str(source_groups[i].pufftemp)+"\n")
        if source_groups[i].puffexp != None:
            f.write("  source_puff_exponent "+str(source_groups[i].puffexp)+"\n")
        f.write("  source_nflights "+str(source_groups[i].nflights)+"\n")
        f.write("end_source_group\n")
    f.close()


