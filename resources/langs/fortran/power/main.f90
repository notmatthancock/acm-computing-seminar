program main
  use matrix_module
  implicit none

  type(vector) :: vec1, vec2
  type(matrix) :: mat1, mat2
  real :: x
  integer :: i

  ! 0s, id, random
  mat1 = zeros(3,3)
  call mat1%destruct()
  mat1 = identity(3,3)
  mat2 = random(3,3)
  mat1 = mat1*mat1
  vec1 = zeros(3)
  call vec1%destruct()
  vec1 = random(3)
  vec2 = random(3)
  ! +,-,*,/,**
  mat1 = mat1+mat2
  vec1 = vec1+vec2
  mat1 = mat1-mat2
  vec1 = vec1-vec2
  vec1 = mat1*vec2
  mat1 = mat2*mat1
  mat1 = 2.0*mat1
  vec1 = 2.0*vec1
  mat1 = mat1/2.0
  vec1 = vec1/2.0
  mat2 = mat1**3
  ! norm
  x = norm(vec1,0)
  x = norm(vec1,1)
  x = norm(mat1,-1)
  x = norm(mat1,0)
  x = norm(mat1,1)
  x = norm(mat1,2)
  call vec1%destruct
  call vec2%destruct
  call mat1%destruct
  call mat2%destruct
end program main
