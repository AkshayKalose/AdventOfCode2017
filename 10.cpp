#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "helpers.h"

using namespace std;

const size_t LIST_SIZE = 256;

void swap_values(size_t list[], size_t index, size_t length) {
    for (size_t i = 0; i < length / 2; i++) {
        size_t wrapped_beginning_index = (index + i) % LIST_SIZE;
        size_t wrapped_ending_index = (index + length - 1 - i) % LIST_SIZE;
        size_t temp = list[wrapped_beginning_index];
        list[wrapped_beginning_index] = list[wrapped_ending_index];
        list[wrapped_ending_index] = temp;
    }
}

int main() {
    vector<string> lines;
    readlines(lines);

    replace(lines[0].begin(), lines[0].end(), ',', ' ');

    vector<size_t> swap_sizes;
    readvalues(lines[0], swap_sizes);

    size_t list[LIST_SIZE];

    for (size_t i = 0; i < LIST_SIZE; i++) {
        list[i] = i;
    }

    size_t skip_size = 0;
    size_t index = 0;

    for (const size_t swap_size : swap_sizes) {
        swap_values(list, index, swap_size);
        index += swap_size + skip_size++;
        index %= LIST_SIZE;
    }

    cout << list[0] * list[1];
}
