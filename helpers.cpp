#include <iostream>
#include "helpers.h"

using namespace std;

void readlines(vector<string>& lines) {
    string line;
    while (getline(cin, line)) {
        lines.push_back(line);
    }
}
