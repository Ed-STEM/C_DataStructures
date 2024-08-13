int longestOnes(int* nums, int numsSize, int k) {
 int sum = 0;
    int r = 0;
    int l =0;
    int j = 0;

    for(r=0;r<numsSize;r++)
    {
        if(nums[r]==0)
        {
            j++;
        }
           
        while(j > k )
        {
                
            if(nums[l]==0)
            {
                j--;
            } 
            l++;
        }

    sum = (r - l +1 > sum ) ? (r - l + 1) : sum;
    }
        
    

    return sum;
}