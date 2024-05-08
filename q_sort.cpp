#include <string>
#include <vector>
#include "sort.h"


void q_sort(std::vector<std::string> &vec, int start, int end) { // NOLINT
    if (end - start <= 1) {
        return;
    }
    int i = start;
    int j = end - 1;
    for (;;) {
        while (i < j && s_comp(vec[i], vec[end - 1]) == 1) {
            ++i;
        }
        while (i < j && s_comp(vec[end - 1], vec[j]) >= 0) {
            --j;
        }
        if (i == j) {
            std::swap(vec[i], vec[end - 1]);
            q_sort(vec, start, i);
            q_sort(vec, i + 1, end);
            return;
        }
        std::swap(vec[i], vec[j]);
    }
}


void q_sort(std::vector<std::string> &vec) {
    return q_sort(vec, 0, static_cast<int>(vec.size()));
}