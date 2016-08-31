module matrix_module
  implicit none

  public :: zeros
  public :: identity
  public :: random

  type matrix
     integer :: shape(2)
     real, allocatable :: data(:,:)
   contains
     procedure :: construct => matrix_construct
     procedure :: destruct => matrix_destruct
     procedure :: norm => matrix_norm
  end type matrix

  type vector
     integer :: length
     real, allocatable :: data(:)
   contains
     procedure :: construct => vector_construct
     procedure :: destruct => vector_destruct
     procedure :: norm => vector_norm
  end type vector

  ! assignments
  interface assignment(=)
     procedure vec_num_assign, vec_vec_assign, mat_num_assign, mat_mat_assign
  end interface assignment(=)

  ! operations
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

  interface operator(**)
     procedure mat_pow
  end interface operator(**)

  ! functions
  interface norm
     procedure vector_norm, matrix_norm
  end interface norm

  ! structured vectors/matrices
  interface zeros
     procedure zeros_vector, zeros_matrix
  end interface zeros

  interface random
     procedure random_vector, random_matrix
  end interface random

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

  ! assignment
  subroutine vec_num_assign(vec,num)
    type(vector), intent(inout) :: vec
    real, intent(in) :: num
    vec%data = num
  end subroutine vec_num_assign

  subroutine vec_vec_assign(vec1,vec2)
    type(vector), intent(inout) :: vec1
    type(vector), intent(in) :: vec2
    vec1%data = vec2%data
  end subroutine vec_vec_assign

  subroutine mat_num_assign(mat,num)
    type(matrix), intent(inout) :: mat
    real, intent(in) :: num
    mat%data = num
  end subroutine mat_num_assign

  subroutine mat_mat_assign(mat1,mat2)
    type(matrix), intent(inout) :: mat1
    type(matrix), intent(in) :: mat2
    mat1%data = mat2%data
  end subroutine mat_mat_assign

  ! operations
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
    prod%data = matmul(mat%data,vec%data)
  end function mat_vec_prod

  function mat_mat_prod(mat1,mat2) result(prod)
    type(matrix), intent(in) :: mat1, mat2
    type(matrix) :: prod
    call prod%construct(mat1%shape(1),mat2%shape(2))
    prod%data = matmul(mat1%data,mat2%data)
  end function mat_mat_prod

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

  function mat_pow(mat1,pow) result(mat2)
    type(matrix), intent(in) :: mat1
    integer, intent(in) :: pow
    type(matrix) :: mat2
    integer :: i
    mat2 = mat1
    do i = 2,pow
       mat2 = mat1*mat2
    end do
  end function mat_pow

  ! functions
  function vector_norm(this,p) result(mag)
    class(vector), intent(in) :: this
    integer, intent(in) :: p
    real :: mag
    integer :: i
    ! inf-norm
    if (p==0) then
       mag = 0.0
       do i = 1,this%length
          mag = max(mag,abs(this%data(i)))
       end do
    ! p-norm
    else if (p>0) then
       mag = (sum(abs(this%data)**p))**(1./p)
    end if
  end function vector_norm

  function matrix_norm(this, p) result(mag)
    class(matrix), intent(in) :: this
    integer, intent(in) :: p
    real ::  mag, tol = 1e-6
    integer :: m, n, row, col, iter, max_iters = 1000
    type(vector) :: vec, last_vec
    m = size(this%data(:,1)); n = size(this%data(1,:))

    ! entry-wise norms
    if (p<0) then
       mag = (sum(abs(this%data)**(-p)))**(-1./p)
    ! inf-norm
    else if (p==0) then
       mag = 0.0
       do row = 1,m
          mag = max(mag,sum(abs(this%data(row,:))))
       end do
    ! 1-norm
    else if (p==1) then
       mag = 0.0
       do col = 1,n
          mag = max(mag,sum(abs(this%data(:,col))))
       end do
    ! p-norm
    else if (p>0) then
       vec = random(n)
       vec = vec/vec%norm(p)
       last_vec = zeros(n)
       mag = 0.0
       do iter = 1,max_iters
          last_vec = vec
          vec = this*last_vec
          vec = vec/vec%norm(p)
          if (vector_norm(vec-last_vec,p)<tol) exit
       end do
       mag = vector_norm(this*vec,p)
    end if
  end function matrix_norm

  ! structured vectors/matrices
  function random_matrix(m,n) result(mat)
    integer :: m,n
    type(matrix) :: mat
    call mat%construct(m,n)
    call random_seed()
    call random_number(mat%data)
  end function random_matrix

  function random_vector(n) result(vec)
    integer :: n
    type(vector) :: vec
    call vec%construct(n)
    call random_seed()
    call random_number(vec%data)
  end function random_vector

  function zeros_vector(n) result(vec)
    integer :: n
    type(vector) :: vec
    call vec%construct(n)
    vec = 0.0
  end function zeros_vector

  function zeros_matrix(m,n) result(mat)
    integer :: m,n
    type(matrix) :: mat
    call mat%construct(m,n)
    mat = 0.0
  end function zeros_matrix

  function identity(m,n) result(mat)
    integer :: m,n,i
    type(matrix) :: mat
    call mat%construct(m,n)
    do i = 1,min(m,n)
       mat%data(i,i) = 1.0
    end do
  end function identity

end module matrix_module
