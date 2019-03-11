EXENAME = main

CXX = clang++
CXXFLAGS = -std=c++11 -g -O0 -Wall -Wextra

all : $(EXENAME)

$(EXENAME): Base.o Derived.o main.cpp
	$(CXX) $(CXXFLAGS) main.cpp Base.o Derived.o -o $(EXENAME)

Base.o: Base.cpp Base.h
	$(CXX) $(CXXFLAGS) -c Base.cpp

Derived.o: Derived.cpp Base.h Derived.h
	$(CXX) $(CXXFLAGS) -c Derived.cpp

.PHONY: clean
clean:
	rm -rf *.o *.dSYM $(EXENAME)
