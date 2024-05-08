#include "sort.h"
#include <fstream>
#include <iostream>

std::vector<std::string> random{};
std::vector<std::string> backwards{};
std::vector<std::string> almost_sorted{};


void generate_data(int seed, const std::string &path) {
    std::ofstream random_file{path + "random.txt", std::ios::trunc | std::ios::out};
    std::ofstream backward_file{path + "backward.txt", std::ios::trunc | std::ios::out};
    std::ofstream almost_file{path + "almost_sorted.txt", std::ios::trunc | std::ios::out};
    StringGenerator generator{};
    random = generator.get_random(seed);
    for (auto &item: random) {
        random_file << item << '\n';
    }
    backwards = generator.get_sorted_backwards(seed);
    for (auto &item: backwards) {
        backward_file << item << '\n';
    }
    almost_sorted = generator.get_almost_sorted(seed);
    for (auto &item: almost_sorted) {
        almost_file << item << '\n';
    }
    random_file.close();
    backward_file.close();
    almost_file.close();
}


void test_default_sort(const std::string &path) {
    std::vector<std::string> paths = {
            path + "q_sort_random.txt",
            path + "q_sort_backward.txt",
            path + "q_sort_almost_sorted.txt",
            path + "merge_sort_random.txt",
            path + "merge_sort_backward.txt",
            path + "merge_sort_almost_sorted.txt"
    };

    Sorter sorter{};
    std::ofstream q_sort_file;
    std::ofstream merge_sort_file;

    size_t path_id = 0;
    for (auto &&vec: {random, backwards, almost_sorted}) {
        q_sort_file.open(paths[path_id], std::ios::out | std::ios::trunc);
        merge_sort_file.open(paths[path_id + 3], std::ios::out | std::ios::trunc);
        ++path_id;
        std::vector<std::string> slice;
        Sorter::SortLog log{};
        for (size_t i = 100; i <= vec.size(); i += 100) {
            slice = std::vector<std::string>(vec.begin(), vec.begin() + i);
            sorter.set_sort(q_sort, &s_comp);
            log = sorter.sort(slice);
            q_sort_file << log << '\n';
            sorter.set_sort(merge_sort, &s_comp);
            log = sorter.sort(slice);
            merge_sort_file << log << '\n';
        }
        q_sort_file.close();
        merge_sort_file.close();
    }
}

void test_upgraded_sort( const std::string &path) {
    std::vector<std::string> paths = {
            path + "q_sort_string_random.txt",
            path + "q_sort_string_backward.txt",
            path + "q_sort_string_almost_sorted.txt",
            path + "merge_sort_string_random.txt",
            path + "merge_sort_string_  backward.txt",
            path + "merge_sort_string_almost_sorted.txt",
            path + "msd_radix_sort_random.txt",
            path + "msd_radix_sort_backward.txt",
            path + "msd_radix_sort_almost_sorted.txt",
            path + "msd_radix_sort_switched_random.txt",
            path + "msd_radix_sort_switched_backward.txt",
            path + "msd_radix_sort_switched_almost_sorted.txt"
    };
    Sorter sorter{};
    std::ofstream q_sort_file;
    std::ofstream merge_sort_file;
    std::ofstream basic_radix_sort_file;
    std::ofstream upgraded_radix_sort_file;

    size_t path_id = 0;
    for (auto &&vec: {random, backwards, almost_sorted}) {
        q_sort_file.open(paths[path_id], std::ios::out | std::ios::trunc);
        merge_sort_file.open(paths[path_id + 3], std::ios::out | std::ios::trunc);
        basic_radix_sort_file.open(paths[path_id + 6], std::ios::out | std::ios::trunc);
        upgraded_radix_sort_file.open(paths[path_id + 9], std::ios::out | std::ios::trunc);
        ++path_id;
        std::vector<std::string> slice;
        Sorter::SortLog log{};
        for (size_t i = 100; i <= vec.size(); i += 100) {
            slice = std::vector<std::string>(vec.begin(), vec.begin() + i);
            sorter.set_sort(q_sort_string, &c_comp);
            log = sorter.sort(slice);
            q_sort_file << log << '\n';
            sorter.set_sort(merge_sort_string, &lcp_comp);
            log = sorter.sort(slice);
            merge_sort_file << log << '\n';
            sorter.set_sort(radix_sort_string);
            log = sorter.sort(slice);
            basic_radix_sort_file << log << '\n';
            sorter.set_sort(radix_sort_switched, &c_comp);
            log = sorter.sort(slice);
            upgraded_radix_sort_file << log << '\n';
        }
        q_sort_file.close();
        merge_sort_file.close();
        basic_radix_sort_file.close();
        upgraded_radix_sort_file.close();
    }
}

