// Testing file for sorter.h
// Maybe consider using EECS 280's unit test framework?
// NOTE: make your own comparator for the tests 

#include "sorter.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Testing constructors
    Sorter<int> sortA;
    cout << "Testing empty constructor\nExpected: \nThis container is empty" << endl;
    sortA.printContainer();

    // Testing array
    int intArr[4] = {2, 9, 16, -3};
    size_t len = sizeof(intArr) / sizeof(intArr[0]);
    Sorter<int> sort_device = Sorter<int>(intArr, len);
    cout << "Testing array\nExpected: \n2 9 16 -3" << endl;
    sort_device.printContainer();

    // Testing vector
    vector<int> intVec = {3,5,7,2};
    sort_device = Sorter<int>(intVec);
    cout << "Testing vector\nExpected: \n3 5 7 2" << endl;
    sort_device.printContainer();

    return 0;
}