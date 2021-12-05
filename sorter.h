#ifndef SORTER_H
#define SORTER_H
/* 
sorting-algorithms.h
Wilson Chen June 2021
Header file containing a bunch of sorting algorithms.
This was intended to be a practice header file, but maybe
I can use it in the future 😳

DISCLAIMER: CAN ONLY ACCEPT ARRAYS/VECTORS
*/

#include <iostream>
#include <functional>   // less
#include <vector>
#include <algorithm>    // vector to array
#include <cassert>

// This should work for most data types and objects, as long as a comparator is defined

// If a comparator is not defined, it will attempt to use 
// "less" from the "functional" library
// "less" syntax: less(item1, item2). Essentially "item1 < item2 ?"

/* USAGE

*/
template <typename T, typename Compare = std::less<T>>
class Sorter {
    private:

    // Vector that holds the input elements
    std::vector<T> container;
    Compare less_comparator;
    // Keeps track if the input container was originally an array
    bool isArray;

    public:

    // CONSTRUCTORS

    Sorter() 
        : isArray(false) {}

    // Array constructors need to know the length of the arrays beforehand

    // Array constructor helper
    std::vector<T> arr_constructor_helper(const T arr[], size_t arr_length) {
        assert(arr != nullptr);
        container.clear();
        std::vector<T> v(arr, arr + arr_length);
        return v;
    }

    // Array constructor (no comparator specified)
    Sorter(const T arr[], size_t arr_length)
        : isArray(true) {
        container = arr_constructor_helper(arr, arr_length);
    }

    // Array constructor (comparator specified)
    Sorter(const T arr[], size_t arr_length, Compare less_in)
        : less_comparator(less_in), isArray(true) {
        container = arr_constructor_helper(arr, arr_length);
    }

    // Vector constructor (no comparator specified)
    Sorter(const std::vector<T> &vec) 
        : container(vec), isArray(false) {}
    
    // Vector constructor (comparator specified)
    Sorter(const std::vector<T> &vec, Compare less_in)
        : container(vec), less_comparator(less_in), isArray(false) {}

    // HELPER FUNCTIONS

    // To return an array, one must return the pointer to the first element in the array
    // Vector to array converter
    // WARNING: USER MUST USE 'delete[]' ON THE DYNAMICALLY ALLOCATED ARRAY
    T *vec_to_arr() {
        T *arr = new T[container.size()];
        std::copy(container.begin(), container.end(), arr);
        return arr;
    }

    // Prints out contents of the sorted vector
    void printContainer() {
        if(container.empty()) {
            std::cout << "This container is empty";
        }
        for(int i = 0; i < (int)container.size(); ++i) {
            std::cout << container[i] << " ";
        }
        std::cout << "\n" << std::endl;
    }

    // SORTING ALGORITHMS
    // Each one will have a version that returns an array and another for vectors
    // Each sorting method will have a helper function to prevent repeated code
    
    // Selection Sort
    // Selection Sort Helper
    void selectionsort_helper() {
        assert((int)container.size() > 0);
        if((int)container.size() == 1) {
            return;
        }
        int smallest_index;
        T temp;
        for(int i = 0; i < (int)container.size(); ++i) {
            smallest_index = i;
            temp = container[i];
            for(int j = i+1; j < (int)container.size(); ++j) {
                if(less_comparator(container[j], container[smallest_index])) {
                    smallest_index = j;
                }
            }
            container[i] = container[smallest_index];
            container[smallest_index] = temp;
        }
    }

    // Selection Sort Array
    T *selectionsort() {

    }

    // Selection Sort Vector


    // Bubble Sort 🤮
    // Bubble Sort helper
    void bubblesort_helper() {
        
    }

    // Bubble Sort Array



    // Bubble Sort Vector


    // Insertion Sort

    // Binary Insertion Sort

    // Merge Sort

    // Quick Sort
};

#endif