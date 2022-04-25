# This contains all the information needed for the datasetup executable. These nc files live in the data directory, and rarely change from run to run, unless new data is added.

class degas2_data:
    def __init__(self,datadir):
        self.dir = datadir

        self.elements_infile, self.elementsfile = self.getfiles("elements")
        self.species_infile, self.speciesfile = self.getfiles("species")
        self.reaction_infile, self.reactionfile = self.getfiles("reactions")
        self.materials_infile, self.materialsfile = self.getfiles("materials")
        self.pmi_infile, self.pmifile = self.getfiles("pmi")

    def getfiles(self,filetype):
        infile = self.dir + "/" + filetype + ".input"
        outfile = self.dir + "/" + filetype + ".nc"
        return infile, outfile

    def writefile(self):

    def run(self):


