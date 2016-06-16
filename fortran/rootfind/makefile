# [[file:../fortran.org::*Rootfinding][Rootfinding:7]]
FC = gfortran
SRC = main.f90
EXE = main
OBJ = functions.o rootfind.o

all: $(EXE)
$(EXE): $(OBJ)
  $(FC) $(OBJ) $(SRC) -o $(EXE) 
%.o: %.f90
  $(FC) -c $< -o $@
clean:
  $(RM) *.o $(EXE)
# Rootfinding:7 ends here
