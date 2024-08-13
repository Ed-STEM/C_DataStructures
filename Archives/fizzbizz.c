 #include <strings.h>
char ** fizzBuzz(int n, int* returnSize){
    

   *returnSize =n;
    char **answer = (char**)malloc(n * sizeof(char *));
    if(answer == NULL){
        printf("Error allocating memory!\n");
    }

    printf("n =%d, returnSize= %d",n, *returnSize);

    for(int j = 0; j < n; j++){
        answer[j]=(char*)malloc(9*sizeof(char));
        sprintf(answer[j], "d", j+1);
        if (answer[j] == NULL){
            printf("Error allocating memory!\n");
            return 1;
        } else if ((j+1) % 3 == 0 && (j+1) % 5 == 0){
            answer[j] = strdup( "FizzBuzz");
        } else if ((j+1) % 3 == 0 && (j+1) % 5 != 0){
            answer[j] = strdup( "Fizz");
        } else if ((j+1) % 3 != 0 && (j+1) % 5 == 0){   
            answer[j] = strdup( "Buzz");
        } else {
            //answer[j] = strdup(j+1);
            sprintf(answer[j], "%d", j+1);
        }  
    }
    return answer;

}