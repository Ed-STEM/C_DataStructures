int* getAverages(int* nums, int numsSize, int k, int* returnSize) {
    
    int64_t sum = 0;
    int64_t* avgs = malloc (numsSize * sizeof(int64_t));
    
    for(int i = 0; i < numsSize; i++)
    {
        if(i-k < 0 || i + k >= numsSize)
        {
            avgs[i] = -1;
        } else {
            for(int j = i-k; j<=i+k; j++)
            {
                sum = sum + nums[j];
            }
            avgs[i] = sum / ((k*2)+1);
            sum = 0;
        }
    }
    
    
    *returnSize = numsSize;
    return avgs;
    
}



    
    long long *prefixSum = (long long *)malloc((numsSize + 1) * sizeof(long long));
    
    prefixSum[0] = 0;
    
    long long *avgs = (long long *)malloc((numsSize +1) * sizeof(long long));

    // Calculate prefix sum
    for (int i = 0; i < numsSize; i++) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    for (int i = 0; i < numsSize; i++) {
        if (i - k < 0 || i + k >= numsSize) {
            avgs[i] = -1;
        } else {
            long long sum = prefixSum[i + k + 1] - prefixSum[i - k];
            avgs[i] = sum / (2 * k + 1);
        }
    }

    free(prefixSum);
    *returnSize = numsSize;
    return avgs;
    