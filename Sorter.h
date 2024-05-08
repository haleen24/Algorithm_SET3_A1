#pragma once

#include <string>
#include <vector>
#include <ostream>
#include <chrono>

struct LCP {
    int pref = 0;
    int sign = 0;
};

class Sorter {
    void (*_sort)(std::vector<std::string> &){};

    static int c_comparator(const char &, const char &);

    static int s_comparator(const std::string &, const std::string &);

    static LCP lcp_comparator(const std::string &, const std::string &, int= 0);

    inline static size_t number_of_comparisons;

public:

    struct SortLog {
        std::chrono::microseconds time;
        size_t number_of_comparisons;
        bool is_sorted;

        friend std::ostream &operator<<(std::ostream &, const Sorter::SortLog &);
    };

    void set_sort(void (*)(std::vector<std::string> &));

    void set_sort(void (*)(std::vector<std::string> &), int(**)(const std::string &, const std::string &));

    void set_sort(void (*)(std::vector<std::string> &), int(**)(const char &, const char &));

    void set_sort(void (*)(std::vector<std::string> &), LCP (**)(const std::string &, const std::string &, int));

    [[nodiscard]] SortLog sort(std::vector<std::string>);
};