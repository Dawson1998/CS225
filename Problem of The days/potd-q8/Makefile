EXENAME = main

CXX = clang++
CXXFLAGS = -std=c++0x -g -O0 -Wall -Wextra

all: $(EXENAME)

$(EXENAME): Piece.cpp Piece.h Queen.cpp Queen.h main.cpp
	$(CXX) $(CXXFLAGS) main.cpp Piece.cpp Queen.cpp -o main

.PHONY: clean
clean:
	rm -f -r *.o *.dSYM main
