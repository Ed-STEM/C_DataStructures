#ifndef TEST_BUILD

#include "hashmap.h"
#include "dbg.h"
#include "countelem.h"

#include <stdio.h>
#include <string.h>

int main()
{

    int array[8] = {1,1,3,3,5,5,7,7};
    int arraySize = 8;

    int count = countElements(array, arraySize);
    printf(" The number %i\n", count);
    
    return 0;

}
#endif