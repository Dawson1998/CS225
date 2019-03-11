# Executable names:
EXE = stickers
TEST = test

# Add all object files needed for compiling:
EXE_OBJ = main.o
OBJS = Image.o StickerSheet.o main.o

# Generated files
CLEAN_RM = out.png

# Use the cs225 makefile template:
include cs225/make/cs225.mk

# MP-specific target
TMP_OBJ := $(OBJS)
OBJS = $(filter-out $(EXE_OBJ), $(TMP_OBJ))
OBJS += part1.o

testimage: $(patsubst %.o, $(OBJS_DIR)/%.o, $(OBJS))
	$(LD) $^ $(LDFLAGS) -o $@
