#! /bin/tcsh

setenv DGCTOP $PWD

switch (`uname`)
case "SunOS"
  setenv OBJECTCODE SUN
  breaksw
case "AIX"
  setenv OBJECTCODE IBM
  breaksw
case "OSF1"
  setenv OBJECTCODE ALPHA
  breaksw
case "HP-UX"
  setenv OBJECTCODE HP
  breaksw
case "IRIX"
  setenv OBJECTCODE IRIX
  breaksw
case "Linux"
  setenv OBJECTCODE LINUX
  setenv COMPILER UNKNOWN
  which pathf90 >& /dev/null
  if ($status == 0) setenv COMPILER PATHSCALE
  which pgf90 >& /dev/null
  if ($status == 0) setenv COMPILER PGROUP
  breaksw
default:
  setenv OBJECTCODE UNKNOWN
  breaksw
endsw

if ($1 == "") then
  setenv DEVICE iter
else
  setenv DEVICE $1
endif
#
# Not sure how useful this will be, but it's at least a placeholder
#
setenv LESSTIF `echo $LD_LIBRARY_PATH | sed -e 's/:/\n/g' | awk '/lesstif/ { print $1}'`

alias cddg 'cd $DGCTOP/DG/class/$DEVICE'
alias cdcarre 'cd $DGCTOP/Carre'

