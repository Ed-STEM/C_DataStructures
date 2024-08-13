#include "debug.h"
#include "hashmap.h"
#include "contigbinary.h"


#include <float.h>
#include <stdio.h>


int findMaxLength(int* nums, int numsSize){
    HashEntry hashTable[MAX_SIZE] = {0};
    int maxLen = 0, sum = 0;

    for(int i = 0; i < numsSize; i++)
    {
        sum += (nums[i]==0) ? -1 : 1;

        if (sum ==0)
        {
            maxLen = i + 1;
        } else {
            int prevIndex = find(hashTable, sum);
            if (prevIndex != -1)
            {
                maxLen = (i - prevIndex > maxLen) ? i - prevIndex : maxLen;
            } else {
                insert(hashTable, sum, i);
            }
        }
    }

    return maxLen;

}

