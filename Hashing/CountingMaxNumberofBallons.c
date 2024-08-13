int maxNumberOfBalloons(char* text) {
    
    int bCount = 0, aCount = 0, lCount = 0, oCount = 0, nCount = 0, wordCount = 0;
    
    //Use a switch to count the letters
    for(int i = 0; i < strlen(text); i++)
    {
        char letter = text[i];
        switch (letter){
            case 'b':
                bCount++;
                break;
            case 'a':
                aCount++;
                break;
            case 'l':
                lCount++;
                break;
            case 'o':
                oCount++;
                break;
            case 'n':
                nCount++;
                break;
        }
    }
    
    printf("b %d , a %d , l %d , o %d, n %d ",bCount, aCount, lCount, oCount, nCount);
    
    //Count how many times the word ballon is formed.
    while(bCount >= 1 && aCount >= 1 && lCount >= 2 && oCount >= 2 && nCount >= 1)
    {
        bCount--;
        aCount--;
        lCount-=2;
        oCount-=2;
        nCount--;
        wordCount++;
    }
    
    return wordCount;
}