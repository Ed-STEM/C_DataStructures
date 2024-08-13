#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int** findWinners(int** matches, int matchesSize, int* matchesColSize, int* returnSize, int** returnColumnSizes) {
    // Assuming the maximum player ID does not exceed 100000
    int maxPlayers = 100001;
    int* winCount = (int*)calloc(maxPlayers, sizeof(int));
    int* loseCount = (int*)calloc(maxPlayers, sizeof(int));
    int** answer = (int**)malloc(2 * sizeof(int*));
    int* winners;
    int* oneLoss;
    int winnersCount = 0, oneLossCount = 0;

    if (!winCount || !loseCount || !answer) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    // Count wins and losses for each player
    for (int i = 0; i < matchesSize; i++) {
        winCount[matches[i][0]]++;
        loseCount[matches[i][1]]++;
    }

    // Count the number of players with 0 losses and exactly 1 loss
    for (int i = 1; i < maxPlayers; i++) {
        if (winCount[i] > 0 || loseCount[i] > 0) {
            if (loseCount[i] == 0) {
                winnersCount++;
            } else if (loseCount[i] == 1) {
                oneLossCount++;
            }
        }
    }

    // Allocate memory for the answer arrays
    winners = (int*)malloc(winnersCount * sizeof(int));
    oneLoss = (int*)malloc(oneLossCount * sizeof(int));
    if (!winners || !oneLoss) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    // Fill the answer arrays
    int wIndex = 0, lIndex = 0;
    for (int i = 1; i < maxPlayers; i++) {
        if (winCount[i] > 0 || loseCount[i] > 0) {
            if (loseCount[i] == 0) {
                winners[wIndex++] = i;
            } else if (loseCount[i] == 1) {
                oneLoss[lIndex++] = i;
            }
        }
    }

    // Set the return values
    answer[0] = winners;
    answer[1] = oneLoss;
    *returnSize = 2;
    *returnColumnSizes = (int*)malloc(*returnSize * sizeof(int));
    (*returnColumnSizes)[0] = winnersCount;
    (*returnColumnSizes)[1] = oneLossCount;

    // Free temporary arrays
    free(winCount);
    free(loseCount);

    return answer;
}


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/

int** findWinners(int** matches, int matchesSize, int* matchesColSize, int* returnSize, int** returnColumnSizes){
    //Assuming the maxium player ID does not exceed 100000
    int maxPlayers = 100001;
    int* winCount = (int*)calloc(maxPlayers, sizeof(int));
    int* loseCount = (int*)calloc(maxPlayers, sizeof(int));
    int** answer = (int**)malloc(2 * sizeof(int*));
    int* winners;
    int* oneLoss;
    int winnersCount =  0, oneLossCount =0;

    if(!winCount || !loseCount || !answer){
        printf("Memory allocation failed\n");
        return NULL;
    }

    // Count wins and losses for each player
    for (int i = 0; i < matchesSize; i++){
        winCount[matches[i][0]]++;
        loseCount[matches[i][1]]++;
    }

    // Count the number of players with 0 losses and exactly 1 loss
    for (int i = 1; i < maxPlayers; i++){
        if (winCount[i] > 0 || loseCount[i] > 0){
            if (loseCount[i]==0){
                winnersCount++;
            } else if (loseCount[i] == 1){
                oneLossCount++;
            }
        }
    }

    //Allocate memory for the answer arrays
    winners = (int*)malloc(winnersCount * sizeof(int));
    oneLoss = (int*)malloc(oneLossCount * sizeof(int));
    if(!winners || !oneLoss){
        printf("Memory allocation failed\n");
        return NULL;
    }

    // Fill the answer arrays
    int wIndex = 0, lIndex = 0;
    for (int i = 1; i < maxPlayers; i++){
        if (winCount[i]>0 || loseCount[i]>0){
            if (loseCount[i] ==0){
                winners[wIndex++] =i;
            } else if (loseCount[i] ==1){
                oneLoss[lIndex++]=i;
            }
        }
    }


    // Set the return values
    answer[0] = winners;
    answer[1] = oneLoss;
    *returnSize = 2;
    *returnColumnSizes = (int*)malloc(*returnSize * sizeof(int));
    (*returnColumnSizes)[0] = winnersCount;
    (*returnColumnSizes)[1] = oneLossCount;

    //Free temporary arrays
    free(winCount);
    free(loseCount);

    return answer;


}


    int* prefix = (int*)malloc ((numsSize + 1) * sizeof(int));
    
    for(int i = 0; i < numsSize; i++)
    {
        if(i ==0)
        {
            prefix[i] = nums[i];
        } else {
            prefix[i] = prefix[i-1]+nums[i];
        }
    }
    
    for(int i = 0; i < numsSize; i++)
    {
        if(i % 2 == 0 && prefix[i] % 2 == 0)
        {
            count++;
        } else if (i % 2 != && prefix[i] % 2 != 0)
        {
            count++;
        } else {
            continue;
        }
    }

        int count = 0;
    int maxVal =0;

    if(numsSize == 2 || numsSize == 3){
        if(nums[0] != nums[1])
        {
            maxVal = 2;
        }
    } else{
     
        for(int i = 0; i < numsSize; i++)
        {

            if(i < numsSize -2 && nums[i] == nums[i+2])
            {
                printf(" %d , %d ", nums[i], nums[i+2]);
                count+=2;
            }
            if(maxVal <= count)
            {
                maxVal = maxVal + count;
            }
            
            count = 0;

        }
    }
    
    return maxVal;

    #define MAX_SIZE 10000

typedef struct {
    int key;
    char value;
} HashEntry;

int hash(int key){
    return (key + MAX_SIZE) % MAX_SIZE;
}

void insert(HashEntry* hashTable, int key, char value){
    
    int index = hash(key);
    
    while (hashTable[index].key !=0 || hashTable[index].value != 0)
    {
        index = hash(index + 1);
    }
    
    hashTable[index].key = key;
    hashTable[index].value = value;
}

int find(HashEntry* hashTable, int key){
    int index = hash(key);
    while (hashTable[index].key !=0 || hashTable[index].value != 0)
    {
        if (hashTable[index].key == key){
            return hashTable[index].value;
        }
        index = hash(index + 1);
    }
    return -1;
}

int lengthOfLongestSubstring(char* s) {
    
    //intiallize counters and hash character array.
    int count = 1, maxCount = 0, j = 1;
    HashEntry hashTable[MAX_SIZE] = {0};
    
    //Copy the first value of the given array into the hashmap.
    insert(hashTable, count, s[0]);
    
    //Go through the array and check neighboring values and double check with hashmap.
    for (int i = 1; i < strlen(s); i++)
    {
        if (find(HashTable,count) != s[i])
        {
            insert(hashTable, i, s[i]);
        } else {
            break;
        }
    }
    
    return maxCount;
    
}