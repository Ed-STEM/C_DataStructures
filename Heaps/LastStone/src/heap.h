#ifndef __heap_h__
#define __heap_h__

//typedef struct Heap;

typedef struct Heap {
    int *data;
    int size;
    int capacity;
} Heap;

Heap* createHeap(int capacity);

void ensureCapacity(Heap *heap, int newcapacity);

void swap(int *a, int *b);

void heapifyUp(Heap *heap, int index);

void heapifyDown(Heap *heap, int index);

void add(Heap *heap, int element);

int top(Heap *heap);

void pop(Heap *heap);

int size(Heap *heap);

void buildHeap(Heap *heap, int *array, int arraySize);


#endif