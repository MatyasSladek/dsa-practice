#ifndef SORTING_ALGORITHMS_HPP
#define SORTING_ALGORITHMS_HPP

#include <vector>
#include <functional>

/**
 * @brief A class that implements various sorting algorithms for integer vectors
 */
class SortingAlgorithms {
public:
    /**
     * @brief Bubble sort implementation
     * Time complexity: O(n²), Space complexity: O(1)
     * @param arr Vector to be sorted
     * @param ascending Sort in ascending order if true, descending if false
     */
    static void bubbleSort(std::vector<int>& arr, bool ascending = true);

    /**
     * @brief Selection sort implementation
     * Time complexity: O(n²), Space complexity: O(1)
     * @param arr Vector to be sorted
     * @param ascending Sort in ascending order if true, descending if false
     */
    static void selectionSort(std::vector<int>& arr, bool ascending = true);

    /**
     * @brief Insertion sort implementation
     * Time complexity: O(n²), Space complexity: O(1)
     * @param arr Vector to be sorted
     * @param ascending Sort in ascending order if true, descending if false
     */
    static void insertionSort(std::vector<int>& arr, bool ascending = true);

    /**
     * @brief Quick sort implementation
     * Time complexity: O(n log n) average, O(n²) worst, Space complexity: O(log n)
     * @param arr Vector to be sorted
     * @param ascending Sort in ascending order if true, descending if false
     */
    static void quickSort(std::vector<int>& arr, bool ascending = true);

    /**
     * @brief Merge sort implementation
     * Time complexity: O(n log n), Space complexity: O(n)
     * @param arr Vector to be sorted
     * @param ascending Sort in ascending order if true, descending if false
     */
    static void mergeSort(std::vector<int>& arr, bool ascending = true);

    /**
     * @brief Heap sort implementation
     * Time complexity: O(n log n), Space complexity: O(1)
     * @param arr Vector to be sorted
     * @param ascending Sort in ascending order if true, descending if false
     */
    static void heapSort(std::vector<int>& arr, bool ascending = true);

    /**
     * @brief Check if a vector is sorted
     * @param arr Vector to check
     * @param ascending Check for ascending order if true, descending if false
     * @return true if sorted, false otherwise
     */
    static bool isSorted(const std::vector<int>& arr, bool ascending = true);

private:
    // Helper functions for quick sort
    static void quickSortHelper(std::vector<int>& arr, int low, int high, bool ascending);
    static int partition(std::vector<int>& arr, int low, int high, bool ascending);

    // Helper functions for merge sort
    static void mergeSortHelper(std::vector<int>& arr, int left, int right, bool ascending);
    static void merge(std::vector<int>& arr, int left, int mid, int right, bool ascending);

    // Helper functions for heap sort
    static void heapify(std::vector<int>& arr, int n, int i, bool ascending);
    static void buildHeap(std::vector<int>& arr, bool ascending);

    // Utility function to swap elements
    static void swap(int& a, int& b);
};

#endif // SORTING_ALGORITHMS_HPP