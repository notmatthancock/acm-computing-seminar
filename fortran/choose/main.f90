! [[file:../fortran.org::*${n%20\choose%20k}$][${n\ \\choose\ k}$:1]]
program main
  implicit none
  print*, choose(4,0), choose(4,1), &
       choose(4,2), choose(4,3), choose(4,4)
contains
  function choose(n,k) result(c)
    integer, intent(in) :: n, k
    integer :: c, i
    c = 1
    do i = 1, min(k,n-k)
       c = c * (n-i+1) / i
    end do
  end function choose
end program main
! ${n\ \\choose\ k}$:1 ends here
