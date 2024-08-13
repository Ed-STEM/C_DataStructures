#include "heap.h"

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000



MedianFinder* medianFinderCreate() {
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));
    obj->maxHeap = (double*)malloc(sizeof(double) * MAX_SIZE);
    obj->minHeap = (double*)malloc(sizeof(double) * MAX_SIZE);
    obj->maxHeapSize = 0;
    obj->minHeapSize = 0;
    return obj;
}

void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(MedianFinder* obj, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < obj->maxHeapSize && obj->maxHeap[left] > obj->maxHeap[largest]){
        largest = left;
    }
    if (right < obj->maxHeapSize && obj->maxHeap[right] > obj->maxHeap[largest]){
        largest = right;
    }
    if (largest != index){
        swap(&obj->maxHeap[index], &obj->maxHeap[largest]);
        maxHeapify(obj, largest);
    }
}

void minHeapify(MedianFinder* obj, int index) {
    int smallest = index;
    int leftChildIndex = 2 * index + 1;
    int rightChildIndex = 2 * index + 2;

    if (leftChildIndex < obj->minHeapSize && obj->minHeap[leftChildIndex] < obj->minHeap[smallest]){
        smallest = leftChildIndex;
    }
    if (rightChildIndex < obj->minHeapSize && obj->minHeap[rightChildIndex] < obj->minHeap[smallest])
        smallest = rightChildIndex;

    if (smallest != index) {
        swap(&obj->minHeap[index], &obj->minHeap[smallest]);
        minHeapify(obj, smallest);
    }
}

void addNum(MedianFinder* obj, int num) {
    if (obj->maxHeapSize == 0 || num < obj->maxHeap[0]){
        obj->maxHeap[obj->maxHeapSize++] = num;
        for (int i = (obj->maxHeapSize / 2) -1; i >= 0; i--){
            maxHeapify(obj, i);
        }
    } else {
        obj->minHeap[obj->minHeapSize++] = num;
        for(int i = (obj->minHeapSize/ 2) - 1; i >= 0; i--){
            minHeapify(obj, i);
        }
    }

    // Rebalance
    if (obj->maxHeapSize > obj->minHeapSize + 1){
        obj->minHeap[obj->minHeapSize++] = obj->maxHeap[0];
        obj->maxHeap[0] = obj->maxHeap[--obj->maxHeapSize];
        maxHeapify(obj, 0);
        minHeapify(obj, (obj->minHeapSize / 2) -1);
    } else if (obj->minHeapSize > obj->maxHeapSize + 1){
        obj->maxHeap[obj->maxHeapSize++] = obj->minHeap[0];
        obj->minHeap[0] = obj->minHeap[--obj->minHeapSize];
        minHeapify(obj, 0);
        maxHeapify(obj, (obj->maxHeapSize / 2)- 1);
    }
}

double findMedian(MedianFinder* obj){
    if (obj->maxHeapSize > obj->minHeapSize){
        return obj->maxHeap[0];
    } else if ( obj->minHeapSize > obj->maxHeapSize){
        return obj->minHeap[0];
    } else {
        return (obj->maxHeap[0] + obj->minHeap[0]) / 2.0;
    }
}

void medianFinderFree(MedianFinder* obj){
    free(obj->maxHeap);
    free(obj->minHeap);
    free(obj);
}


