#include "debug.h"

#include <stdio.h>
#include <debug.h>
#include <slidingwin.h>


int main(int argc , char *argv[])
{

//    setLogLevel(LOG_DEBUG);

//    int *ptr = malloc(sizeof(int));
//    CHECK_ALLOC(ptr);

//    *ptr = 10;
//    LOG_INFO("Value assigned to ptr: %d", *ptr);

    int nums[] = {1, 12, -5, -6, 50, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 4;
    double maxAverage = findMaxAverage(nums, numsSize, k);

    printf("Maximum average: %f\n", maxAverage);

//    free(ptr);
    return 0;

    
}