from polygon import *

class Source:
    def __init__(self,nflights,stype,species,rootspecies=None,specify_flux=True,sourcefile="sourcefile",puffparams=[]):
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
        if stype == "puff":
            self.pufftemp = puffparams[0]
        self.sourcefile = sourcefile

def write_db_input(source_groups,plasmafile="plasmafile",filename="db.in"):
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
        f.write("  source_file "+source_groups[i].sourcefile+" row\n")
        if source_groups[i].type == "puff":
            f.write("  source_puff_temp "+str(source_groups[i].pufftemp)+"\n")
        f.write("  source_nflights "+str(source_groups[i].nflights)+"\n")
        f.write("end_source_group\n")
    f.close()


