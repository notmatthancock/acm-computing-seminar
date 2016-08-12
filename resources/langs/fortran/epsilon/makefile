# [[file:../fortran.org::*Machine%20Epsilon][Machine\ Epsilon:6]]
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
# Machine\ Epsilon:6 ends here
