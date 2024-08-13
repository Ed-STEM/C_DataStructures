#ifndef __heap_h__
#define __heap_h__

//typedef struct Heap;

typedef struct{
    double* maxHeap; // First half of the elements
    int maxHeapSize;
    double* minHeap;
    int minHeapSize;
} MedianFinder;

MedianFinder* medianFinderCreate();

void swap(double *a, double *b);

void maxHeapify(MedianFinder* obj, int index);

void minHeapify(MedianFinder* obj, int index);

void addNum(MedianFinder* obj, int num);

double findMedian(MedianFinder* obj);

void medianFinderFree(MedianFinder* obj);

#endif