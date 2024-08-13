bool canConstruct(char* ransomNote, char* magazine) {
    
    bool test = true;
    
    for (int i = 0; i < strlen(ransomNote); i++)
    {
        for (int j = 0; j < strlen(magazine); j++)
        {
            if( ransomNote[i] == magazine[j] )
            {
                test = true;
                magazine[j] = "T";
                break;
            } else if (ransomNote[i] != magazine[j] && j == strlen(magazine) - 1)
            {
                return false;
            }
            
        }
        printf(" i %d.", i);
    }
    
    return test;
}