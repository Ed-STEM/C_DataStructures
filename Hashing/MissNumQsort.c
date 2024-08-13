int cmpfunc(const void *a, const void * b){
    return ( *(int*)a - *(int*)b);
}

int missingNumber(int* nums, int numsSize) {
    

    qsort(nums, numsSize, sizeof(int), cmpfunc);
    for (int i = 0; i < numsSize; i++){
        if (nums[i] != i){
            //printf(" %d:%d", sort[i], i);
            return i;
        }
    }
      
    if(nums[numsSize-1] != numsSize ){
        return numsSize;
    }
    
    return -1;
    
}