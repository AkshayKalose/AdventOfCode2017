#include <vector>
#include <string>
#include <sstream>

void readlines(std::vector<std::string>& lines);

template <typename T, typename A>
void readvalues(const std::string& line, std::vector<T, A>& values) {
    std::istringstream stream(line);
    T value;
    while (stream >> value) {
        values.push_back(value);
    }
}
