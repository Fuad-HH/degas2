import netCDF4 as nc

# TODO
# Returns a dictionary with keys as "mandatory_headers"
def parse_file_with_headers(filename,mandatory_headers):
    f = open(filename,"r")
    lines = f.readlines()
    f.close()

    #def get_header_indices(lines,headers):

    idx = get_header_indices(lines,mandatory_headers)

    d = {}

def write_file_with_headers(filename,d,info=None):
    f = open(filename,"w")
    if info:
        f.write(info+"\n")
    for key in d:
        f.write(key+"\n")
        for obj in d[key]:
            f.write(obj+"\n")
    f.close()


def get_strings_1d(self,s):
    data = []
    for i in range(0,len(self[s])):
         data.append(str(nc.chartostring(self[s])).strip())
    return data


