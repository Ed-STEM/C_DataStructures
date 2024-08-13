int missingNumber(int* nums, int numsSize) {
    
    int* full = malloc ((numsSize+1) * sizeof(int));
    bool* test = malloc ((numsSize+1)* sizeof(bool));
    int answer = 0;
    
    for(int i = 0; i<= numsSize; i++)
    {
        full[i] = i;
        test[i] = false;
    }
    
    for(int i = 0; i<= numsSize; i++)
    {
        for(int j = 0; j < numsSize; j++ )
        {
            if(full[i] == nums[j])
            {
                test[i] = true;
            } 
                
        }
    }
    
    for(int i= 0; i <= numsSize; i++)
    {
        if(test[i] == NULL)
        {
            printf("Theres a problem.");
        }
        printf(" bool %d ", test[i]);
        if(test[i] != 1)
        {
            answer = i;
        }
    }
    
    
    free(full);
    free(test);
    return answer;

}