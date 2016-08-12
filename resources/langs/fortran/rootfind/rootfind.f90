! [[file:../fortran.org::*Rootfinding][Rootfinding:3]]
module rootfind
  implicit none

  interface
     function fun(x)
       real, intent(in) :: x
       real :: fun
     end function fun
  end interface

contains

  function newton(f,dfdx,x0,tol,maxstep) result(xn)
    procedure(fun), pointer :: f, dfdx
    real, intent(in) :: x0, tol
    integer, intent(in) :: maxstep
    real :: xn
    integer :: n = 0

    xn = x0
    do while (abs(f(xn))>tol .and. n<maxstep)
       xn = xn - f(xn)/dfdx(xn)
       n = n + 1
    end do
  end function newton

end module rootfind
! Rootfinding:3 ends here
