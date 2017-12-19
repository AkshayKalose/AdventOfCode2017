#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "helpers.h"

using namespace std;

void max_min(int& max, int& min) {
    if (max < min) {
        int temp = max;
        max = min;
        min = temp;
    }
}

int natural_quotient(const vector<int>& values) {
    for (size_t i = 0; i < values.size(); i++) {
        for (size_t j = i + 1; j < values.size(); j++) {
            int max = values[i];
            int min = values[j];
            max_min(max, min);
            if (max % min == 0) return max / min;
        }
    }
    return 0;
}

int main() {
    vector<string> lines;
    readlines(lines);

    size_t sum = 0;

    for (const string& line : lines) {
        vector<int> values;
        readvalues(line, values);
        sum += natural_quotient(values);
    }

    cout << sum;
}
