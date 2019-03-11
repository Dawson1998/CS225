EXENAME = main

CXX = clang++
CXXFLAGS = -std=c++0x -g -O0 -Wall -Wextra

.PHONY: all
all : $(EXENAME)

$(EXENAME): q2.cpp epoch.cpp epoch.h
	$(CXX) $(CXXFLAGS) q2.cpp epoch.cpp -o $(EXENAME)

.PHONY: clean
clean:
	rm -f $(EXENAME)
