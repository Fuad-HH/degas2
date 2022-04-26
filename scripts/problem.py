import species 
#import PMI as pm
#import material as mat
#import reaction as rc
import utils


class Problem:
    def __init__(self):
        self.description = "No description"
        self.test_species = []
        self.background_species = []
        self.reactions = []
        self.materials = []
        self.pmi = []

    def add_test_species(self,test):
        self.test_species.append(test)

    def add_background_species(self,test):
        self.background_species.append(test)

    def add_reaction(self,reaction):
        self.reactions.append(reaction)

    def add_PMI(self,pmi):
        self.pmi.append(pmi)

    def add_material(self,material):
        self.materials.append(material)

    # Reads a degas2 problem_infile and stores its contents to class instance
    def parse_input_file(self,filename):
        headers = ["TEST","BACKGROUND","REACTION","MATERIALS","PMI"]
        d = utils.parse_file_with_headers(filename,headers)
        for name in d["TEST"]:
            self.add_test_species( species.lookup(name) )
        for name in d["BACKGROUND"]:
            self.add_background_species( species.lookup(name) )
        for name in d["REACTION"]:
            self.add_reaction(reaction.lookup(name) )
        for name in d["MATERIALS"]:
            self.add_material(material.lookup(name) )
        for name in d["PMI"]:
            self.add_PMI(pmi.lookup(name) )

    # Generates a degas2 problem_infile from class instance
    def generate_input_file(self,filename):
        d={}
        d["TEST"] = self.test_species
        d["BACKGROUND"] = self.background_species
        d["REACTION"] = self.reactions
        d["MATERIALS"] = self.materials
        d["PMI"] = self.pmi
        utils.write_file_with_headers(filename,d,"$ $")
   
def defineProblem(testSps,backSps,reactions,mats,pmis):
    p = Problem()
    for t in testSps:
        p.add_test_species(t)
    for b in backSps:
        p.add_background_species(b)
    for r in reactions:
        p.add_reaction(r)
    for m in mats:
        p.add_material(m)
    for m in pmis:
        p.add_PMI(m)
    return p

def generateProblemInput(testSps,backSps,reactions,mats,pmis):
    p = defineProblem(testSps,backSps,reactions,mats,pmis)
    p.generate_input_file("problem.in")
    return p

def genStdProblem(label):
    if label == "C-H":
        generateProblemInput(["0","H"],["e","H+"],["hionize5","hh_chargex"],["C"],["hdesorbc_xgc","hreflc"])
    if label == "C":
        generateProblemInput(["0","H","H2","H2+"],["e","H+"],["hionize5","hh_chargex","h2dis","h2ion","h2dision","h2pdision","h2pdis","h2pdisrec"],["C"],["hdesorbc","h2desorbc","hreflc"])
    if label == "Li":
        generateProblemInput(["0","H"],["e","H+"],["hionize5","hh_chargex"],["Li"],["H_refl_svftrim_Li","hdesorbLi"])
    if label == "Li_reflOnly":
        generateProblemInput(["0","H"],["e","H+"],["hionize5","hh_chargex"],["Li"],["H_refl_svftrim_Li"])
    if label == "LiOH":
        generateProblemInput(["0","H","H2","H2+"],["e","H+"],["hionize5","hh_chargex",\
                "h2dis","h2dis_n3","h2ion","h2dision","h2pdision","h2pdis"],["LiOH"],\
                ["H_refl_vftrim_LiOH","h_des_maxw_LiOH","h2_des_maxw_LiOH"])

