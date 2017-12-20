#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include "helpers.h"

using namespace std;

int main() {
    vector<string> lines;
    readlines(lines);

    size_t count = 0;

    for (const string& line : lines) {
        unordered_set<string> used_words;
        vector<string> words;
        readvalues(line, words);
        bool words_unique = true;
        for (const string& word : words) {
            if (!used_words.insert(word).second) {
                words_unique = false;
                break;
            }
        }
        if (words_unique) count++;
    }

    cout << count;
}
