#include <iostream>
#include <vector>
#include <string>
#include "helpers.h"

using namespace std;

int main() {
    vector<string> lines;
    readlines(lines);

    size_t sum = 0;

    string line = lines[0];

    for (size_t i = 0; i < line.length(); i++) {
        if (line[i] == line[(i + line.length() / 2) % line.length()]) {
            sum += line[i] - '0';
        }
    }

    cout << sum;
}
