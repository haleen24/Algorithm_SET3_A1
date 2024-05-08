#include <iostream>
#include <algorithm>
#include "StringGenerator.h"
#include "Sorter.h"
#include "sort.h"

int main() {
    generate_data(0, "../data/tests/");
    test_default_sort( "../data/");
    test_upgraded_sort( "../data/");
}
