/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    
    int* mono = (int*)malloc((nums1Size) * sizeof(int));
    int* index = (int*)malloc((nums1Size) * sizeof(int));
    
    for(int i = 0; i < nums1Size; i++){
        mono[i] = -1;
    }
    
    for (int i = 0; i < nums1Size; i++){
        
        for(int j = 0; j < nums2Size; j++){
            if(nums1[i] == nums2[j]){
                index[i] = j;
                break;
                
            }
        }
    }
    
    for (int i = 0; i < nums1Size; i++){
        for (int j = index[i]+1; j < nums2Size; j++){
            if( nums1[i] < nums2[j]){
                mono[i] = nums2[j];
                break;
            }
        }
    }
    
    *returnSize = nums1Size;
    return mono;
    
}