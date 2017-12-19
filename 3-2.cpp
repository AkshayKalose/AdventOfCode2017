#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include "helpers.h"

using namespace std;

int main() {
    vector<string> lines;
    readlines(lines);

    int number = stoi(lines[0]);

    map<pair<int, int>, int> grid;

    int curr_value = 1;
    grid[pair<int, int>(0, 0)] = curr_value;
    pair<int, int> curr_coordinates(0, 0);
    pair<int, int> delta(1, 0);
    int spiral_index = 0;

    while (curr_value <= number) {
        if (curr_coordinates.first == spiral_index && curr_coordinates.second == -1 * spiral_index) {
            spiral_index++;
        } else if (curr_coordinates.first == spiral_index && curr_coordinates.second == -1 * (spiral_index - 1)) {
            delta.first = 0;
            delta.second = 1;
        } else if (curr_coordinates.first == spiral_index && curr_coordinates.second == spiral_index) {
            delta.first = -1;
            delta.second = 0;
        } else if (curr_coordinates.first == -1 * spiral_index && curr_coordinates.second == spiral_index) {
            delta.first = 0;
            delta.second = -1;
        } else if (curr_coordinates.first == -1 * spiral_index && curr_coordinates.second == -1 * spiral_index) {
            delta.first = 1;
            delta.second = 0;
        }
        curr_coordinates.first += delta.first;
        curr_coordinates.second += delta.second;

        curr_value = 0;
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if (i == 0 && i == j) continue;
                pair<int, int> adjacent_coordinates(curr_coordinates.first + i, curr_coordinates.second + j);
                if (grid.find(adjacent_coordinates) != grid.end()) {
                    curr_value += grid[adjacent_coordinates];
                }
            }
        }
        grid[curr_coordinates] = curr_value;
    }

    cout << curr_value;
}
