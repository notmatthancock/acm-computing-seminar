! [[file:../fortran.org::*Quadrature][Quadrature:5]]
program main
  use functions
  use quadrature
  implicit none

  real :: a = 0, b = 1
  integer :: n = 5
  print*, midpoint_rule(f1,a,b,n)

end program main
! Quadrature:5 ends here
