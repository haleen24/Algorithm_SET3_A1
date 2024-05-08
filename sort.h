#pragma once

#include <string>
#include <vector>
#include <exception>

#include "Sorter.h"
#include "StringGenerator.h"

inline int default_s_comp(const std::string &s1, const std::string &s2) {
    return (s1 > s2 ? -1 : s1 != s2);
}

inline int default_c_comp(const char &c1, const char &c2) {
    return (c1 > c2 ? -1 : c1 != c2);
}

inline int (*s_comp)(const std::string &, const std::string &) = default_s_comp;

inline int (*c_comp)(const char &, const char &) = default_c_comp;

inline LCP (*lcp_comp)(const std::string &, const std::string &, int);

void q_sort(std::vector<std::string> &, int s, int e);

void q_sort(std::vector<std::string> &);

void merge_sort(std::vector<std::string> &);

void generate_data(int, const std::string &);

void test_default_sort(const std::string &);

void test_upgraded_sort(const std::string &);

void q_sort_string(std::vector<std::string> &, int s, int e, int c);

void q_sort_string(std::vector<std::string> &);

void merge_sort_string(std::vector<std::string> &);

void radix_sort_string(std::vector<std::string> &);

void radix_sort_switched(std::vector<std::string> &);