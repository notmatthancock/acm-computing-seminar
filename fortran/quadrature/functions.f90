! [[file:../fortran.org::*Quadrature][Quadrature:1]]
module functions
  implicit none

contains

  function f1(x)
    real, intent(in) :: x
    real :: f1
    f1 = x
  end function f1

end module functions
! Quadrature:1 ends here
