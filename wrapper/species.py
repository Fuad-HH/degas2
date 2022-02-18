# This is a generic species class.
# Each species is made up of elementary particles and may have internal energy states, represented by a set of integers
# Species may be bundled by collisional radiative modelling.

# Ought to parse the original species.in files as well as the resulting .nc files. 

import sys
import element
import constants
import scipy.constants 
import netCDF4 as nc

class Species:
    def __init__(self,symbol,name):
        self.constituents = []
        self.mass = 0.0
        self.Z = 0.0
        self.symbol = symbol
        self.name = name
        self.id = None
        self.is_photon = False
        self.generic = None
        if symbol == "0" or name == "geometry":
            self.geometry = True
        else:
            self.geometry = False
        # Internal energy states to come

    def add_element(self,constituent):
        self.constituents.append(constitutent)
        self.mass += constituent.mass
        self.Z += consitituent.Z
        self.mass += consitituent.mass

def populate_global_list(ncfilename):
    global global_list
    global_list =[]

    data = nc.Dataset(ncfilename)

    for i in range(0,data["sp_num"][0]):
        name = str(nc.chartostring(data["species_name"][i])).strip()
        symbol = str(nc.chartostring(data["species_sy"][i])).strip()
        mass = data["species_m"][i]
        Z = data["species_z"][i]
        sp = Species(symbol,name)

        Ncomp = data["species_ncomp"][i]
        for j in range(0,Ncomp):
            el_id = data["species_el"][i][j]
            el = element.lookup_id(el_id)
            for k in range(0,abs(data["species_count"][i][j])):
                sp.add_element(el)
            sp.add_element(el)
        sp.mass = mass
        sp.id = i+1
        sp.generic = data["species_generic"][i]

        global_list.append(sp)

def lookup(symbol,sp_list = None):
    if not sp_list:
        sp_list = global_list
    found = None
    for s in sp_list:
        if s.symbol == symbol:
            found = s
    if not found:
        sys.exit("ERROR: Could not find species symbol "+symbold+" in global list.")
    return found





