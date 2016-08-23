program main
  implicit none

  character(32) :: arg
  integer :: n_arg = 0

  do
     ! get next command line argument
     call get_command_argument(n_arg, arg)

     ! if it is empty, exit
     if (len_trim(arg) == 0) exit

     ! print argument to screen
     print"('argument ', i0, ': ', a)", n_arg, trim(arg)

     ! increment count
     n_arg = n_arg+1
  end do

  ! print total number of arguments
  print "('number of arguments: ', i0)", n_arg

end program main
