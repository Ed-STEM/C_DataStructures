//Create the main function that calls leetcode example and test problems.
//This first example is for running the Fibbonaci sequece.

double fibonacci(int maxnum)
{
    if(maxnum <= 1)
        return maxnum;

    int firstback = fibonacci(maxnum - 1);
    int secondback = fibonacci(maxnum - 2);

    return firstback + secondback;

}