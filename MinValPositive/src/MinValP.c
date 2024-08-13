#include "debug.h"
#include <float.h>
#include <stdio.h>

int minStartValue(int* nums, int numsSize) {
    
    int startValue= 0;
    int sum=0;
    
    for(int i = 0; i < numsSize; i++)
    {
        
        if(sum <= 0 && i == 0)
        {
            startValue++;
            sum = nums[i] + startValue;
            
        } else if (sum <= 0 && i != 0){
            startValue++;
            printf("%d", startValue);
            
        } else {
            sum = sum + nums[i]+startValue;
            printf("%d ", sum);
        }
        
    }
    
    return startValue;  
}
