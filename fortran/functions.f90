program main
module functions
  implicit none

contains

  function f1(x)
    real, intent(in) :: x
    real :: f1
    f1 = x
  end function f1

end module functions
end program main
