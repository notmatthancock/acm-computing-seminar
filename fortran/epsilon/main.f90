! [[file:../fortran.org::*Machine%20Epsilon][Machine\ Epsilon:3]]
program main
  use constants
  implicit none
  print*, machine_epsilon(0._sp), machine_epsilon(0._dp)
end program main
! Machine\ Epsilon:3 ends here
