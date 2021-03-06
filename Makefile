CXX = g++
CXXFLAGS = -Wall -g

PROGRAMS = 1.cpp 1-2.cpp 2.cpp 2-2.cpp 3.cpp 3-2.cpp 4.cpp 4-2.cpp 5.cpp 5-2.cpp 6.cpp 6-2.cpp 7.cpp 7-2.cpp \
	8.cpp 8-2.cpp 9.cpp 9-2.cpp 10.cpp 10-2.cpp
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

6: 6.o helpers.o
	$(CXX) $(CXXFLAGS) -o $@ $^

6-2: 6-2.o helpers.o
	$(CXX) $(CXXFLAGS) -o $@ $^

7: 7.o helpers.o
	$(CXX) $(CXXFLAGS) -o $@ $^

7-2: 7-2.o helpers.o
	$(CXX) $(CXXFLAGS) -o $@ $^

8: 8.o helpers.o
	$(CXX) $(CXXFLAGS) -o $@ $^

8-2: 8-2.o helpers.o
	$(CXX) $(CXXFLAGS) -o $@ $^

9: 9.o helpers.o
	$(CXX) $(CXXFLAGS) -o $@ $^

9-2: 9-2.o helpers.o
	$(CXX) $(CXXFLAGS) -o $@ $^

10: 10.o helpers.o
	$(CXX) $(CXXFLAGS) -o $@ $^

10-2: 10-2.o helpers.o
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -f $(TARGETS) $(OBJECTS) core
