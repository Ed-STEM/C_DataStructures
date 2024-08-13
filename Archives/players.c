/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
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
