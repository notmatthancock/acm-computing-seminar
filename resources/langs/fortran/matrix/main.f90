program main
  use matrix_module
  implicit none

  type(matrix) :: mat
  integer :: n

  ! compute determinants of random matrices
  do n = 1,5
     ! generate random  matrix
     mat = random_matrix(n,n)

     ! print determinant of matrix
     print "('n: ', i0, ', det: ', f0.5)", n, det(mat)

     ! destruct matrix
     call mat%destruct()
  end do

end program main
