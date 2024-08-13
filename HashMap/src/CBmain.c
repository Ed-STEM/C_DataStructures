#include "debug.h"
#include "hashmap.h"
#include "contigbinary.h"

#include <stdio.h>


int main()
{

//    setLogLevel(LOG_DEBUG);

//    int *ptr = malloc(sizeof(int));
//    CHECK_ALLOC(ptr);

//    *ptr = 10;
//    LOG_INFO("Value assigned to ptr: %d", *ptr);

    int nums[] ={0, 1, 0, 1, 0, 1, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("Maximum length of a contiguous subarray: %d\n ", findMaxLength(nums, numsSize));

//    free(ptr);
    return 0;

    
}