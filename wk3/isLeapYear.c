// Ciarán Mooney 
// 17/12/2012 (British Format)
// Program to work out if it's a leap year.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define START_OF_GREG_CALENDAR  1582

int main (int argc, const char * argv[]) {

    int year;

    printf ("please enter the year you are interested in\n");

    scanf("%d", &year);

    // notice this only works if the year if >= 1582
    // because of the gregorian calanedara stuff
    assert (year >= START_OF_GREG_CALENDAR);

    if ((year % 4) == 0 ) {
        if (year % 100 == 0) {
            if (year % 400 == 0){
                printf ("%d is a leap year!\n", year);
             } else {
            printf ("%d is not a leap year!\n", year);
            }
        } else {
            printf ("%d is a leap year!\n", year);
        }     
    } else {
        printf ("%d is not a leap year!\n", year);
    }   


    return EXIT_SUCCESS;
}

