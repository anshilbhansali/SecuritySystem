

OBJS = pass.o 
EXENAME = pass

CXX = clang++
CXXFLAGS = -Iinclude -std=c++14 -stdlib=libc++ -c -g -O0 -Wall -Wextra
LDFLAGS = -std=c++14 -stdlib=libc++ -lpng -lc++abi

.PHONY: all clean

all : $(EXENAME)

$(EXENAME) : $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o $(EXENAME)

pass.o : pass.c
	$(CXX) $(CXXFLAGS) pass.c

clean :
	rm -f *.o $(EXENAME) 2>/dev/null