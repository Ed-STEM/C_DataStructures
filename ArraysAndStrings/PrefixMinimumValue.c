int minStartValue(int* nums, int numsSize) {
    
    int startValue = 1; // Initial start value
    int sum = 0;
    int minSum = 0;

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        if (sum < minSum) {
            minSum = sum;
        }
    }

    // If minSum is less than 0, we need to adjust startValue
    if (minSum < 0) {
        startValue = 1 - minSum;
    }

    return startValue;
    
 
}