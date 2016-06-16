# [[file:../fortran.org::*Quadrature][Quadrature:7]]
FC = gfortran
SRC = main.f90
EXE = main
OBJ = functions.o quadrature.o

all: $(EXE)
$(EXE): $(OBJ)
  $(FC) $(OBJ) $(SRC) -o $(EXE) 
%.o: %.f90
  $(FC) -c $< -o $@
clean:
  $(RM) *.o $(EXE)
# Quadrature:7 ends here
