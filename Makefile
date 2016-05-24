#Author: Brett A. Blashko
#ID: V00759982
#Created: 05/16/2016
#Modified: 05/23/2016

PROGS = main
OBJS = main.o image.o vector3.o sphere.o plane.o color.o
CXX = g++
CXXFLAGS = -g -O
CXXWARNS = -Wall -Werror

all: main

main.o : main.cpp
	$(CXX) $(CXXFLAGS) $(CXXWARNS) -c $^

image.o : image.cpp
	$(CXX) $(CXXFLAGS) $(CXXWARNS) -c $^

vector3.o : vector3.cpp
	$(CXX) $(CXXFLAGS) $(CXXWARNS) -c $^

sphere.o : sphere.cpp
	$(CXX) $(CXXFLAGS) $(CXXWARNS) -c $^

plane.o : plane.cpp
	$(CXX) $(CXXFLAGS) $(CXXWARNS) -c $^

color.o : color.cpp
	$(CXX) $(CXXFLAGS) $(CXXWARNS) -c $^

main : $(OBJS)
	$(CXX) $(CXXFLAGS) $(CXXWARNS) -o $@ $?
	rm -f $(OBJS)

clean:
	rm -f $(OBJS) $(PROGS) *.bmp
