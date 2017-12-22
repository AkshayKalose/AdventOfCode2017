#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <regex>
#include <vector>
#include <string>
#include <limits>
#include "helpers.h"

using namespace std;

bool compare(unordered_map<string, int>& regs, string reg, string op, string val) {
    int value = stoi(val);
    int register_value = regs[reg];
    bool result;
    if (op == "==") {
        result = register_value == value;
    } else if (op == "!=") {
        result = register_value != value;
    } else if (op == "<") {
        result = register_value < value;
    } else if (op == ">") {
        result = register_value > value;
    } else if (op == "<=") {
        result = register_value <= value;
    } else {
        // op == ">="
        result = register_value >= value;
    }
    return result;
}

int execute_instruction(unordered_map<string, int>& regs, const string& line) {
    smatch sm;
    regex_match(line, sm, regex("(\\w*) (inc|dec) (-?\\d*) if (\\w*) ([!<>=]*) (-?\\d*)"));

    if (compare(regs, sm[4], sm[5], sm[6])) {
        int value = stoi(sm[3]);
        if (sm[2] == "inc") {
            regs[sm[1]] += value;
        } else {
            regs[sm[1]] -= value;
        }
    }
    return regs[sm[1]];
}

int main() {
    vector<string> lines;
    readlines(lines);

    unordered_map<string, int> regs;

    int max = numeric_limits<int>::min();

    for (const string& line : lines) {
        int val = execute_instruction(regs, line);
        if (val > max) {
            max = val;
        }
    }

    cout << max_element(regs.begin(), regs.end(),
                        [](const pair<string, int>& l, const pair<string, int>& r) -> bool {
                            return l.second < r.second;
                        })->second << endl;

    cout << max;
}
