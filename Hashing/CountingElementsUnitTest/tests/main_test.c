#include "hashmap.h"
#include "dbg.h"
#include "countelem.h"

#include <stdio.h>
#include <assert.h>


void test_insert_and_find(){
    Hashitem dict[MAX_SIZE] = {-1};
    //initDict(dict);

    // Test inserting and finding a single value
    insert(dict, 100, 200);
    assert(find(dict, 100) == 200); // Verify that the value can be found

    // Test inserting
    assert(find(dict, 999) == -1);
}

void test_countElements(){
    int arr[] = {1, 2, 3};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    // Should return 2 because 2 and 3 are in the array, making a consective count with 1 and 2. 
    assert(countElements(arr, arrSize) == 2);

    int arr2[] = {1, 1, 3, 4};
    arrSize = sizeof(arr2) / sizeof(arr2[0]);

    // Should return 2 because 4 has no consective following but 3 does, and 1 is counted once for 2.
    assert(countElements(arr2, arrSize) == 2);
}

int main() {
    test_insert_and_find();
    test_countElements();
    return 0;
}