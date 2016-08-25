COMPILER = gfortran
SOURCE = main.f90
EXECUTABLE = main
OBJECTS = header.o

all: $(EXECUTABLE)
$(EXE): $(OBJECTS)
	$(COMPILER) $(SOURCE) $(OBJECTS) -o $(EXECUTABLE)
%.o: %.f90
	$(COMPILER) -c $< -o $@
