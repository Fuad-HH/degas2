import numpy as np
import os.path

class ehr_data():
    #
    # Note that this method needs to "_" at the beginning and end.
    #
    def __init__(self,file_path):
        self.file_path=file_path
        self.ntemp=60
        self.nden=15
        if os.path.exists(self.file_path):
#            print(self.file_path)
            self.data_dict = self.read_file(self.file_path)
        else:
            raise ValueError('No data file found')
    #
    # Note that "self" must appear here in the definition,
    # even though it does not in the call to it above.
    #
    def read_file(self,file_path):
        datafile = open(file_path,'rt')
        #
        # Keep track of the number of sections primarily
        # so we know whether or not were are just starting.
        #
        sections=0
        #
        # The primary data structure is a dictionary with a
        # "key" being the label for the data section and the
        # "value" being the 2-D data.
        #
        all_data={}
        #
        # Loop over every line in the file.
        #
        for line in datafile:
            #
            # This string appears in every data label, originally to
            # simplify searching through the file.
            #
            if '(jt,jn)' in line:
                # Store the data from the previous section
                if (sections > 0):
                    all_data.update({var_label : one_var})
                    this_value=all_data.get(var_label)
                sections+=1
                #
                # Initialize this section.
                #
                jn=0
                var_label=line
                # Note that originally had this initialized only
                # at the top, with the idea being the data would
                # get overwritten.  However, in that case, ALL of
                # the dictionary entries, regardless of the key,
                # were getting overwritten at the same time.
                one_var=np.zeros((self.nden,self.ntemp))
            #
            # Previously had this looking for '  jn =', but then
            # got a file with a single leading space.  Fixed by
            # stripping leading spaces.
            #
            elif line.lstrip().startswith('jn ='):
                #
                # Get ready for the next density value.
                #
                jn+=1
                datalines=0
            elif not line.isspace():
                #
                # Apart from a few blank lines, everything else
                # in the file is data, the scan over temperature
                # index.
                #
                datalines+=1
                #
                # "split" just returns text.  Immediately
                # convert to floats so that the np.array has
                # the desired (float) type.
                #
                linevalues=[float(x) for x in line.split()]
                if (datalines == 1):
                    section=np.array([linevalues])
                else:
                    section=np.append(section,[linevalues])
                    #
                    # This assumes that there a 60 data values
                    # with 6 per line.  At the end, we insert
                    # the "section" into the 2-D array for this
                    # variable.
                    #
                    if (datalines == 10):
                        one_var[jn-1,:]=section
        #
        # This just enters the data for the last variable into
        # the dictionary since we won't be going through the loop
        # over lines any more.
        #
        all_data.update({var_label : one_var})
        datafile.close()
        return all_data

    def get_one_var(self,search_var):
        num_keys=0
        #
        # The main thing to note here is that they actual
        # keys are long and messy.  Can uniquely specify
        # a much shorter string.  So, have to search.  This
        # will catch, crudely, strings that are not unique
        # or not present.
        #
        for entry in self.data_dict.keys():
            if search_var in entry:
                if (num_keys == 0):
                    actual_key=entry
                    num_keys+=1
                    one_var=self.data_dict.get(actual_key)
                else:
                    print(' Duplicat entry')
        if (num_keys == 0):
            one_var=[]
            print(' No entry found')
        return one_var
    
    # These are assumed to be the same for all files.
    # In principle, could extract from the comments.
    def get_Te(self):
        delta_logTe = 0.1
        logTe_min = -1.2
        logTe = logTe_min + delta_logTe*np.arange(self.ntemp)
        Te = 10.**logTe
        return Te

    # Ditto for the density
    def get_ne(self):
        delta_logne = 0.5
        logne_min = 10.
        logne = logne_min + delta_logne*np.arange(self.nden)
        ne = 10.**logne
        return ne
    
    
                        

