program main
  use constants
  implicit none
  print*, machine_epsilon(0._sp), &
       machine_epsilon(0._dp), &
       machine_epsilon(0._rp)
end program main
