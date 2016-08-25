FC = gfortran
SRC = main.f90
EXE = main
OBJ = matrix_module.o

all: $(EXE)
$(EXE): $(OBJ)
	$(FC) $(OBJ) $(SRC) -o $(EXE) 
%.o: %.f90
	$(FC) -c $< -o $@
