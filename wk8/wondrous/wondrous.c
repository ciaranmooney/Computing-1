// Ciarán Mooney
// 22/1/2013
// A program and function that prints out wondrous numbers

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int wondrous (int start);
void test (void);
int even(int number);

#define TRUE 1
#define FALSE 0

int main(int argc, char* argv[]){
    int iterations;
    
    test();
    iterations = wondrous(7999);
    printf("%d", iterations);
    return EXIT_SUCCESS;
}

void test (void){
    assert(even(2) == TRUE);
    assert(even(3) == FALSE);
    printf("is_even passed\n");
    assert(wondrous(3)==8);
    assert(wondrous(1)==1);
    printf("All tests passed!\n");
}

int wondrous (int start){
    int counter;

    counter = 1;

    while (start > 1 ){
        printf("%d ", start);
        counter = counter + 1;
        if (even(start) == TRUE){
            start = start / 2;
            }
        else {
            start = (start * 3) + 1;
        }
    }
    printf("1\n");
    return counter;
}

int even (int number){
    int is_even;

    if (number % 2 ==0){
        is_even = TRUE;
    }
    else {
        is_even = FALSE;
    }

    return is_even;
}
