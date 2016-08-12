# [[file:../fortran.org::*Project%20template][Project\ template:6]]
FC = gfortran
SRC = main.f90
EXE = main
OBJ = header.o

all: $(EXE)
$(EXE): $(OBJ)
  $(FC) $(OBJ) $(SRC) -o $(EXE)
%.o: %.f90
  $(FC) -c $< -o $@
clean:
  $(RM) *.o $(EXE)
# Project\ template:6 ends here
