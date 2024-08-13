/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize){

    int *array = malloc (numsSize * sizeof(int));
    
    for(int i = 0; i < numsSize; i++)
    {
        if(i == 0)
        {
        array[i] = nums[i];
        } else {
            array[i] = nums[i] +array[i-1];
        }
        
    }
    
    *returnSize = numsSize;
    return array;
    
    
    
}