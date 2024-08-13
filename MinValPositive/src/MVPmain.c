#include "debug.h"

#include <stdio.h>
#include <debug.h>
#include <minvalp.h>


int main(int argc , char *argv[])
{

    LOG_INFO("Program Started");
    
    int nums[] = {-3,2,-3,4,2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int minval = minStartValue(nums, numsSize);

    printf("Minimum startValue is: %i\n", minval);

    return 0;

    
}