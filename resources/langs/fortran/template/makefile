FC = gfortran
SRC = main.f90
EXE = main
OBJ = header.o

all: $(EXE)
$(EXE): $(OBJ)
	$(FC) $(SRC) $(OBJ) -o $(EXE)
%.o: %.f90
	$(FC) -c $< -o $@
