EXE = lab_inheritance
TEST = test

EXE_OBJ = main.o
OBJS = main.o circle.o flower.o line.o rectangle.o shape.o triangle.o truck.o vector2.o

# Additional executables
EXE_VIRTUAL      = test_virtual
EXE_PURE_VIRTUAL = test_pure_virtual
EXE_DESTRUCTOR   = test_destructor
EXE_SLICING      = test_slicing
EXE_CONSTRUCTOR  = test_constructor

# Override "default" rule provided by the Makefile template
all: $(EXE) $(EXE_VIRTUAL) $(EXE_PURE_VIRTUAL) $(EXE_DESTRUCTOR) $(EXE_SLICING) $(EXE_CONSTRUCTOR)

# Remove additional executables during `make clean`
CLEAN_RM = $(EXE_VIRTUAL) $(EXE_PURE_VIRTUAL) $(EXE_DESTRUCTOR) $(EXE_SLICING) $(EXE_CONSTRUCTOR)

# Use the CS 225 Makefile template
include cs225/make/cs225.mk

# Assignment-specific compiler config
# Note that due to how make processes Makefiles, these flags will even apply
# to the targets inside the included Makefile template
CXXFLAGS += -Wno-delete-non-virtual-dtor

# Dependencies for additional executables
OBJS_VIRTUAL      = $(OBJS_DIR)/test_virtual.o $(OBJS_DIR)/shape.o $(OBJS_DIR)/rectangle.o
OBJS_PURE_VIRTUAL = $(OBJS_DIR)/test_pure_virtual.o $(OBJS_DIR)/shape.o $(OBJS_DIR)/rectangle.o $(OBJS_DIR)/circle.o $(OBJS_DIR)/truck.o
OBJS_DESTRUCTOR   = $(OBJS_DIR)/test_destructor.o $(OBJS_DIR)/shape.o $(OBJS_DIR)/triangle.o
OBJS_SLICING      = $(OBJS_DIR)/test_slicing.o $(OBJS_DIR)/shape.o $(OBJS_DIR)/rectangle.o $(OBJS_DIR)/circle.o $(OBJS_DIR)/flower.o $(OBJS_DIR)/triangle.o
OBJS_CONSTRUCTOR  = $(OBJS_DIR)/test_constructor.o $(OBJS_DIR)/shape.o $(OBJS_DIR)/circle.o

OBJS_PROVIDED = $(OBJS_DIR)/cs225/PNG.o $(OBJS_DIR)/cs225/lodepng/lodepng.o $(OBJS_DIR)/cs225/HSLAPixel.o $(OBJS_DIR)/vector2.o $(OBJS_DIR)/line.o

$(EXE_VIRTUAL): $(OBJS_VIRTUAL) $(OBJS_PROVIDED)
	$(LD) $^ $(LDFLAGS) -o $@
$(EXE_PURE_VIRTUAL): $(OBJS_PURE_VIRTUAL) $(OBJS_PROVIDED)
	$(LD) $^ $(LDFLAGS) -o $@
$(EXE_DESTRUCTOR): $(OBJS_DESTRUCTOR) $(OBJS_PROVIDED)
	$(LD) $^ $(LDFLAGS) -o $@
$(EXE_SLICING): $(OBJS_SLICING) $(OBJS_PROVIDED)
	$(LD) $^ $(LDFLAGS) -o $@
$(EXE_CONSTRUCTOR): $(OBJS_CONSTRUCTOR) $(OBJS_PROVIDED)
	$(LD) $^ $(LDFLAGS) -o $@
