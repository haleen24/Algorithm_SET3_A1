#include <string>
#include <vector>

#include "sort.h"

struct LCPData {
    std::string str;
    int pref;
};

std::vector<LCPData> merge_lcp(std::vector<LCPData> &left, std::vector<LCPData> &right) {
    std::vector<LCPData> res;
    res.reserve(left.size() + right.size());
    size_t i = 0;
    size_t j = 0;
    size_t l_size = left.size();
    size_t r_size = right.size();
    while (i < l_size && j < r_size) {
        int k_i = left[i].pref;
        int k_j = right[j].pref;

        if (k_i > k_j) {
            res.push_back(left[i]);
            ++i;
        } else if (k_i < k_j) {
            res.push_back(right[j]);
            ++j;
        } else {
            auto lcp_data = lcp_comp(left[i].str, right[j].str, k_i);
            if (lcp_data.sign == 1) {
                res.push_back(left[i]);
                ++i;
                right[j].pref = lcp_data.pref;
            } else {
                res.push_back(right[j]);
                ++j;
                left[i].pref = lcp_data.pref;
            }
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

[[nodiscard]] std::vector<LCPData> merge_sort_string(std::vector<std::string> &vec, int start, int end) { // NOLINT
    if (end - start <= 0) {
        return {};
    } else if (end - start == 1) {
        return {LCPData{
                .str = vec[start],
                .pref =0
        }
        };
    }

    int middle = (start + end) / 2;

    auto left = merge_sort_string(vec, start, middle);
    auto right = merge_sort_string(vec, middle, end);
    return
            merge_lcp(left, right
            );
}

void merge_sort_string(std::vector<std::string> &vec) {

    auto res = merge_sort_string(vec, 0, static_cast<int>(vec.size()));
    for (int i = 0; i < vec.size(); ++i) {
        vec[i] = res[i].str;
    }
}