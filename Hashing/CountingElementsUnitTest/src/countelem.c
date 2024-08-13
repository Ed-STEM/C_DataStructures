#include "countelem.h"


int countElements(int* arr, int arrSize) {
    int count = 0;
    Hashitem dict[MAX_SIZE] = {-1};
    
    for(int i = 0; i < arrSize; i++){
        insert(dict,i,arr[i]);
    }
    printf(" 1st For complete. ");
    
    for(int j = 0; j < arrSize; j++){
        if(find(dict,j) != -1){
            count++;
            printf(" count %d ", count);
            break;
        }
    }
    printf(" 2nd For complete. ");
    
    return count;

}
