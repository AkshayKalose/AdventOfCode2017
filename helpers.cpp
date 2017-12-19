#include <iostream>
#include <sstream>
#include "helpers.h"

using namespace std;

void readlines(vector<string>& lines) {
    string line;
    while (getline(cin, line)) {
        lines.push_back(line);
    }
}

void readvalues(const string& line, vector<int>& values) {
    istringstream stream(line);
    int value;
    while (stream >> value) {
        values.push_back(value);
    }
}
