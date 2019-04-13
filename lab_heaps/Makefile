# Executable names:
EXE = testheap
TEST = test

# Add all object files needed for compiling:
EXE_OBJ = main.o
OBJS = main.o  coloredout.o

include cs225/make/cs225.mk

doc: lab_heaps.doxygen $(wildcard *.h) $(wildcard *.cpp)
	-doxygen lab_heaps.doxygen

