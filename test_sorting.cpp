#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "SortingAlgorithms.hpp"
#include <vector>
#include <algorithm>
#include <random>

class SortingTestFixture {
public:
    std::vector<int> empty;
    std::vector<int> single = {42};
    std::vector<int> sorted_asc = {1, 2, 3, 4, 5};
    std::vector<int> sorted_desc = {5, 4, 3, 2, 1};
    std::vector<int> unsorted = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    std::vector<int> duplicates = {5, 2, 8, 2, 9, 1, 5, 5};
    std::vector<int> negatives = {-3, -1, -4, -1, -5, 0, 2, 6, -2};
    std::vector<int> large_random;

    SortingTestFixture() {
        // Generate large random vector for performance testing
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(-1000, 1000);
        
        large_random.reserve(1000);
        for (int i = 0; i < 1000; ++i) {
            large_random.push_back(dis(gen));
        }
    }

    // Helper function to test any sorting algorithm
    template<typename Func>
    void testSortingAlgorithm(Func sortFunc, const std::string& algorithmName) {
        SECTION("Empty vector - " + algorithmName) {
            auto vec = empty;
            sortFunc(vec, true);
            REQUIRE(vec.empty());
            REQUIRE(SortingAlgorithms::isSorted(vec, true));
        }

        SECTION("Single element - " + algorithmName) {
            auto vec = single;
            sortFunc(vec, true);
            REQUIRE(vec.size() == 1);
            REQUIRE(vec[0] == 42);
            REQUIRE(SortingAlgorithms::isSorted(vec, true));
        }

        SECTION("Already sorted ascending - " + algorithmName) {
            auto vec = sorted_asc;
            auto original = vec;
            sortFunc(vec, true);
            REQUIRE(vec == original);
            REQUIRE(SortingAlgorithms::isSorted(vec, true));
        }

        SECTION("Already sorted descending - " + algorithmName) {
            auto vec = sorted_desc;
            sortFunc(vec, true);
            std::vector<int> expected = {1, 2, 3, 4, 5};
            REQUIRE(vec == expected);
            REQUIRE(SortingAlgorithms::isSorted(vec, true));
        }

        SECTION("Unsorted vector ascending - " + algorithmName) {
            auto vec = unsorted;
            sortFunc(vec, true);
            std::vector<int> expected = {1, 1, 2, 3, 3, 4, 5, 5, 6, 9};
            REQUIRE(vec == expected);
            REQUIRE(SortingAlgorithms::isSorted(vec, true));
        }

        SECTION("Unsorted vector descending - " + algorithmName) {
            auto vec = unsorted;
            sortFunc(vec, false);
            std::vector<int> expected = {9, 6, 5, 5, 4, 3, 3, 2, 1, 1};
            REQUIRE(vec == expected);
            REQUIRE(SortingAlgorithms::isSorted(vec, false));
        }

        SECTION("Vector with duplicates - " + algorithmName) {
            auto vec = duplicates;
            sortFunc(vec, true);
            std::vector<int> expected = {1, 2, 2, 5, 5, 5, 8, 9};
            REQUIRE(vec == expected);
            REQUIRE(SortingAlgorithms::isSorted(vec, true));
        }

        SECTION("Vector with negative numbers - " + algorithmName) {
            auto vec = negatives;
            sortFunc(vec, true);
            std::vector<int> expected = {-5, -4, -3, -2, -1, -1, 0, 2, 6};
            REQUIRE(vec == expected);
            REQUIRE(SortingAlgorithms::isSorted(vec, true));
        }

        SECTION("Large random vector - " + algorithmName) {
            auto vec = large_random;
            sortFunc(vec, true);
            REQUIRE(SortingAlgorithms::isSorted(vec, true));
            
            // Verify all elements are still present
            auto original_sorted = large_random;
            std::sort(original_sorted.begin(), original_sorted.end());
            REQUIRE(vec == original_sorted);
        }
    }
};

TEST_CASE_METHOD(SortingTestFixture, "Bubble Sort Tests", "[bubble_sort]") {
    testSortingAlgorithm([](std::vector<int>& v, bool asc) { 
        SortingAlgorithms::bubbleSort(v, asc); 
    }, "Bubble Sort");
}

TEST_CASE_METHOD(SortingTestFixture, "Selection Sort Tests", "[selection_sort]") {
    testSortingAlgorithm([](std::vector<int>& v, bool asc) { 
        SortingAlgorithms::selectionSort(v, asc); 
    }, "Selection Sort");
}

TEST_CASE_METHOD(SortingTestFixture, "Insertion Sort Tests", "[insertion_sort]") {
    testSortingAlgorithm([](std::vector<int>& v, bool asc) { 
        SortingAlgorithms::insertionSort(v, asc); 
    }, "Insertion Sort");
}

TEST_CASE_METHOD(SortingTestFixture, "Quick Sort Tests", "[quick_sort]") {
    testSortingAlgorithm([](std::vector<int>& v, bool asc) { 
        SortingAlgorithms::quickSort(v, asc); 
    }, "Quick Sort");
}

TEST_CASE_METHOD(SortingTestFixture, "Merge Sort Tests", "[merge_sort]") {
    testSortingAlgorithm([](std::vector<int>& v, bool asc) { 
        SortingAlgorithms::mergeSort(v, asc); 
    }, "Merge Sort");
}

TEST_CASE_METHOD(SortingTestFixture, "Heap Sort Tests", "[heap_sort]") {
    testSortingAlgorithm([](std::vector<int>& v, bool asc) { 
        SortingAlgorithms::heapSort(v, asc); 
    }, "Heap Sort");
}

TEST_CASE_METHOD(SortingTestFixture, "isSorted Function Tests", "[is_sorted]") {
    SECTION("Empty vector is sorted") {
        REQUIRE(SortingAlgorithms::isSorted(empty, true));
        REQUIRE(SortingAlgorithms::isSorted(empty, false));
    }

    SECTION("Single element is sorted") {
        REQUIRE(SortingAlgorithms::isSorted(single, true));
        REQUIRE(SortingAlgorithms::isSorted(single, false));
    }

    SECTION("Ascending sorted vector") {
        REQUIRE(SortingAlgorithms::isSorted(sorted_asc, true));
        REQUIRE_FALSE(SortingAlgorithms::isSorted(sorted_asc, false));
    }

    SECTION("Descending sorted vector") {
        REQUIRE_FALSE(SortingAlgorithms::isSorted(sorted_desc, true));
        REQUIRE(SortingAlgorithms::isSorted(sorted_desc, false));
    }

    SECTION("Unsorted vector") {
        REQUIRE_FALSE(SortingAlgorithms::isSorted(unsorted, true));
        REQUIRE_FALSE(SortingAlgorithms::isSorted(unsorted, false));
    }

    SECTION("Vector with equal elements") {
        std::vector<int> equal = {5, 5, 5, 5};
        REQUIRE(SortingAlgorithms::isSorted(equal, true));
        REQUIRE(SortingAlgorithms::isSorted(equal, false));
    }
}

TEST_CASE("Edge Cases", "[edge_cases]") {
    SECTION("Two elements") {
        std::vector<int> two_unsorted = {2, 1};
        std::vector<int> two_sorted = {1, 2};
        
        SortingAlgorithms::bubbleSort(two_unsorted, true);
        REQUIRE(two_unsorted == two_sorted);
    }

    SECTION("All same elements") {
        std::vector<int> same = {7, 7, 7, 7, 7};
        auto original = same;
        
        SortingAlgorithms::quickSort(same, true);
        REQUIRE(same == original);
        REQUIRE(SortingAlgorithms::isSorted(same, true));
    }

    SECTION("Reverse sorted") {
        std::vector<int> reverse = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        
        SortingAlgorithms::mergeSort(reverse, true);
        REQUIRE(reverse == expected);
    }
}

TEST_CASE("Performance Comparison", "[performance]") {
    SECTION("Compare all algorithms on medium dataset") {
        std::vector<int> original(100);
        std::iota(original.rbegin(), original.rend(), 1); // 100, 99, 98, ..., 1
        
        auto test_bubble = original;
        auto test_selection = original;
        auto test_insertion = original;
        auto test_quick = original;
        auto test_merge = original;
        auto test_heap = original;
        
        // All should produce the same result
        SortingAlgorithms::bubbleSort(test_bubble, true);
        SortingAlgorithms::selectionSort(test_selection, true);
        SortingAlgorithms::insertionSort(test_insertion, true);
        SortingAlgorithms::quickSort(test_quick, true);
        SortingAlgorithms::mergeSort(test_merge, true);
        SortingAlgorithms::heapSort(test_heap, true);
        
        // All results should be identical
        REQUIRE(test_bubble == test_selection);
        REQUIRE(test_selection == test_insertion);
        REQUIRE(test_insertion == test_quick);
        REQUIRE(test_quick == test_merge);
        REQUIRE(test_merge == test_heap);
        
        // All should be sorted
        REQUIRE(SortingAlgorithms::isSorted(test_bubble, true));
        REQUIRE(SortingAlgorithms::isSorted(test_selection, true));
        REQUIRE(SortingAlgorithms::isSorted(test_insertion, true));
        REQUIRE(SortingAlgorithms::isSorted(test_quick, true));
        REQUIRE(SortingAlgorithms::isSorted(test_merge, true));
        REQUIRE(SortingAlgorithms::isSorted(test_heap, true));
    }
}

TEST_CASE("Stability Test", "[stability]") {
    // Note: This is a conceptual test since we're dealing with integers
    // In practice, stability would be tested with objects that have additional data
    SECTION("Duplicate elements maintain relative order where applicable") {
        std::vector<int> duplicates_test = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
        std::vector<int> expected_sorted = {1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 9};
        
        // Test that sorting produces correct result regardless of stability
        SortingAlgorithms::mergeSort(duplicates_test, true);
        REQUIRE(duplicates_test == expected_sorted);
        REQUIRE(SortingAlgorithms::isSorted(duplicates_test, true));
    }
}