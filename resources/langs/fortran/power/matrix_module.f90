module matrix_module
  implicit none

  type matrix
     integer :: shape(2)
     real, allocatable :: data(:,:)
   contains
     procedure :: construct => matrix_construct
     procedure :: destruct => matrix_destruct
     procedure :: max_eig
  end type matrix

  type vector
     integer :: length
     real, allocatable :: data(:)
   contains
     procedure :: construct => vector_construct
     procedure :: destruct => vector_destruct
  end type vector

  interface assignment(=)
     procedure vec_num_assign, vec_vec_assign, mat_num_assign, mat_mat_assign
  end interface assignment(=)

  interface operator(+)
     procedure vec_vec_sum, mat_mat_sum
  end interface operator(+)

  interface operator(-)
     procedure vec_vec_diff, mat_mat_diff
  end interface operator(-)

  interface operator(*)
     procedure num_vec_prod, num_mat_prod, mat_vec_prod, mat_mat_prod
  end interface operator(*)

  interface operator(/)
     procedure vec_num_quot, mat_num_quot
  end interface operator(/)

  interface norm2
     procedure vec_norm2
  end interface norm2

contains

  subroutine matrix_construct(this, m, n)
    class(matrix) :: this
    integer :: m,n
    this%shape = [m,n]
    allocate(this%data(m,n))
  end subroutine matrix_construct

  subroutine vector_construct(this, n)
    class(vector) :: this
    integer :: n
    this%length = n
    allocate(this%data(n))
  end subroutine vector_construct

  subroutine matrix_destruct(this)
    class(matrix) :: this
    deallocate(this%data)
  end subroutine matrix_destruct

  subroutine vector_destruct(this)
    class(vector) :: this
    deallocate(this%data)
  end subroutine vector_destruct

  subroutine max_eig(this, iter, val, vec)
    class(matrix), intent(in) :: this
    integer, intent(inout) :: iter
    real, intent(inout) :: val
    type(vector), intent(inout) :: vec
    type(vector) :: last_vec
    real :: tol=1e-6
    integer :: max_iters, i

    vec = random_vector(this%shape(2))
    vec = vec/norm2(vec)

    call last_vec%construct(this%shape(2))
    last_vec%data = 0.0
    max_iters = iter
    iter = 0

    do while (norm2(vec-last_vec)>tol.and.iter<max_iters)
       last_vec%data = vec%data
       vec = this*last_vec
       vec = vec/norm2(vec)
       iter = iter+1
    end do

    val = norm2(this*vec)

  end subroutine max_eig

  function random_matrix(m,n) result(mat)
    integer :: m,n,i,j
    type(matrix) :: mat
    call mat%construct(m,n)
    call srand(time())
    do i = 1,m
       do j = 1,n
          mat%data(i,j) = rand()
       end do
    end do
  end function random_matrix

  function random_vector(n) result(vec)
    integer :: n,i
    type(vector) :: vec
    call vec%construct(n)
    call srand(time())
    do i = 1,n
       vec%data(i) = rand()
    end do
  end function random_vector

  ! assignment
  subroutine vec_num_assign(vec,num)
    type(vector), intent(out) :: vec
    real, intent(in) :: num
    vec%data = num
  end subroutine vec_num_assign

  subroutine vec_vec_assign(vec1,vec2)
    type(vector), intent(out) :: vec1
    type(vector), intent(in) :: vec2
    vec1%data = vec2%data
  end subroutine vec_vec_assign

  subroutine mat_num_assign(mat,num)
    type(matrix), intent(out) :: mat
    real, intent(in) :: num
    mat%data = num
  end subroutine mat_num_assign

  subroutine mat_mat_assign(mat1,mat2)
    type(matrix), intent(out) :: mat1
    type(matrix), intent(in) :: mat2
    mat1%data = mat2%data
  end subroutine mat_mat_assign

  ! addition
  function vec_vec_sum(vec1,vec2) result(s)
    type(vector), intent(in) :: vec1, vec2
    type(vector) :: s
    call s%construct(vec1%length)
    s%data = vec1%data + vec2%data
  end function vec_vec_sum

  function mat_mat_sum(mat1,mat2) result(s)
    type(matrix), intent(in) :: mat1, mat2
    type(matrix) :: s
    call s%construct(mat1%shape(1),mat1%shape(2))
    s%data = mat1%data+mat2%data
  end function mat_mat_sum

  ! subtraction
  function vec_vec_diff(vec1,vec2) result(diff)
    type(vector), intent(in) :: vec1, vec2
    type(vector) :: diff
    call diff%construct(vec1%length)
    diff%data = vec1%data-vec2%data
  end function vec_vec_diff

  function mat_mat_diff(mat1,mat2) result(diff)
    type(matrix), intent(in) :: mat1, mat2
    type(matrix) :: diff
    call diff%construct(mat1%shape(1),mat1%shape(2))
    diff%data = mat1%data-mat2%data
  end function mat_mat_diff

  ! multiplication
  function num_vec_prod(num,vec) result(prod)
    real, intent(in) :: num
    type(vector), intent(in) :: vec
    type(vector) :: prod
    call prod%construct(vec%length)
    prod%data = num*vec%data
  end function num_vec_prod

  function num_mat_prod(num,mat) result(prod)
    real, intent(in) :: num
    type(matrix), intent(in) :: mat
    type(matrix) :: prod
    call prod%construct(mat%shape(1),mat%shape(2))
    prod%data = num*mat%data
  end function num_mat_prod

  function mat_vec_prod(mat,vec) result(prod)
    type(matrix), intent(in) :: mat
    type(vector), intent(in) :: vec 
    type(vector) :: prod
    call prod%construct(mat%shape(1))
    print*, mat%shape, vec%length
    prod%data = matmul(mat%data,vec%data)
  end function mat_vec_prod

  function mat_mat_prod(mat1,mat2) result(prod)
    type(matrix), intent(in) :: mat1, mat2
    type(matrix) :: prod
    call prod%construct(mat1%shape(1),mat2%shape(2))
    print*, mat1%shape, mat2%shape
    prod%data = matmul(mat1%data,mat2%data)
  end function mat_mat_prod

  ! division
  function vec_num_quot(vec,num) result(quot)
    type(vector), intent(in) :: vec
    real, intent(in) :: num
    type(vector) :: quot
    call quot%construct(vec%length)
    quot%data = vec%data/num
  end function vec_num_quot

  function mat_num_quot(mat,num) result(quot)
    type(matrix), intent(in) :: mat
    real, intent(in) :: num
    type(matrix) :: quot
    call quot%construct(mat%shape(1),mat%shape(2))
    quot%data = mat%data/num
  end function mat_num_quot

  ! norm
  function vec_norm2(vec) result(norm)
    type(vector), intent(in) :: vec
    real :: norm
    norm = norm2(vec%data)
  end function vec_norm2

end module matrix_module
