CXX = g++
CXXFLAGS = -Wall -g

PROGRAMS = 1.cpp 1-2.cpp 2.cpp 2-2.cpp 3.cpp 3-2.cpp 4.cpp 4-2.cpp 5.cpp 5-2.cpp
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

2: 2.o helpers.o
	$(CXX) $(CXXFLAGS) -o $@ $^

2-2: 2-2.o helpers.o
	$(CXX) $(CXXFLAGS) -o $@ $^

3: 3.o helpers.o
	$(CXX) $(CXXFLAGS) -o $@ $^

3-2: 3-2.o helpers.o
	$(CXX) $(CXXFLAGS) -o $@ $^

4: 4.o helpers.o
	$(CXX) $(CXXFLAGS) -o $@ $^

4-2: 4-2.o helpers.o
	$(CXX) $(CXXFLAGS) -o $@ $^

5: 5.o helpers.o
	$(CXX) $(CXXFLAGS) -o $@ $^

5-2: 5-2.o helpers.o
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -f $(TARGETS) $(OBJECTS) core
