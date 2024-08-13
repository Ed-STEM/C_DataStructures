#ifndef __hashmap_h__
#define __hashmap_h__

#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_math.h>

#define MAX_SIZE 1000

typedef struct{
    int key;
    int value;
} Hashitem;

int hash(int key);

void insert(Hashitem* dict, int key, int value);

int find(Hashitem* dict, int key);

#endif

/*
3 projects
unit testing on leetcode projects *practice
gsl for math and eventually fusion  *primary *primary! we agree.
gsl kmeans? eventually. *practice

Is github an issue? 
or good thing.

*/