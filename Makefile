CXX=g++
CXXFLAGS=-lglut -lGLU -lGL


all: myrender

myrender: myrender.o
	$(CXX) -o myrender myrender.o $(CXXFLAGS)

myrender.o:	myrender.cpp
	$(CXX) -c -g myrender.cpp

clean: 
	rm myrender *.o