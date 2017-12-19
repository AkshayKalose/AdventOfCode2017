CXX = g++
CXXFLAGS = -Wall -g

PROGRAMS = 1.cpp 1-2.cpp
EXTRAS = helpers.cpp
HEADERS = $(EXTRAS:.cpp=.h)
SOURCES = $(PROGRAMS) $(EXTRAS)
OBJECTS = $(SOURCES:.cpp=.o)
TARGETS = $(PROGRAMS:.cpp=)

default: $(TARGETS)

1: 1.o helpers.o
	$(CXX) $(CXXFLAGS) -o $@ $^

1-2: 1-2.o helpers.o
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -f $(TARGETS) $(OBJECTS) core
