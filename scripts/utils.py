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

    utils.write_file_with_headers(filename,d,"$ $")

def write_file_with_headers(filename,d,info=None):
    """
    Writes a simple degas2 input file using an input dictionary.
    Currently only works for problemsetup input files

    Args:
        filename: the name of the file to write
        d: dictionary of data where the key is a header for the group. Individual objects within each key are strings which are written line-by-line.
    """

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


