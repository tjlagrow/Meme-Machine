CXX = g++
CXXFLAGS = -g -std=c++11 -lgd

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $<

all: main 

MAIN_OBJECTS = test.o
main: $(MAIN_OBJECTS)
	$(CXX) -o $@ $(MAIN_OBJECTS) -lgd


clean: 
	$(RM) *.o main 