/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    
    int* sorted = malloc(numsSize * sizeof(nums));
    int k = 0;
    
    for(int i = 0; i <= numsSize-1; i++)
    {
        sorted[i] = nums[i] * nums[i];
    }

    
    while(k <= numsSize)
    {
        for(int j = 0; j <= numsSize-2;j++)
        {
            int a = sorted[j];
            int b = sorted[j+1];
            if(a > b)
            {
                sorted[j] = b;
                sorted[j+1] = a;
            } else {
                continue;
            }
            
        }
         k++;
    }

    *returnSize = numsSize;
    return sorted;
    
}

//Better Answer
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    
    int hold = 0;
    int count = 0;
    int check = 0;
    int* sqr = (int*)malloc((numsSize+1)*sizeof(int));
    
    //Square Array
    for (int i = 0; i < numsSize; i++){
        sqr[i] = nums[i] * nums[i];
    }

    //Sort Squared Array
    while(check < numsSize){
        for(count = 0; count < numsSize-1; count++){

            if (sqr[count] > sqr[count+1] ){
                hold = sqr[count];
                sqr[count] = sqr[count+1];
                sqr[count+1] = hold;
                count--;
            } 
        }
        check++;
    }
    
    *returnSize = numsSize;
    return sqr;
    
}

//Actual two-pointer Answer CGPT
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* sqr = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    int left = 0;
    int right = numsSize - 1;
    int index = numsSize - 1; // Start filling from the end of the array

    while (left <= right) {
        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];

        if (leftSquare > rightSquare) {
            sqr[index--] = leftSquare;
            left++;
        } else {
            sqr[index--] = rightSquare;
            right--;
        }
    }

    return sqr;
}