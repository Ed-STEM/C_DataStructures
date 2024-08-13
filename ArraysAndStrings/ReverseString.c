void reverseString(char* s, int sSize) {
    
    if(s == NULL || sSize <= 1){
        return;
    }
    
    int left = 0;
    int right = sSize -1;
    
    while(left < right){
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        
        left++;
        right--;
    }
}

// Accidently thought it was a reverse string, good algorithm though
bool checkIfPangram(char* sentence) {
    
    int length = strlen(sentence)-1;
    for (int i = 0; sentence[i] != '\0'; i++){
        printf("i : length-i %c:%c , i:length %d:%d,", sentence[i],sentence[length-i], i, length);
        if(sentence[i] != sentence[length - i]){
            return false;
        }
    }
    
    return false;

}