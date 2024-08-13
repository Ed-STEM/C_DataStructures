#include "debug.h"
#include <float.h>
#include <stdio.h>

double findMaxAverage(int* nums, int numsSize, int k) {


//    setLogLevel(LOG_DEBUG);

    if(numsSize < k)
    {
        printf("k value must be less than the length of the array.");
        return -1;
    }
    
    double maxval = 0.0;
    int sum =0;

    for(int i = 0; i<k;i++)
    {
        sum += nums[i];
    }
    
    maxval = (double) sum/k;

    
//    CHECK_NULL(nums);
    for(int i =k; i < numsSize; i++)
    {
        sum = sum - nums[i -k] + nums[i];
        double currentAvg = (double)sum/k;
        if(maxval < currentAvg)
        {
            maxval = currentAvg;
        }
    }

    error:
       if(!nums)
       {
            return -1;
       }
            //free(nums);
        

    return maxval;
    
}

