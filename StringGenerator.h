#pragma once

#include <vector>

class StringGenerator {
    size_t max_size = 3000;
    size_t min_len = 10;
    size_t max_len = 200;
public:
    explicit StringGenerator(size_t amount_of_data = 3000, size_t min_string_len = 10, size_t max_string_len = 200);


    [[nodiscard]] std::vector<std::string> get_random(int) const;


    [[nodiscard]] std::vector<std::string> get_sorted(int) const;

    [[nodiscard]] std::vector<std::string> get_sorted_backwards(int) const;

    [[nodiscard]] std::vector<std::string> get_almost_sorted(int) const;

};

