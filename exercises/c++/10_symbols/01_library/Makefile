EXE = greetings.x
CXX = c++
CXXFLAGS = -I include -std=c++11
SRC = source/hello.cc
OBJ = $(SRC:.cc=.o)

all: $(EXE)

%.o:%.cc
	$(CXX) -c $< -o $@ $(CXXFLAGS)

$(EXE): main.o source/hello.o
	$(CXX) $^ -o $(EXE) -L . -lexercise1

main.o: source/hello.o

source/hello.o: include/hello.h

clean:
	rm -rf source/*.o *.o $(EXE) */*~ *~

.PHONY: clean all
