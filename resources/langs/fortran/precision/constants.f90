! [[file:../fortran.org::*Setting%20precision%20of%20variables][Setting\ precision\ of\ variables:1]]
module constants
  implicit none
  integer, parameter :: sp = kind(0.), dp = kind(0.d0)
  integer, parameter :: rp = dp
end module constants
! Setting\ precision\ of\ variables:1 ends here
