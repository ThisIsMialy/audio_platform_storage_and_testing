CXX = g++
CXXFLAGS = -g -Wall -Wextra -Wpedantic
RM = rm
OBJ = track.o doublyList.o

.PHONY : all
all : program

program : main.cpp $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

track.o : track.cpp track.h
	$(CXX) $(CXXFLAGS) -c $<

doublyList.o: doublyList.cpp doublyList.h
	$(CXX) $(CXXFLAGS) -c $<

loadFile.o: loadFile.cpp loadFile.h
	$(CXX) $(CXXFLAGS) -c $<



.PHONY: clean
clean:
	$(RM) *.o
	$(RM) program
