program main
  use functions
  use rootfinding
  implicit none

  procedure(fun), pointer :: f, dfdx
  real :: x = 1., tol = 1e-5
  integer :: maxstep = 100
  f => f1
  dfdx => df1dx
  print*, newton(f,dfdx,x,tol,maxstep)

end program main
