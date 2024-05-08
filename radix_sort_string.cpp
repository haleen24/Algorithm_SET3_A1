#include "sort.h"
#include <unordered_map>

#define TRUE_DICT_SIZE  128

std::unordered_map<char, int> dictionary = {
        {'a', 97},
        {'b', 98},
        {'c', 99},
        {'d', 100},
        {'e', 101},
        {'f', 102},
        {'g', 103},
        {'h', 104},
        {'i', 105},
        {'j', 106},
        {'k', 107},
        {'l', 108},
        {'m', 109},
        {'n', 110},
        {'o', 111},
        {'p', 112},
        {'q', 113},
        {'r', 114},
        {'s', 115},
        {'t', 116},
        {'u', 117},
        {'v', 118},
        {'w', 119},
        {'x', 120},
        {'y', 121},
        {'z', 122},
        {'A', 65},
        {'B', 66},
        {'C', 67},
        {'D', 68},
        {'E', 69},
        {'F', 70},
        {'G', 71},
        {'H', 72},
        {'I', 73},
        {'J', 74},
        {'K', 75},
        {'L', 76},
        {'M', 77},
        {'N', 78},
        {'O', 79},
        {'P', 80},
        {'Q', 81},
        {'R', 82},
        {'S', 83},
        {'T', 84},
        {'U', 85},
        {'V', 86},
        {'W', 87},
        {'X', 88},
        {'Y', 89},
        {'Z', 90},
        {'0', 48},
        {'1', 49},
        {'2', 50},
        {'3', 51},
        {'4', 52},
        {'5', 53},
        {'6', 54},
        {'7', 55},
        {'8', 56},
        {'9', 57},
        {'!', 33},
        {'@', 64},
        {'#', 35},
        {'%', 37},
        {':', 58},
        {';', 59},
        {'^', 94},
        {'&', 38},
        {'*', 42},
        {'(', 40},
        {')', 41},
        {'-', 45}
};

std::vector<std::vector<std::string>> counting_sort(std::vector<std::string> &vec, int c) {
    if (vec.empty()) {
        return {};
    }
    std::vector<std::vector<std::string>> result{TRUE_DICT_SIZE};
    for (auto &item: vec) {
        if (c >= item.size()) {
            continue;
        }
        result[dictionary[item[c]]].push_back(item);
    }
    return result;
}


std::vector<std::string> basic_msd_radix_sort_string(std::vector<std::string> &vec, int l) { //NOLINT
    std::vector<std::string> results;
    results.reserve(vec.size());
    for (auto &item: vec) {
        if (l < item.size()) {
            continue;
        }
        results.push_back(item);
    }
    auto &&counted = counting_sort(vec, l);
    for (int i = 0; i < dictionary.size(); ++i) {
        if (counted[i].empty()) {
            continue;
        }
        auto &&tmp = basic_msd_radix_sort_string(counted[i], l + 1);
        results.insert(
                results.end(), std::make_move_iterator(tmp.begin()), std::make_move_iterator(tmp.end()));
    }
    return results;
}


void radix_sort_string(std::vector<std::string> &vec) {
    vec = basic_msd_radix_sort_string(vec, 0);
}


std::vector<std::string> switched_msd_radix_sort_string(std::vector<std::string> &vec, int l) { // NOLINT
    if (vec.size() < dictionary.size()) {
        q_sort_string(vec, 0, static_cast<int>(vec.size()), l);
        return vec;
    }
    std::vector<std::string> results{};
    results.reserve(vec.size());
    for (const auto &item: vec) {
        if (l < item.size()) {
            continue;
        }
        results.push_back(item);
    }
    auto counted = counting_sort(vec, l);
    for (int i = 0; i < dictionary.size(); ++i) {
        if (counted[i].empty()) {
            continue;
        }
        auto &&tmp = switched_msd_radix_sort_string(counted[i], l + 1);
        results.insert(
                results.end(), std::make_move_iterator(tmp.begin()), std::make_move_iterator(tmp.end()));
    }
    return results;
}


void radix_sort_switched(std::vector<std::string> &vec) {
    vec = switched_msd_radix_sort_string(vec, 0);
}