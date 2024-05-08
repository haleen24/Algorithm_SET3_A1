#include <string>
#include <vector>

#include "sort.h"

std::vector<std::string> merge(std::vector<std::string> &left, std::vector<std::string> &right) {
    std::vector<std::string> res;
    res.reserve(left.size() + right.size());
    size_t i = 0;
    size_t j = 0;
    size_t l_size = left.size();
    size_t r_size = right.size();
    while (i < l_size && j < r_size) {
        if (s_comp(left[i], right[j]) == 1) {
            res.push_back(left[i]);
            ++i;
        } else {
            res.push_back(right[j]);
            ++j;
        }
    }
    while (i < l_size) {
        res.push_back(left[i]);
        ++i;
    }
    while (j < r_size) {
        res.push_back(right[j]);
        ++j;
    }
    return res;
}

[[nodiscard]] std::vector<std::string> merge_sort(std::vector<std::string> &vec, int start, int end) { // NOLINT
    if (end - start <= 0) {
        return {};
    } else if (end - start == 1) {
        return {vec[start]};
    }
    int middle = (start + end) / 2;

    std::vector<std::string> left = merge_sort(vec, start, middle);
    std::vector<std::string> right = merge_sort(vec, middle, end);
    return merge(left, right);
}

void merge_sort(std::vector<std::string> &vec) {
    vec = merge_sort(vec, 0, static_cast<int>(vec.size()));
}