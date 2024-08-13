#include "hashmap.h"



int hash(int key){
    return (key + MAX_SIZE) % MAX_SIZE;
}

void insert(Hashitem* dict, int key, int value){
    int index = hash(key);
    int originalIndex = index;
    while (dict[index].key != -1 || dict[index].value != -1){
        index = hash(index+1);
        if (index == originalIndex){
            //Hashmap is full.
            return;
        }
    }
    dict[index].key = key;
    dict[index].value = value;
}

int find(Hashitem* dict, int key){
    int index = hash(key);
    while (dict[index].key != -1){
        if (dict[index].key == key){
            printf(" Found %d ", dict[index].value);
            return dict[index].value;
        }
        index = hash(index+1);
    }
    return -1;
}