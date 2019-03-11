EXENAME = main

CXX = clang++
CXXFLAGS = -std=c++11 -g -O0 -Wall -Wextra

all : $(EXENAME)

$(EXENAME): q4.o q4.h Circle.h Circle.o
	$(CXX) $(CXXFLAGS) main.cpp q4.o Circle.o -o $(EXENAME)

q4.o: q4.h q4.cpp
	$(CXX) $(CXXFLAGS) -c q4.cpp

Circle.o: Circle.h Circle.cpp
	$(CXX) $(CXXFLAGS) -c Circle.cpp

.PHONY: clean
clean:
	rm -f *.o $(EXENAME)
