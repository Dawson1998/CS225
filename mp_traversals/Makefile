# Executable names:
EXE = traversals
TEST = test

# Add all object files needed for compiling:
EXE_OBJ = main.o
OBJS = main.o Point.o FloodFilledImage.o Animation.o


# mp_traverals specific stuff
# Add all `colorPicker` and `imageTraversal`s:
CPP_FILES += $(wildcard colorPicker/*.cpp)
CPP_FILES += $(wildcard imageTraversal/*.cpp)
OBJS += $(CPP_FILES:.cpp=.o)

# Generated files
CLEAN_RM = pacman-*.png i-rainbow-*.png lantern-rainbow-*.png pacman-*.gif i-rainbow-*.gif lantern-rainbow-*.gif frames

# Use the cs225 makefile template:
include cs225/make/cs225.mk

