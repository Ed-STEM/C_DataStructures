#include "debug.h"

#include <stdio.h>
#include <debug.h>
#include <longestones.h>


int main(int argc , char *argv[])
{

    int nums[] = {1,1,1,0,0,0,1,1,1,1,0};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 2;
    int maxOnes = longestOnes(nums, numsSize, k);

    printf("Maximum Ones: %i\n", maxOnes);

    return 0;

    
}