/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findWinners(int** matches, int matchesSize, int* matchesColSize, int* returnSize, int** returnColumnSizes) {
int lose = 0;
    
    int** answer = (int**)malloc (2 * sizeof(int*));
    int* winners = malloc (matchesSize+1 * sizeof(int));
    int* losers = malloc (matchesSize+1 * sizeof(int));
    
    printf("Matches %d", matchesSize);
    
    if(answer == NULL)
    {
        printf("There was an issue allocating memory.");
    }
    
    for(int i = 0; i < matchesSize; i++)
    {
        for(int j = 0; j < matchesSize; j++)
        {

            if(matches[i][0] == matches[j][1])
            {
                lose++;
            }
        
        }
        if(lose == 0)
        {
            printf(" lose = 0 ");
            winners[i] = matches[i][0];
            printf(" %d , %d ", winners[i], matches[i][0]);
        } else if (lose == 1)
        {
            printf(" lose - 1");
            losers[i] = matches[i][0];
            printf(" %d , %d ", losers[i], matches[i][0]);
        } else {
            break;
        }
        
    }
    printf("Winners,losers %d,%d", winners[0], losers[0]);
    answer[0] = winners;
    answer[1] = losers;
    printf("answer0 answer1 %d,%d");
    //free(winners);
    //free(losers);
    *returnColumnSizes = (int*)malloc(*returnSize * sizeof(int));
    (*returnColumnSizes)[0] = winners;
    (*returnColumnSizes)[1] = losers;
    *returnSize = 2;
    return answer;