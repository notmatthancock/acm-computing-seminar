# [[file:../fortran.org::*Setting%20precision%20of%20variables][Setting\ precision\ of\ variables:6]]
FC = gfortran
SRC = main.f90
EXE = main
OBJ = constants.o

all: $(EXE)
$(EXE): $(OBJ)
  $(FC) $(OBJ) $(SRC) -o $(EXE) 
%.o: %.f90
  $(FC) -c $< -o $@
clean:
  $(RM) *.o $(EXE)
# Setting\ precision\ of\ variables:6 ends here
