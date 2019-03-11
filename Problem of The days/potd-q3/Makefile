EXENAME = main

CXX = clang++
CXXFLAGS = -std=c++11 -g -O0 -Wall -Wextra

all : $(EXENAME)

$(EXENAME): main.cpp Pet.h Pet.o
	$(CXX) $(CXXFLAGS) main.cpp Pet.o -o $(EXENAME)

Pet.o: Pet.h Pet.cpp
	$(CXX) $(CXXFLAGS) -c Pet.cpp

.PHONY: clean
clean:
	rm -f $(EXENAME)
