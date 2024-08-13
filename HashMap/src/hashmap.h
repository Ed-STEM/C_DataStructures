#ifndef __hashmap_h__
#define __hashmap_h__


#define MAX_SIZE 10000

typedef struct {
    int key;
    int value;
} HashEntry;

void insert(HashEntry* hashTable, int key, int value);

int hash(int key);

int find(HashEntry* hashTable, int key);


#endif