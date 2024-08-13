#include "heap.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    MedianFinder* finder = medianFinderCreate();
    addNum(finder, 1);
    addNum(finder, 2);
    printf("Median: %f\n", findMedian(finder));
    addNum(finder, 3);
    printf("Median: %f\n", findMedian(finder));
    medianFinderFree(finder);
    return 0;
}