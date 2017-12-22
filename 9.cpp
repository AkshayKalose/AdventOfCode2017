#include <iostream>
#include <vector>
#include <string>
#include "helpers.h"

using namespace std;

int main() {
    vector<string> lines;
    readlines(lines);

    string& stream = lines[0];

    size_t pos = 0;
    size_t stack = 0;
    size_t score = 0;
    bool garbage = false;

    while (pos < stream.length()) {
        if (!garbage) {
            if (stream[pos] == '{') {
                score += ++stack;
            } else if (stream[pos] == '}') {
                stack--;
            } else if (stream[pos] == '<') {
                garbage = true;
            }
        } else {
            if (stream[pos] == '>') {
                garbage = false;
            } else if (stream[pos] == '!') {
                pos++;
            }
        }

        pos++;
    }

    cout << score;
}
