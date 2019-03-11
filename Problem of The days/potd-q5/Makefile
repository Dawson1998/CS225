EXENAME = main

CXX = clang++
CXXFLAGS = -std=c++11 -g -O0 -Wall -Wextra

all : $(EXENAME)

$(EXENAME): main.cpp Food.h Food.o q5.o q5.h
	$(CXX) $(CXXFLAGS) main.cpp Food.o q5.o -o $(EXENAME)

Food.o: Food.h Food.cpp
	$(CXX) $(CXXFLAGS) -c Food.cpp

q5.o: q5.h q5.cpp
	$(CXX) $(CXXFLAGS) -c q5.cpp

.PHONY: clean
clean:
	rm -f *.o $(EXENAME)
