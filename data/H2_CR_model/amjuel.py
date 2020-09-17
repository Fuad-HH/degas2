import numpy as np

def get_AMJUEL_fit(filename,H123,reacstr):
    datafile = open(filename,'rt')
    data_start=False
    section_start=False
    reaction_start=False
    isw=int(H123.split('.')[1])
    if ((isw == 3) or (isw == 4) or (isw == 12)):
        j=-1
        fit_coef=np.zeros((9,9))
        index_start=False
        skip_line=False
#
# The logic here appears a little convoluted, but 
# is intended to mimic as closely as possible the 
# sequences in the EIRENE routine slreac.  In particular,
# that routine uses three nested do-loops for this search
# and read procedure; we have replaced them here with a 
# single loop over the entire file.  The reaction_start and
# index_start flags effectively replace the do-loops; the
# tests on i and j then correspond to the do loop limits.
# Note the "break" to exit the entire loop at the end.
#
    for line in datafile:
        if '##BEGIN DATA HERE##' in line:
            data_start=True
        if (data_start and (H123 in line) ):
            section_start=True
        if (section_start and 
           (('Reaction ' in line) and (reacstr in line))):
            reaction_start=True
        if (reaction_start):
            if ((isw == 3) or (isw == 4) or (isw == 12)):
                if (('Index' in line) and (not index_start)
                   and (not skip_line)):
                    index_start=True
                    skip_line=True
                    j=j+1
                    i=0
                else:
                    if (index_start and (not skip_line)):
                        linevalues=[float(x.replace('D','E')) for x in line.split()]
                        fit_coef[i,j*3:j*3+3] = linevalues[1:]
                        if (i == 8):
                            index_start=False
                            if (j == 2):
                                break
                        i=i+1
                    else:
                        skip_line=False
    datafile.close()
    return fit_coef

def ne_Te_exp_fit(fit_coef,ne,Te):
    log_Te = np.log(Te)
    log_ne8 = np.log(ne*1.e-8)
    fit = 0.0        
    for kn in range(9):
        ne_fac = np.power(log_ne8,kn)
        for kt in range(9):
            Te_fac = np.power(log_Te,kt)
            fit = fit + fit_coef[kt,kn]*ne_fac*Te_fac
    fit = np.exp(fit)
    return fit

def Eb_T_exp_fit(fit_coef,Eb,T):
    log_T = np.log(T)
    log_Eb = np.log(Eb)
    fit = 0.0        
    for kn in range(9):
        ne_fac = np.power(log_Eb,kn)
        for kt in range(9):
            T_fac = np.power(log_T,kt)
            fit = fit + fit_coef[kt,kn]*ne_fac*T_fac
    fit = np.exp(fit)
    return fit
