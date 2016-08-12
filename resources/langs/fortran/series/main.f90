! [[file:../fortran.org::*$\sum_{n=0}^{\infty}\frac1{n!}$][$\\sum_{n=0}^{\\infty}\\frac1{n!}$:1]]
program main
  implicit none
  integer :: n = 0, nf = 1
  real :: s = 0
  do while (1./real(nf) > 0)
     s = s + 1./real(nf)
     n = n + 1
     nf = nf * n
  end do
  print*, s, exp(1.)-s
end program main
! $\\sum_{n=0}^{\\infty}\\frac1{n!}$:1 ends here
