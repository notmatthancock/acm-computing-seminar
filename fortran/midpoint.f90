program main
  use functions
  use quadrature
  implicit none

  procedure(integrand), pointer :: f
  real :: a, b
  integer :: n
  f => f1
  print*, midpoint_rule(f,a,b,n)

end program main
