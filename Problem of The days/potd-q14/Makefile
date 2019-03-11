EXENAME = main
OBJS = Animal.o Pet.o main.o

CXX = clang++
CXXFLAGS = -std=c++0x -c -g -O0 -Wall -Wextra
LD = clang++
LDFLAGS = -std=c++0x

all: $(EXENAME)

$(EXENAME): $(OBJS)
	$(LD) $^ $(LDFLAGS) -o $@

main.o: main.cpp
	$(CXX) $< $(CXXFLAGS)

Animal.o: Animal.cpp Animal.h
	$(CXX) $< $(CXXFLAGS)

Pet.o: Pet.cpp Pet.h
	$(CXX) $< $(CXXFLAGS)

clean :
	-rm -f *.o $(EXENAME)
