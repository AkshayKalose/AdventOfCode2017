#include <iostream>
#include <set>
#include <vector>
#include <string>
#include "helpers.h"

using namespace std;

int main() {
    vector<string> lines;
    readlines(lines);

    size_t count = 0;

    for (const string& line : lines) {
        set<vector<int>> used_char_counts;
        vector<string> words;
        readvalues(line, words);
        bool char_counts_unique = true;
        for (const string& word : words) {
            vector<int> char_counts(256);
            for (const char c : word) {
                char_counts[c]++;
            }
            if (!used_char_counts.insert(char_counts).second) {
                char_counts_unique = false;
                break;
            }
        }
        if (char_counts_unique) count++;
    }

    cout << count;
}
