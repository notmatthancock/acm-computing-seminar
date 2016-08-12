! [[file:../fortran.org::*Rootfinding][Rootfinding:5]]
program main
  use functions
  use rootfind
  implicit none

  procedure(fun), pointer :: f, dfdx
  real :: x = 1., tol = 1e-5
  integer :: maxstep = 100
  f => f1
  dfdx => df1dx
  print*, newton(f,dfdx,x,tol,maxstep)

end program main
! Rootfinding:5 ends here
