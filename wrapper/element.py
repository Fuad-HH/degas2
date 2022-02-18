import netCDF4 as nc
import utils

class Element:
    def __init__(self,symbol,name,A,Z):
        self.symbol = symbol
        self.name = name
        self.A = A
        self.Z = Z
        self.mass = A * constants.amu
        self.id = None

def populate_global_list(ncfilename):
    global global_list
    global_list =[]

    data = nc.Dataset(ncfilename)

    for i in range(0,data["element_name"].shape(0)):
        name = str(nc.chartostring(data["element_name"][i])).strip()
        symbol = str(nc.chartostring(data["element_sy"][i])).strip()
        A = data["element_m"][i]
        Z = data["element_z"][i]
        el = Element(symbol,name,A,Z)
        el.id = i+1
        global_list.append(el)

def lookup_id(id):
    found = None
    for el in global_list:
        if id == el.id:
            found = el
    if not found:
        sys.exit("Could not find element id %d"%id)
    return found


