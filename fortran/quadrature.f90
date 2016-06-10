program main
module quadrature
  implicit none

  interface
     function integrand(x)
       real, intent(in) :: x
       real :: integrand
     end function integrand
  end interface

contains

  function midpoint_rule(f,a,b,n) result(I)
    implicit none
    procedure(integrand), pointer :: f
    real :: a, b
    integer :: n
    real :: I
    I = 0
  end function midpoint_rule

end module quadrature
end program main
