#include "heap.h"

#include <stdio.h>
#include <stdlib.h>


int main() {
    Heap *heap = createHeap(10); // Initial capacity of 10

    // Add to heap
    add(heap, 1);
    add(heap, 2);
    add(heap, 3);

    // Check maximum element
    printf("Maximum element: %d\n", top(heap));

    // Pop maximum element
    pop(heap);

    // Get size
    printf("Size: %d\n", size(heap));

    // Bonus: convert an array into a heap in linear time
    int nums[] = {3, 1, 4, 1, 5, 9, 2, 6};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    Heap *heapFromArr = createHeap(8);
    buildHeap(heapFromArr, nums, numsSize);
    printf("Heap built from array, max element: %d\n", top(heapFromArr));

    ensureCapacity(heapFromArr);
    printf("The new heap capacity is : %d\n", heapFromArr->capacity);
    printf("The new heap size is %d\n", size(heapFromArr));

    // Clean up
    free(heap->data);
    free(heap);
    free(heapFromArr->data);
    free(heapFromArr);

    return 0;
}