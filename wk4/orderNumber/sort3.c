// Ciarán Mooney 
// 24/12/2012 
// Sort three numbers

#include <stdlib.h>
#include <stdio.h>

#define ONE_TWO 1
#define TWO_THREE 2
#define ONE_THREE 3

#define TWO_EQUAL_YES 1
#define TWO_EQUAL_NO 0

#define DONE_NO 0
#define DONE_YES 1

void printThreeNumbers (int one, int two, int three);
int checkEqual (int one, int two, int three);

int main (int argc, const char * argv[]) {
    int first, second, third;
    int twoEqual;
    int done;
    twoEqual = TWO_EQUAL_NO;
    done = DONE_NO;
    scanf("%d %d %d", &first, &second, &third); 
    //scanf("%d", &first);
    //scanf("%d", &second);
    //scanf("%d", &third);

    // first == second != third
    // first != second == third
    // first == third != second

    // first == second == third

    // All possible orders of three inputted numbers
    // first second third
    // first third second
    // second first third
    // second third first
    // third first second
    // third second first

    //check for equality of input
    // if equal check, check ordering
    
    if (checkEqual(first, second, third)==ONE_TWO){
        // check that third is < or > first and second 
        twoEqual = TWO_EQUAL_YES;
        if (second < third) {
            // first second third
            printThreeNumbers(first, second, third);
        } else {
            // third first second
            printThreeNumbers(third, first, second);
        } 
    }

    if (checkEqual(first, second, third)==TWO_THREE){
        //check that first is < or > second and third
        twoEqual = TWO_EQUAL_YES;
        if (first < third) {
            // first second third
            printThreeNumbers(first, second, third);
        } else {
            // second third first
            printThreeNumbers(second, third, first);
        } 
    }

    if (checkEqual(first, second, third)==ONE_THREE){
        //check that second is < or > first and third
        twoEqual = TWO_EQUAL_YES;
        if (second < third) {
            // second first third
            printThreeNumbers(second, first, third);
        } else {
            // first third second
            printThreeNumbers(first, third, second);
        } 
    }

    if (twoEqual == TWO_EQUAL_NO){
    
    // All possible orders of three inputted numbers
    // first second third
    // first third second
    // second first third
    // second third first
    // third first second
    // third second first
        if (done == 0) {
            if (first < second) {
                if (second < third) {
                    // first second third
                    printThreeNumbers(first, second, third);
                    done = DONE_YES;
                }
                if (third < second) {
                    if (third < first){
                        printThreeNumbers(third, first, second);
                        done = DONE_YES;
                    } else {
                        // first third second
                        printThreeNumbers(first, third, second);
                        done = DONE_YES;
                    }
                }
            
            } 
        }
        
        if (done == 0) {
            if (second < first) {
                if (first < third) {
                    // second first third
                    printThreeNumbers(second, first, third);
                    done = DONE_YES;
                }
                if (third < first) {
                    if (third < second ) {
                        printThreeNumbers(third, second, first);
                        done = DONE_YES;
                    } else {
                        // second third first
                        printThreeNumbers(second, third, first);
                        done = DONE_YES;
                    }   
                } 
            }    
         }
    
        if (done == 0) {
            if (third < first) {
                if (first < second) {
                    // third second first 
                    printThreeNumbers(third, second, first);
                    done = DONE_YES;
                }
                if (second < first) {
                    if (second < third){
                        printThreeNumbers(second, third, first);
                        done = DONE_YES;
                    } else {
                        // third second first
                        printThreeNumbers(third, second, first);
                        done = DONE_YES;
                    }
                } 
            }
        }
    }
    return EXIT_SUCCESS;
}

void printThreeNumbers (int one, int two, int three) {
    printf("%d\n%d\n%d\n",one, two, three);
}

int checkEqual(int one, int two, int three){
    int equal;
    equal = 0;
    if (one == two){
        equal = ONE_TWO;
    }    

    if (two == three){
        equal = TWO_THREE;
    }

    if (one == three){
        equal = ONE_THREE;
    }
    return equal;
}

