#include <chrono>

#include "Sorter.h"

void Sorter::set_sort(void (*func)(std::vector<std::string> &)) {
    _sort = func;
}

void
Sorter::set_sort(void (*func)(std::vector<std::string> &), int(**comp)(const std::string &, const std::string &)) {
    *comp = s_comparator;
    _sort = func;
}

void Sorter::set_sort(void (*func )(std::vector<std::string> &), int (**comp)(const char &, const char &)) {
    *comp = c_comparator;
    _sort = func;
}


void Sorter::set_sort(void (*func)(std::vector<std::string> &),
                      LCP (**comp)(const std::string &, const std::string &, int)) {
    *comp = lcp_comparator;
    _sort = func;
}

Sorter::SortLog Sorter::sort(std::vector<std::string> vec) {
    number_of_comparisons = 0;
    auto start = std::chrono::steady_clock::now();
    _sort(vec);
    auto end = std::chrono::steady_clock::now();
    std::chrono::microseconds result_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    return SortLog{
            .time = result_ms,
            .number_of_comparisons = number_of_comparisons,
            .is_sorted = std::is_sorted(vec.begin(), vec.end())
    };
}

int Sorter::c_comparator(const char &c1, const char &c2) {
    ++number_of_comparisons;
    return (c1 > c2 ? -1 : c1 != c2);
}

int Sorter::s_comparator(const std::string &s1, const std::string &s2) {
    size_t i = 0;
    size_t size = std::min(s1.size(), s2.size());
    for (; i < size; ++i) {
        int res = c_comparator(s1[i], s2[i]);
        if (res != 0) {
            return res;
        }
    }
    return (s1.size() > s2.size() ? -1 : s1.size() != s2.size());
}


std::ostream &operator<<(std::ostream &os, const Sorter::SortLog &log) {
    return os << "[time: " << log.time << ", number_of_comparisons: " << log.number_of_comparisons << ", is_sorted: "
              << (log.is_sorted ? "true" : "false") << ']';
}

LCP Sorter::lcp_comparator(const std::string &s1, const std::string &s2, int k) {
    for (int i = k; i < std::min(s1.size(), s2.size()); ++i) {
        int res = c_comparator(s1[i], s2[i]);
        if (res == 0) {
            continue;
        } else {
            return LCP{
                    .pref = i,
                    .sign = res
            };
        }
    }
    return LCP{
            .pref = static_cast<int>(std::min(s1.size(), s2.size())),
            .sign = (s1.size() > s2.size() ? -1 : s1.size() != s2.size())
    };
}





