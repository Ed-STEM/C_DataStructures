#include "heap.h"

#include <stdio.h>
#include <stdlib.h>



Heap* createHeap(int capacity) {
    Heap *heap = (Heap*)malloc(sizeof(Heap));
    heap->data = (double*)malloc(capacity * sizeof(double));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void ensureCapacity(Heap *heap, int newcapacity) {
    if (heap->size <= newcapacity) {
        heap->data = (double*)realloc(heap->data, (newcapacity * sizeof(double)));
    } else {
        printf(" Failed to enter a heap capacity that is valid. \n");
    }
}

void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(Heap *heap, int index) {
    while (index != 0 && heap->data[(index - 1) / 2] < heap->data[index]) {
        swap(&heap->data[(index - 1) / 2], &heap->data[index]);
        index = (index - 1) / 2;
    }
}

void heapifyDown(Heap *heap, int index) {
    int largest = index;
    int leftChildIndex = 2 * index + 1;
    int rightChildIndex = 2 * index + 2;

    if (leftChildIndex < heap->size && heap->data[leftChildIndex] > heap->data[largest])
        largest = leftChildIndex;

    if (rightChildIndex < heap->size && heap->data[rightChildIndex] > heap->data[largest])
        largest = rightChildIndex;

    if (largest != index) {
        swap(&heap->data[index], &heap->data[largest]);
        heapifyDown(heap, largest);
    }
}

void add(Heap *heap, int element) {
    //ensureCapacity(heap,);
    heap->data[heap->size] = element;
    heap->size++;
    heapifyUp(heap, heap->size - 1);
}

int top(Heap *heap) {
    return heap->data[0];
}

void pop(Heap *heap) {
    if (heap->size == 0) return;
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
}

int size(Heap *heap) {
    return heap->size;
}

void buildHeap(Heap *heap, int *array, int arraySize) {
    if (arraySize > heap->capacity) {
        heap->capacity = arraySize;
        heap->data = (double*)realloc(heap->data, heap->capacity * sizeof(double));
    }
    for (int i = 0; i < arraySize; i++) {
        heap->data[i] = array[i];
    }
    heap->size = arraySize;
    for (int i = (arraySize / 2) - 1; i >= 0; i--) {
        heapifyDown(heap, i);
    }
}


