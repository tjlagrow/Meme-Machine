CXX = g++
CXXFLAGS = -g -std=c++11 -lgd

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $<

all: main 

MAIN_OBJECTS = imageops.o encrypt.o
main: $(MAIN_OBJECTS)
	$(CXX) -o $@ $(MAIN_OBJECTS)


clean: 
	$(RM) *.o main 
