#include "heap.h"

#include <stdio.h>
#include <stdlib.h>


int main() {
    int stones[] = {2, 7, 4, 1, 8, 1};
    int stonesSize = sizeof(stones) / sizeof(stones[0]);
    Heap *heapFromArr = createHeap(8);
    buildHeap(heapFromArr, stones, stonesSize);
    printf("Heap built from array, max element: %d\n", top(heapFromArr));

    ensureCapacity(heapFromArr, stonesSize);
    printf("The new heap capacity is : %d\n", heapFromArr->capacity);
    printf("The new heap size is %d\n", size(heapFromArr));

    for(int i = 0; i < stonesSize; i++){
        add(heapFromArr, stones[i]);
    }

    while(size(heapFromArr) > 1){
        pop(heapFromArr);
        int first = *heapFromArr->data;
        pop(heapFromArr);
        int second = *heapFromArr->data;
        if(first != second){
            add(heapFromArr, first-second);
        }
    }

    int last = size(heapFromArr) == 0 ? 0 : *heapFromArr->data;
    printf(" The last weight of stones is: %d \n", last);


    // Clean up
    free(heapFromArr->data);
    free(heapFromArr);

    return 0;
}