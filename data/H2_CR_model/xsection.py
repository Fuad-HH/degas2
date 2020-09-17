import numpy as np
import netCDF4
#
# Macro parameters copied in from xsection.hweb and reaction.hweb.
#
unit_string_length = 12
tag_string_length = 40
eval_name_length = 40
table_rank_max = 3
dep_var_max = 20
rc_sy_len = 24

electron_charge = 1.60217733e-19  # from constants.hweb
atomic_mass_unit = 1.6605402e-27  # ditto; in kg
#
# Utility method used to translate Python strings into
# the character arrays expected by netCDF.
#
def nc_string(string,length):
    return netCDF4.stringtoarr(string.ljust(length),length)
#
# This class is a local collection of the Python / NumPy objects
# that are written to or read from a netCDF file in DEGAS 2's
# xsection format used for atomic physics reaction data.
#
class xs_data():
    def __init__(self,name,num_dep_var):
        self.name = name
        self.tab_index = np.ones((dep_var_max,table_rank_max),dtype=int)
        self.rank = np.zeros(dep_var_max,dtype=int)
        self.num_dep_var = num_dep_var
        self.data_base = np.zeros(dep_var_max,dtype=int)
        self.data_inc = np.zeros(dep_var_max,dtype=int)
        self.data_size = 0
        #
        # For an array of strings, we need to first define a NumPy array to hold the
        # characters.  Note that np.empty in general fills the array with random junk;
        # that's the case for strings, too.  Then initialize the arrays to "unknown",
        # padded to tag_string_length, to match the convention used by ratecalc.
        #
        self.spacing = np.empty((dep_var_max,table_rank_max+1,tag_string_length),
                                    dtype='|S1')
        self.spacing[:,:,:] = nc_string('unknown',tag_string_length)   
        self.var = np.empty((dep_var_max,table_rank_max+1,tag_string_length),dtype='|S1')
        self.var[:,:,:] = nc_string('unknown',tag_string_length)
        self.units = np.empty((dep_var_max,table_rank_max+1,unit_string_length),dtype='|S1')
        self.units[:,:,:] = nc_string('unknown',unit_string_length)
        self.mult = np.zeros((dep_var_max,table_rank_max+1),dtype=float)
        self.eval_name = np.empty((dep_var_max,eval_name_length),dtype='|S1')
        self.eval_name[:,:] = nc_string('unknown',eval_name_length)
        self.indep_min = np.zeros((dep_var_max,table_rank_max),dtype=float)
        self.indep_max = np.zeros((dep_var_max,table_rank_max),dtype=float)
#
# Sets up all of the auxiliary information for the dependent variable
# var_num.  The actual data are specified via the set_data method.
#
    def set_var(self,var_num,var,eval_name,dims,units,mult,indep_min,indep_max,spacing):
        rank = len(dims)
        self.rank[var_num] = rank
        self.eval_name[var_num] = nc_string(eval_name,eval_name_length)
        self.tab_index[var_num,0:rank] = dims
        self.mult[var_num,0:rank+1] = mult
        self.indep_min[var_num,0:rank] = indep_min
        self.indep_max[var_num,0:rank] = indep_max
        for i in range(rank+1):
            self.var[var_num,i] = nc_string(var[i],tag_string_length)
            self.units[var_num,i] = nc_string(units[i],unit_string_length)
            self.spacing[var_num,i] = nc_string(spacing[i],tag_string_length)
#
# Sets up the 1-D data_tab array that holds all of the data for
# this xs_data object.  This should only be called by the set_data
# method.  I.e., there is no need for the user to invoke this.
#
    def set_up_data(self):
        #
        # This is equivalent to the macro set_inc(x,y) in
        # xsection.hweb, the first step in xs_ragged_alloc(x,y)
        # there.
        #
        for j in range(self.tab_index.shape[0]):
            self.data_inc[j]=1
            for i in range(self.tab_index.shape[1]):
                self.data_inc[j]=self.data_inc[j]*self.tab_index[j,i]
        #
        # This is the second step, equivalent to the macro set_base(x,y).
        # We have replaced the macros range_min and range_max used in
        # xsection.hweb with 0 and the sizes of the array, respectively,
        # since that is how they will be defined in the netCDF file.
        # That is, we will not have arrays with indices starting at
        # 0 or 1; rather, the latter will be an array one longer than
        # the former.
        #
        self.data_base[0] = 0
        for i in range(1,self.data_base.shape[0]):
            self.data_base[i] = self.data_base[i-1] + self.data_inc[i-1]
        self.data_size = self.data_base[-1] + self.data_inc[-1]
        #
        # Set up the actual data table
        #
        self.data_tab = np.zeros(self.data_size,dtype=float)
        self.data_tab[self.data_base[self.num_dep_var]:] = 2.0e30  # real_unused
#
# Transfers the potentially multi-dimensional data for dependent variable
# var_num into the 1-D data_tab in this xs_data object.
#
    def set_data(self,var_num,data):
        #
        # Check to see if the data table increments, etc.
        # have been set up yet.
        #
        if (self.data_size == 0):
            self.set_up_data()
        #
        # Fill in the data table using the various arrays assembled above.
        # Note that the np.flatten method takes an optional argument
        # specifying its order of operation.  The one we want is *not* determined
        # by anything done above, but by the method in which the data table
        # is turned back into a multi-dimensional (ragged) object by the
        # xs_data_table macro in xsection.hweb.  This ordering turns out to
        # be the 'F' ordering. 
        #
        if (np.ndim(data) > 0):
            self.data_tab[self.data_base[var_num]:self.data_base[var_num+1]]=data.flatten('F')
        else:
            self.data_tab[self.data_base[var_num]:self.data_base[var_num+1]]=data
#
# The remaining methods in this class allow the user to
# explore the contents of an xs_data object, presumably
# one read from a netCDF file.
#
# This first one just lists the dependent variables and their units.
#
    def list_vars(self):
        print('{:>2}'.format('j'),'{:^30}'.format('Name'),
                  '{:^15}'.format('Units'))
        for j in range(self.num_dep_var):
            print('{:2d}'.format(j),
                      '{:<30}'.format(np.char.rstrip(self.var[j,0])),
                      '{:<15}'.format(np.char.rstrip(self.units[j,0])))
#
# Prints out more detailed information on dependent variable j,
# together with data on its independent variables.
#
    def print_var(self,j):
        print('Dependent variable: ',np.char.rstrip(self.var[j,0]),
                  ' Units: ',np.char.rstrip(self.units[j,0]),'\n',
                  'Multiplier: ','{:.5e}'.format(self.mult[j,0]),
                  ' Spacing: ',np.char.rstrip(self.spacing[j,0]),'\n')
        print('{:^15}'.format('Indep. var.'),'{:^10}'.format('Units'),
                  '{:^11}'.format('Multiplier'),
                  '{:^8}'.format('Spacing'),
                  '{:^11}'.format('Min.'),
                  '{:^11}'.format('Max.'))

        for i in range(self.rank[j]):
            print('{:<15}'.format(np.char.rstrip(self.var[j,i+1])),
                      '{:<10}'.format(np.char.rstrip(self.units[j,i+1])),
                      '{:.5e}'.format(self.mult[j,i+1]),
                      '{:<8}'.format(np.char.rstrip(self.spacing[j,i+1])),
                      '{:.5e}'.format(self.indep_min[j,i]),
                      '{:.5e}'.format(self.indep_max[j,i]))
#
# Returns a NumPy array containing all of the
# data corresponding to dependent variable j.  The resulting
# scalar or array has the dimensions as specified in the
# self.tab_index[j,:] array. 
#
    def get_var_data(self,j):
        if (j < dep_var_max-1):
            data_1d = self.data_tab[self.data_base[j]:self.data_base[j+1]]
        elif (j == dep_var_max-1):
            data_1d = self.data_tab[self.data_base[j]:]
        else:
            raise ValueError('Input variable ',j,' exceeds number of variables ',
                                 self.num_dep_var)
        if (self.rank[j] == 0):
            return data_1d.item()
        elif (self.rank[j] == 1):
            return data_1d
        elif (self.rank[j] == 2):
            return np.reshape(data_1d,
                                  (self.tab_index[j,0],self.tab_index[j,1]),'F')
        elif (self.rank[j] == 3):
            return np.reshape(data_1d,
                                  (self.tab_index[j,0],self.tab_index[j,1],self.tab_index[j,2]),
                                  'F')
        else:
            raise ValueError('Rank ',self.rank[j],' not handled')
#
# Corresponding method that returns the array of independent variable i's
# values for dependent variable j.  Note that the xs_data object does not
# have these explicitly.  Rather, this array is constructed from the independent
# variable's spacing, minimum, and maximum values.
#
    def get_indep_var(self,j,i):
        if (j > self.num_dep_var-1):
            raise ValueError('Input variable ',j,' exceeds number of variables ',
                                 self.num_dep_var)
        if (i > self.rank[j]-1):
            raise ValueError('Input variable ',i,' exceeds number of variables ',
                                 self.rank[j])
        if ((np.char.rstrip(self.spacing[j,i+1]) == 'linear')):
            delta = (self.indep_max[j,i]-self.indep_min[j,i])/(self.tab_index[j,i]-1.)
            indep_var = self.indep_min[j,i] + [delta*i for i in range(self.tab_index[j,i])]
        elif ((np.char.rstrip(self.spacing[j,i+1]) == 'log')):
            delta = np.log(self.indep_max[j,i]/self.indep_min[j,i])/(self.tab_index[j,i]-1.)
            indep_var = self.indep_min[j,i]*np.exp([delta*i for i in range(self.tab_index[j,i])])
        else:
            raise ValueError(' Spacing ',np.char.rstrip(self.spacing[j,i+1]),' not handled')

        return indep_var
#
# Returns a dictionary containing both independent and
# dependent variables using the variable names as keys.
#
    def get_var_dict(self,j):
        this_var = {}
        dep_var_data = self.get_var_data(j)
        print(type(np.char.rstrip(self.var[j,0]).tolist()))
        dep_var_key = 'dep_var: '+np.char.rstrip(self.var[j,0]).tolist()+\
          ' ('+np.char.rstrip(self.units[j,0]).tolist()+')'
        this_var.update({dep_var_key : dep_var_data})
        if (self.rank[j] == 0):
            return this_var
        else:
            for i in range(self.rank[j]):
                indep_var_data = self.get_indep_var(j,i)
                indep_var_key = 'indep_var '+'{}'.format(i)+': '+\
                  np.char.rstrip(self.var[j,i+1]).tolist()+\
                  ' ('+np.char.rstrip(self.units[j,i+1]).tolist()+')'
                this_var.update({indep_var_key : indep_var_data})
            return this_var
#
# Simpler method that returns only the independent and dependent
# variable data in a list.  Presumably, the user knows which is which
# via the print_var method.  As is clear from the method's name,
# the objective is to simplify plotting calls.
#
    def get_var4plot(self,j):
        var_data = []
        for i in range(self.rank[j]):
            var_data.append(self.get_indep_var(j,i))
        var_data.append(self.get_var_data(j))
        return var_data
#
# Corresponding class that either writes an xs_data
# object to or reads one from a netCDF file.
#
class xs_netCDF():
    #
    # The first full implementation of this class was targeted only
    # at writing files.  In that case, had only one constructor essentially
    # the same as write_ncfile below, but closing the file at the end.
    #
    # The same method could not be adapted to read a netCDF file since
    # the xs_data object in the argument would not exist at that point.
    # Moreover, because Python does not allow methods to be overloaded,
    # we were left to instead establish separate "classmethod" constructors
    # for writing and reading.  The root constructor then becomes nearly
    # trivial, consisting of specifying only the path to the file.
    #
    # Antother subtle difference relative to the original approach is
    # that the xs_data object is now also part of this class.  In the
    # "write" case, this was not needed since the xs_data object was
    # first created and passed in.  But, in the "read" case, this can not
    # be done.  Since there is no easy way to return this object, we
    # instead make it a class object and return ncfile.
    #
    # At present, we have also split off the file closing command to a
    # separate method to ensure that the user knows explicitly when a
    # file is open or closed.
    #
    def __init__(self,file_path):
        "basic constructor"
        
    @classmethod
    def write_ncfile(cls,xs,file_dir,descript,version):
        file_path = file_dir+xs.name+'.nc'
        ncfile = cls(file_path)
        ncfile.xs = xs
        ncfile.ds = netCDF4.Dataset(file_path,'w',format='NETCDF3_CLASSIC')
        ncfile.ds.description = descript
        ncfile.ds.data_version = version
        #
        # Create dimensions and variables in the
        # netCDF file.  The order of these definitions
        # has been set to match that of existing netCDF
        # xsection data files.
        #
        ncfile.ds.createDimension('rank_ind',table_rank_max)
        ncfile.ds.createDimension('rank_ind0',table_rank_max+1)
        ncfile.ds.createDimension('dep_var_ind',dep_var_max)
        ncfile.ds.createDimension('unit_string',unit_string_length)
        ncfile.ds.createDimension('tag_string',tag_string_length)
        ncfile.ds.createDimension('xs_symbol_string',rc_sy_len)
        ncfile.ds.createDimension('eval_name',eval_name_length)
        
        ncfile.ds.createDimension('xs_data_ind',xs.data_size)

        xs_data_size = ncfile.ds.createVariable('xs_data_size','i4')
        xs_num_dep_var = ncfile.ds.createVariable('xs_num_dep_var','i4')
        xs_rank = ncfile.ds.createVariable('xs_rank','i4',('dep_var_ind'))
        xs_tab_index = ncfile.ds.createVariable('xs_tab_index','i4',('dep_var_ind','rank_ind'))
        xs_data_base = ncfile.ds.createVariable('xs_data_base','i4',('dep_var_ind'))
        xs_data_inc = ncfile.ds.createVariable('xs_data_inc','i4',('dep_var_ind'))
        #
        # Writing the data into the netCDF files amounts to just setting
        # the netCDF variable values to the corresponding NumPy variables
        # defined in the xs_data class:
        #
        xs_data_size[:] = xs.data_size
        xs_num_dep_var[:] = xs.num_dep_var
        xs_rank[:] = xs.rank
        xs_tab_index[:] = xs.tab_index
        xs_data_base[:] = xs.data_base
        xs_data_inc[:] = xs.data_inc
        #
        # The handling of strings passed to the netCDF files is less than
        # obvious.  We pass a basic Python string type to the netCDF function stringtoarr,
        # used above to define the nc_string function.  The rc_sy_len argument is needed
        # to match up with the length of the xs_name variable.  To reproduce exactly
        # what was in the Fortran-written files, we use the ljust function to pad the
        # string with spaces.
        #
        xs_name = ncfile.ds.createVariable('xs_name','|S1',('xs_symbol_string'))
        xs_name[:] = nc_string(xs.name,rc_sy_len)
        #
        # This same approach is needed for arrays for strings.  In addition, care is needed in
        # setting up the NumPy arrays fed into them, as is described in the xs_data class.
        # 
        xs_spacing = ncfile.ds.createVariable('xs_spacing','|S1',('dep_var_ind','rank_ind0','tag_string'))
        xs_spacing[:] = xs.spacing

        xs_var = ncfile.ds.createVariable('xs_var','|S1',('dep_var_ind','rank_ind0','tag_string'))
        xs_var[:] = xs.var

        xs_units = ncfile.ds.createVariable('xs_units','|S1',('dep_var_ind','rank_ind0','unit_string'))
        xs_units[:] = xs.units

        xs_eval_name = ncfile.ds.createVariable('xs_eval_name','|S1',('dep_var_ind','eval_name'))
        xs_eval_name[:] = xs.eval_name

        xs_min = ncfile.ds.createVariable('xs_min','f8',('dep_var_ind','rank_ind'))
        xs_min[:] = xs.indep_min

        xs_max = ncfile.ds.createVariable('xs_max','f8',('dep_var_ind','rank_ind'))
        xs_max[:] = xs.indep_max

        xs_mult = ncfile.ds.createVariable('xs_mult','f8',('dep_var_ind','rank_ind0'))
        xs_mult[:] =xs.mult

        xs_data_tab = ncfile.ds.createVariable('xs_data_tab','f8',('xs_data_ind'))
        xs_data_tab[:] = xs.data_tab
        
        return ncfile
    
    @classmethod
    def read_ncfile(cls,xs_name,file_dir):
        file_path = file_dir+xs_name+'.nc'
        ncfile = cls(file_path)
        ncfile.ds = netCDF4.Dataset(file_path,'r',format='NETCDF3_CLASSIC')
        num_dep_var = ncfile.ds.variables['xs_num_dep_var'][:]
        name = ncfile.ds.variables['xs_name'][:]
        #
        # Strictly speaking, the name of DEGAS 2 reaction files is
        # supposed to be the same as xs_name.  Hence, we have implemented
        # this test.  This may need to be relaxed at some point for
        # the purposes of testing data files.
        #
        if (netCDF4.chartostring(name).item().strip() != xs_name):
            raise ValueError('Input name ',xs_name,
                                 ' does not match file name ',
                                 netCDF4.chartostring(name).item().strip())
        ncfile.xs = xs_data(xs_name,num_dep_var)

        ncfile.xs.data_size = ncfile.ds.variables['xs_data_size'][:]
        ncfile.xs.rank = ncfile.ds.variables['xs_rank'][:]
        ncfile.xs.tab_index = ncfile.ds.variables['xs_tab_index'][:]
        ncfile.xs.data_base = ncfile.ds.variables['xs_data_base'][:]
        ncfile.xs.data_inc = ncfile.ds.variables['xs_data_inc'][:]
        ncfile.xs.spacing = netCDF4.chartostring(ncfile.ds.variables['xs_spacing'][:])
        ncfile.xs.var = netCDF4.chartostring(ncfile.ds.variables['xs_var'][:])
        ncfile.xs.units = netCDF4.chartostring(ncfile.ds.variables['xs_units'][:])
        ncfile.xs.eval_name = netCDF4.chartostring(ncfile.ds.variables['xs_eval_name'][:])
        ncfile.xs.indep_min = ncfile.ds.variables['xs_min'][:]
        ncfile.xs.indep_max = ncfile.ds.variables['xs_max'][:]
        ncfile.xs.mult = ncfile.ds.variables['xs_mult'][:]
        ncfile.xs.data_tab = ncfile.ds.variables['xs_data_tab'][:]
        
        return ncfile

    def close(self):
        self.ds.close()

