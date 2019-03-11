EXENAME = main
OBJS = main.o Node.o Memory.o MemoryGiven.o

CXX = clang++
CXXFLAGS = -std=c++0x -c -g -O0 -Wall -Wextra
LD = clang++
LDFLAGS = -std=c++0x

all: $(EXENAME)

$(EXENAME): $(OBJS)
	$(LD) $^ $(LDFLAGS) -o $@

main.o: main.cpp
	$(CXX) $< $(CXXFLAGS)

Node.o: Node.cpp
	$(CXX) $< $(CXXFLAGS)

Memory.o: Memory.cpp
	$(CXX) $< $(CXXFLAGS)

MemoryGiven.o: MemoryGiven.cpp
	$(CXX) $< $(CXXFLAGS)

clean:
	-rm -f *.o $(EXENAME)
