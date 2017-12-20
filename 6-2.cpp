#include <iostream>
#include <map>
#include <limits>
#include <vector>
#include <string>
#include "helpers.h"

using namespace std;

size_t max_index(const vector<int>& banks) {
    size_t index = 0;
    int max = numeric_limits<int>::min();
    for (size_t i = 0; i < banks.size(); i++) {
        if (banks[i] > max) {
            max = banks[i];
            index = i;
        }
    }
    return index;
}

void redistribute(vector<int>& banks) {
    size_t index = max_index(banks);
    int blocks = banks[index];
    banks[index] = 0;
    while (blocks > 0) {
        index = (index + 1) % banks.size();
        banks[index]++;
        blocks--;
    }
}

int main() {
    vector<string> lines;
    readlines(lines);

    map<vector<int>, int> bank_configurations;

    vector<int> banks;
    readvalues(lines[0], banks);

    size_t cycles = 0;

    auto pair = bank_configurations.insert(make_pair(banks, cycles));

    while (pair.second) {
        redistribute(banks);
        pair = bank_configurations.insert(make_pair(banks, ++cycles));
    }

    cout << cycles - pair.first->second;
}
