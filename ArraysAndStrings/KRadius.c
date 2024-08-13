/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getAverages(int* nums, int numsSize, int k, int* returnSize) {
    
    long sum = 0;
    long* prefix = malloc ((numsSize+1) * sizeof(long));
    int* avgs = malloc (numsSize * sizeof(int));
    prefix[0] = 0;
    
    for (int i = 0; i < numsSize; i++)
    {
        prefix[i+1] = prefix[i]+nums[i];
    }
    
    for(int i = 0; i < numsSize; i++)
    {
        if(i-k < 0 || i + k >= numsSize)
        {
            avgs[i] = -1;
        } else {
            sum = prefix[i+k+1] - prefix[i-k];
            avgs[i] = sum / ((k*2)+1);
           // printf(" avg %d ", avgs[i]);
            sum = 0;
        }
    }
    
    free(prefix);
    *returnSize = numsSize;
    return avgs;
    
}