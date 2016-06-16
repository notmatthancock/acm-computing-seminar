! [[file:../fortran.org::*Rootfinding][Rootfinding:1]]
module functions
  implicit none

contains

  function f1(x)
    real, intent(in) :: x
    real :: f1
    f1 = sin(x)
  end function f1

  function df1dx(x)
    real, intent(in) :: x
    real :: df1dx
    df1dx = cos(x)
  end function df1dx

end module functions
! Rootfinding:1 ends here
