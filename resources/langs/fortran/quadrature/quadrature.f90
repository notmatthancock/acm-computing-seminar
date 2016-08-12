! [[file:../fortran.org::*Quadrature][Quadrature:3]]
module quadrature
  implicit none

contains

  function midpoint_rule(f,a,b,n) result(I)
    interface
       function f(x)
         real, intent(in) :: x
         real :: f
       end function f
    end interface
    real :: a, b
    integer :: n, j
    real :: I, dx

    dx = (b-a)/real(n)
    I = 0
    do j = 0,n-1
       I = I + f(a + (j+.5)*dx)
    end do
    I = dx*I
  end function midpoint_rule

end module quadrature
! Quadrature:3 ends here
