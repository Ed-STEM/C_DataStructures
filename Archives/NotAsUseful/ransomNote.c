#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <unistd.h>
#include <getopt.h>
#include <sys/types.h>
#include <stdbool.h>

bool canConstruct(char * ransomNote, char * magazine){

    char *map = (char*)malloc((strlen(magazine)+1)*sizeof(char));
    map = *magazine;
    printf("The map size is: %d ", strlen(map));
    int i,j = 0;
    
    while(*ransomNote){
        if (ransomNote[i] != NULL && ransomNote[i] == magazine[j]){
            strcpy(map,"T");
            ransomNote[i] == NULL;
            magazine++;
            i++;
            j++;
        } else {
            i++;
            j++;
        }
    }

    printf("Boolean test underway.");
    while(map != NULL){
        if (map != "T")
        {
            free(map);
            return 1;
        } else {
            map++;
        }
    }
    free(map);
    return 0;
}

int main(int argc, char *argv[]){
    char * ransomNote;
    char * magazine;
    
    if(argc > 3){
        printf("There are too many arguments");
    } else if(argc < 3){
        printf("There are too few arguments");
    } else if(argc == 3){
        ransomNote = argv[1];
        magazine = argv[2];
    } else {
        printf("This program will self-destruct in ...");
    }

    int value = canConstruct(ransomNote, magazine);
    return value;
    
}