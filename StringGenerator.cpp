#include <random>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include "StringGenerator.h"


const std::vector<char> symbols{
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u',
        'v', 'w', 'x', 'y', 'z',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U',
        'V', 'W', 'X', 'Y', 'Z',
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        '!', '@', '#', '%', ':', ';', '^', '&', '*', '(', ')', '-'
};

std::vector<std::string> StringGenerator::get_random(int seed) const {

    srand(seed);

    std::mt19937 gen(seed);
    std::uniform_int_distribution<> len_distrib(static_cast<int>(min_len), static_cast<int>(max_len));
    std::uniform_int_distribution<> char_distrib(0ul, static_cast<int>(symbols.size()) - 1);

    std::vector<std::string> result(max_size, std::string());

    char *buffer;
    for (size_t i = 0; i < max_size; ++i) {
        size_t len = len_distrib(gen);
        buffer = new char[len];
        for (size_t j = 0; j < len; ++j) {
            char symbol = symbols[char_distrib(gen)];
            buffer[j] = symbol;
        }
        result[i] = std::string(buffer, len);
        delete buffer;
    }
    return result;
}


std::vector<std::string> StringGenerator::get_sorted(int seed) const {
    std::vector<std::string> result = get_random(seed);
    std::sort(result.begin(), result.end(), [](std::string a, std::string b) {
        return a < b;
    });
    return result;
}

std::vector<std::string> StringGenerator::get_sorted_backwards(int seed) const {
    std::vector<std::string> result = get_sorted(seed);
    std::reverse(result.begin(), result.end());
    return result;
}


std::vector<std::string> StringGenerator::get_almost_sorted(int seed) const {
    std::vector<std::string> result = get_sorted(seed);
    const size_t step = 10;
    for (size_t i = 0; i < result.size(); i += step) {
        std::swap(result[i - 1], result[i]);
    }
    return result;
}

StringGenerator::StringGenerator(size_t amount_of_data, size_t min_string_len, size_t max_string_len) : max_size(
        amount_of_data), min_len(min_string_len), max_len(max_string_len) {
}

