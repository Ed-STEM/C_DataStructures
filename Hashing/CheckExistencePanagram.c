bool checkIfPangram(char* sentence) {
    
    bool letters[26] = {false};
    
    for (int i = 0; sentence[i] != '\0'; i++)
    {
        if(sentence[i] >= 'a' && sentence[i] <= 'z'){
            letters[sentence[i]-'a'] = true;
        }
    }
    
    for (int i = 0; i<26; i++){
        if(!letters[i]){
            return false;
        }
    }
    return true;
}