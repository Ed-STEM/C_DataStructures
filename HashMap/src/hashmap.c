#include "debug.h"
#include <float.h>
#include <stdio.h>
#include "hashmap.h"


int hash(int key){
    return (key + MAX_SIZE) % MAX_SIZE;
}

void insert(HashEntry* hashTable, int key, int value){
    int index = hash(key);
    while (hashTable[index].key !=0 || hashTable[index].value != 0)
    {
        index = hash(index +1);
    }
    hashTable[index].key = key;
    hashTable[index].value = value;
}

int find(HashEntry* hashTable, int key){
    int index = hash(key);
    while (hashTable[index].key != 0 || hashTable[index].value != 0)
    {
        if (hashTable[index].key == key) {
            return hashTable[index].value;
        }
        index = hash(index +1);
    }
    return -1; 
}
