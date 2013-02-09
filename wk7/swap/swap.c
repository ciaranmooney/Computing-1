// Ciarán Mooney 
// 15/1/2013 
// Swap two numbers 

#include <stdlib.h>
#include <stdio.h>

void swap (int* first, int* second);

int main (int argc, const char * argv[]) {
    int first, second;
    int *pFirst, *pSecond;

    pFirst = &first;
    pSecond = &second;

    scanf("%d %d", &first, &second);
    printf("1: %d, 2: %d\n", first, second);
    swap(pFirst, pSecond);
    printf("1: %d, 2: %d\n", first, second);

    return EXIT_SUCCESS;
}

void swap (int* first, int* second){
    int a;
    int b;   
    
    a = *first;
    b = *second;

    *second = a;
    *first = b;
}
