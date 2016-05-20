#Author: Brett A. Blashko
#ID: V00759982
#Created: 05/18/2016
#Modified: 05/18/2016

PROGS = rayTracer
OBJS = RGB.o Image.o Vector3.o rayTracer.o Sphere.o Ray.o
CXX = g++
CXXFLAGS = -g -O
CXXWARNS = -Wall -Werror

all: rayTracer

RGB.o : RGB.cpp
	$(CXX) $(CXXFLAGS) $(CXXWARNS) -c $^

Image.o : Image.cpp
	$(CXX) $(CXXFLAGS) $(CXXWARNS) -c $^

Vector3.o : Vector3.cpp
	$(CXX) $(CXXFLAGS) $(CXXWARNS) -c $^

Sphere.o : Sphere.cpp
	$(CXX) $(CXXFLAGS) $(CXXWARNS) -c $^

rayTracer.o : rayTracer.cpp
	$(CXX) $(CXXFLAGS) $(CXXWARNS) -c $^

Ray.o : Ray.cpp
	$(CXX) $(CXXFLAGS) $(CXXWARNS) -c $^

rayTracer : $(OBJS)
	$(CXX) $(CXXFLAGS) $(CXXWARNS) -o $@ $?

clean:
	rm -f $(OBJS) $(PROGS)
