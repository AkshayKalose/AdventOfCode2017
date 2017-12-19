#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "helpers.h"

using namespace std;

int main() {
    vector<string> lines;
    readlines(lines);

    int number = stoi(lines[0]);
    int sqrt_bottom_right_corner = ceil(sqrt(number));
    if (sqrt_bottom_right_corner % 2 == 0) sqrt_bottom_right_corner++;
    int bottom_right_corner = round(pow(sqrt_bottom_right_corner, 2));

    int edge_length = (bottom_right_corner - round(pow(sqrt_bottom_right_corner - 2, 2))) / 4 + 1;

    int spiral_index = floor(sqrt_bottom_right_corner / 2);

    if (number == bottom_right_corner) {
        cout << spiral_index * 2;
        return 0;
    }

    for (size_t i = 0; i < 4; i++) {
        int current_corner = bottom_right_corner - (edge_length - 1) * (i + 1);
        if (number > current_corner) {
            cout << spiral_index + abs(current_corner + edge_length / 2 - number);
            break;
        }
    }
}
