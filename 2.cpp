#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "helpers.h"

using namespace std;

int largest_difference(const vector<int>& values) {
    int max = numeric_limits<int>::min();
    int min = numeric_limits<int>::max();
    for (size_t i = 0; i < values.size(); i++) {
        if (values[i] > max) max = values[i];
        if (values[i] < min) min = values[i];
    }
    return max - min;
}

int main() {
    vector<string> lines;
    readlines(lines);

    size_t sum = 0;

    for (const string& line : lines) {
        vector<int> values;
        readvalues(line, values);
        sum += largest_difference(values);
    }

    cout << sum;
}
