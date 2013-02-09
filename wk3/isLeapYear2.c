// Ciarán Mooney
// 18.12.12 (British Date Format)
// A program that has a leap year function.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define START_OF_GREG_CALENDAR  1582

int isLeapYear (int year){
    
    int LeapYear;

    assert (year >= START_OF_GREG_CALENDAR);
    
    if ((year % 4) == 0 ) {
        if (year % 100 == 0) {
            if (year % 400 == 0){
                LeapYear = 1;
             } else {
            LeapYear = 0;
            }
        } else {
            LeapYear = 1;
        }     
    } else {
        LeapYear = 0;
    }   

    return LeapYear;
}

int main (int argc, const char * argv[]) {

    int year;

    printf ("please enter the year you are interested in\n");

    scanf("%d", &year);

    if (isLeapYear(year) == 0){
        printf("%d is not a leap year.\n", year);
    }

    if (isLeapYear(year) == 1){
        printf("%d is a leap year.\n", year);
    }

    return EXIT_SUCCESS;
}



