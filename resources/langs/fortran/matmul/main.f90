! [[file:../fortran.org::*Matrix%20multiplication][Matrix\ multiplication:1]]
program main
  implicit none

  real :: A(4,4), B(4,4)
  A=1; B=2

  print*, matrix_multiply(A,B)

contains

  function matrix_multiply(A,B) result(C)
    implicit none
    real :: A(4,4), B(4,4), C(4,4)
    integer :: i,j,k

    C = 0
    do i=1,4
       do j=1,4
          do k=1,4
             C(i,j) = C(i,j) + A(i,k)*B(k,j)
          end do
       end do
    end do

    end function matrix_multiply

end program main
! Matrix\ multiplication:1 ends here
