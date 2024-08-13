#include "heap.h"

#include <stdio.h>
#include <stdlib.h>


int main() {
    int nums[] = {5,19,8,1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    double target = 0;
    int ans = 0;

    Heap *heapFromArr = createHeap(8);
    buildHeap(heapFromArr, nums, numsSize);
    printf("Heap built from array, max element: %d\n", top(heapFromArr));

    ensureCapacity(heapFromArr, numsSize);
    printf("The new heap capacity is : %d\n", heapFromArr->capacity);
    printf("The new heap size is %d\n", size(heapFromArr));

    for(int i = 0; i < numsSize; i++){
        add(heapFromArr, nums[i]);
        target += nums[i];
    }

    target /= 2;

    while(target > 0){
        ans++;
        pop(heapFromArr);
        double x = *heapFromArr->data;
        target -= (x / 2);
        add(heapFromArr, x / 2);
    }

    printf(" The Minimum operations to halve the sum of the given array is: %d \n", ans);

    // Clean up
    free(heapFromArr->data);
    free(heapFromArr);

    return 0;
}