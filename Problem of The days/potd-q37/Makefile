EXENAME = main
OBJS = main.o functions.o

CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lpthread -lm

all : $(EXENAME)

$(EXENAME) : $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o : main.cpp functions.cpp
	$(CXX) $(CXXFLAGS) main.cpp

functions.o : functions.cpp
	$(CXX) $(CXXFLAGS) functions.cpp

clean :
	-rm -f *.o $(EXENAME)
