int largestUniqueNumber(int* nums, int numsSize) {
    //set the maximum value parameter.
    int maxVal = 0;
    int count = 0;
    
    //create an array of non duplicates.
    int* singles = (int*)malloc(numsSize * sizeof(int));
    
    //O(n^2) loop to create an array with no duplicates.
    for (int i = 0; i < numsSize; i++)
    {

        for (int j = 0; j < numsSize; j++)
        {
            if(i != j)
            {
                if(nums[i] == nums[j])
                {
                    break;
                } else if (j == numsSize -1) {
                    singles[count] = nums[i];
                    count++;
                }
            }
        }
    }
    
    //O(n) loop to find the maximum value of the non-duplicates array
    for (int i = 0; i < numsSize; i++)
    {
        if ( maxVal < singles[i])
        {

            maxVal = singles[i];
        } else if (maxVal == singles[i])
        {
            maxVal = 0;
        }
    }
    
    //free memory for non-duplicate array.
    free(singles);

    
    //Test for maximum value or non-existence return value.
    if(numsSize == 1)
    {
        maxVal = nums[0];
    }
    if (maxVal == 0)
    {
        return -1;
    } else {
        return maxVal;
    }
    
    
}