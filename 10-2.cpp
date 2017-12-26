#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include "helpers.h"

using namespace std;

const size_t LIST_SIZE = 256;
const size_t DENSE_SIZE = 16;
const size_t XOR_SIZE = LIST_SIZE / DENSE_SIZE;
const char salt[] = {17, 31, 73, 47, 23};
const size_t SALT_SIZE = 5;
const size_t ROUNDS = 64;

void swap_values(size_t list[], size_t index, char length) {
    for (char i = 0; i < length / 2; i++) {
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

    vector<char> swap_sizes;
    for (size_t i = 0; i < lines[0].length(); i++) {
        swap_sizes.push_back(lines[0][i]);
    }

    for (size_t i = 0; i < SALT_SIZE; i++) {
        swap_sizes.push_back(salt[i]);
    }

    size_t list[LIST_SIZE];

    for (size_t i = 0; i < LIST_SIZE; i++) {
        list[i] = i;
    }

    size_t skip_size = 0;
    size_t index = 0;

    for (size_t i = 0; i < ROUNDS; i++) {
        for (const char swap_size : swap_sizes) {
            swap_values(list, index, swap_size);
            index += swap_size + skip_size++;
            index %= LIST_SIZE;
        }
    }

    cout << hex << setfill('0');

    for (size_t i = 0; i < DENSE_SIZE; i++) {
        size_t dense_value = 0;
        for (size_t j = 0; j < XOR_SIZE; j++) {
            dense_value ^= list[XOR_SIZE * i + j];
        }
        cout << setw(2) << dense_value;
    }
}
