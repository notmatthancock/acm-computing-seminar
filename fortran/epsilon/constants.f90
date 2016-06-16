! [[file:../fortran.org::*Machine%20Epsilon][Machine\ Epsilon:1]]
module constants
  implicit none

  integer, parameter :: sp = kind(0.), dp = kind(0.d0)
  integer, parameter :: rp = dp

  interface machine_epsilon
     module procedure machine_epsilon_sp, machine_epsilon_dp
  end interface machine_epsilon

contains

  function machine_epsilon_sp(x) result(e)
    implicit none
    real(sp), intent(in) :: x
    real :: e
    e = .5
    do while (1._sp + e > 1._sp)
       e = .5 * e
    end do
  end function machine_epsilon_sp

  function machine_epsilon_dp(x) result(e)
    implicit none
    real(dp), intent(in) :: x
    real :: e
    e = .5
    do while (1._dp + e > 1._dp)
       e = .5 * e
    end do
  end function machine_epsilon_dp

end module constants
! Machine\ Epsilon:1 ends here
