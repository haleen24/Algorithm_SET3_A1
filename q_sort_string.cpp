#include <string>
#include <vector>
#include "sort.h"


void q_sort_string(std::vector<std::string> &vec, int start, int end, int c) { // NOLINT
    if (end - start <= 1) {
        return;
    }
    int i = start;
    int j = end - 1;
    char pivot_char;
    char cur_char;
    size_t pivot_size = vec[end - 1].size();

    if (c >= pivot_size) {
        while (vec[i].size() < c) {
            ++i;
        }
        std::swap(vec[end - 1], vec[i]);
        return q_sort_string(vec, i + 1, end, c + 1);
    }
    pivot_char = vec[j][c];
    int last_i = INT_MAX;
    int last_j = INT_MIN;
    for (;;) {
        while (i < j) {
            if (c >= vec[i].size()) {
                ++i;
                continue;
            }
            int comp = c_comp(pivot_char, vec[i][c]);
            if (comp == 0) {
                last_i = std::min(last_i, i);
                ++i;
                continue;
            } else if (comp == -1) {
                last_i = last_i == INT_MAX ? i : last_i;
                std::swap(vec[i], vec[last_i]);
                ++last_i;
            } else {
                break;
            }
            ++i;
        }
        if (j == end - 1 && i != j) {
            --j;
        }
        while (i < j) {
            if (c >= vec[j].size()) {
                break;
            }
            int comp = c_comp(pivot_char, vec[j][c]);
            if (comp == 0) {
                last_j = std::max(last_j, j);
                --j;
                continue;
            } else if (comp == 1) {
                last_j = last_j == INT_MIN ? j : last_j;
                std::swap(vec[j], vec[last_j]);
                --last_j;
            } else {
                break;
            }
            --j;
        }
        if (i == j) {
            std::swap(vec[i], vec[end - 1]);
            last_i = std::min(last_i, i);
            last_j = std::max(last_j, j);
            q_sort_string(vec, start, last_i, c);
            q_sort_string(vec, last_i, last_j + 1, c + 1);
            q_sort_string(vec, last_j + 1, end, c);
            return;
        }
        std::swap(vec[i], vec[j]);
    }
}


void q_sort_string(std::vector<std::string> &vec) {
    return q_sort_string(vec, 0, static_cast<int>(vec.size()), 0);
}