program main
  use matrix_module
  implicit none

  type(matrix) :: mat
  type(vector) :: vec
  integer :: n, iter
  real :: val

  do n = 2,5
     iter = 100
     mat = random_matrix(n,n)
     call mat%max_eig(iter,val,vec)
     print *, n, iter, val, norm2(mat*vec-val*vec)
     call mat%destruct()
     call vec%destruct()
  end do

end program main
