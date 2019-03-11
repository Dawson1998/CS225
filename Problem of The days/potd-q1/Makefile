EXENAME = main

CXX = clang++
CXXFLAGS = -std=c++0x -g -O0 -Wall -Wextra

all : $(EXENAME)

$(EXENAME): q1.cpp hello.cpp
	$(CXX) $(CXXFLAGS) q1.cpp hello.cpp -o $(EXENAME)

.PHONY: clean
clean:
	rm -f $(EXENAME)
