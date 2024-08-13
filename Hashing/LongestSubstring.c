
int lengthOfLongestSubstring(char* s) {
    int lastIndex[128];
    memset(lastIndex, -1, sizeof(lastIndex));
    
    int maxLen = 0, start = 0;
    
    for(int i = 0; s[i] != '\0'; i++)
    {
        char currentChar = s[i];
        
        if (lastIndex[currentChar]>= start)
        {
            start = lastIndex[currentChar] + 1;
        }
        lastIndex[currentChar]= i;
        maxLen = (i -start + 1 > maxLen) ? i -start +1 : maxLen;
    }

    return maxLen;
    
}