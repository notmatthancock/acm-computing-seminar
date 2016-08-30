module matrix_module
  implicit none

  type matrix
     integer :: shape(2)
     real, allocatable :: data(:,:)
   contains
     procedure :: construct
     procedure :: destruct
     procedure :: print
     procedure :: det
  end type matrix

contains

  subroutine construct(this, m, n)
    class(matrix) :: this
    integer :: m,n
    this%shape = [m,n]
    allocate(this%data(m,n))
  end subroutine construct

  subroutine destruct(this)
    class(matrix) :: this
    deallocate(this%data)
  end subroutine destruct

  ! print: formatted print of matrix
  subroutine print(this)
    class(matrix) :: this
    ! row_fmt: format character string for row printing
    ! fmt: temporary format string
    character(32) :: row_fmt, fmt = '(a,i0,a,i0,a,i0,a)'
    ! w: width of each entry printed
    ! d: number of decimal digits printed
    integer :: w, d = 2, row
    ! find largest width of element in matrix
    w = ceiling(log10(maxval(abs(this%data)))) + d + 2
    ! write row formatting to 'row_fmt' variable
    write(row_fmt,fmt) '(',this%shape(2),'(f',w,'.',d,',1x))'
    ! print matrix row by row
    do row = 1,this%shape(1)
       print row_fmt, this%data(row,:)
    end do
  end subroutine print

  ! det: compute determinant of matrix
  ! using recursive definition based on cofactors
  recursive function det(this) result(d)
    class(matrix) :: this
    type(matrix) :: submatrix
    real :: d, sgn, element, minor
    integer :: m, n, row, col, i, j

    m = this%shape(1)
    n = this%shape(2)
    d = 0.0

    ! compute cofactor
    ! if 1x1 matrix, return value
    if (m==1.and.n==1) then
       d = this%data(1,1)
    ! if square and not 1x1
    else if (m==n) then
       ! cofactor sum down the first column
       do row = 1,m
          ! sign of term
          sgn = (-1.0)**(row+1)
          ! matrix element
          element = this%data(row,1)
          ! construct the cofactor submatrix and compute its determinant
          call submatrix%construct(m-1,n-1)
          if (row==1) then
             submatrix%data = this%data(2:,2:)
          else if (row==m) then
             submatrix%data = this%data(:m-1,2:)
          else
             submatrix%data(:row-1,:) = this%data(:row-1,2:)
             submatrix%data(row:,:) = this%data(row+1:,2:)
          end if
          minor = submatrix%det()
          call submatrix%destruct()

          ! determinant accumulator
          d = d + sgn*element*minor
       end do
    end if
  end function det

  ! random_matrix: generate matrix with random entries in [-1,1]
  ! m,n: number of rows,cols
  function random_matrix(m,n) result(mat)
    integer :: m,n,i,j
    type(matrix) :: mat
    ! allocate memory for matrix
    call mat%construct(m,n)
    ! seed random number generator
    call srand(time())
    ! populate matrix
    do i = 1,m
       do j = 1,n
          mat%data(i,j) = 2.0*rand() - 1.0
       end do
    end do
  end function random_matrix

end module matrix_module
