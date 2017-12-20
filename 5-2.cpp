#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "helpers.h"

using namespace std;

int main() {
    vector<string> lines;
    readlines(lines);

    vector<int> instructions;
    transform(lines.begin(), lines.end(), back_inserter(instructions),
                [](const string& line) { return stoi(line); });

    size_t steps = 0;
    size_t index = 0;

    while (index < instructions.size()) {
        int prev_index = index;
        index += instructions[index];
        if (instructions[prev_index] >= 3) {
            instructions[prev_index]--;
        } else {
            instructions[prev_index]++;
        }
        steps++;
    }

    cout << steps;
}
