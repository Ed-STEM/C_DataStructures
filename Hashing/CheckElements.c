int countElements(int* arr, int arrSize) {
    
    int count = 0;
    int value = 0;
    
    for(int i = 0; i < arrSize; i++)
    {
        for(int j = 0; j < arrSize; j++)
        {
            //if(i>0 && arr[i]==arr[i-1])
            //{
            //    break;
            //}
            if(arr[i]+1 == arr[j])
            {
                value++;
                break;
            } 
        }
    }
    
    return value;
}