// Ciarán Mooney
// 27/12/2012 (British Format)
// Something about working out what date next thursday falls on

/*
*  doomsday.c
*  A program to test a function dayOfWeek which determines which
*  day of the week a particular date falls on.
*  (only for dates after the start of the Gregorian calendar).
*
*  Program stub created by Richard Buckland on 27/03/12
*  This program by YOUR-NAME-HERE
*  Freely licensed under Creative Commons CC-BY-3.0
*
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define THURSDAY 0
#define FRIDAY   1
#define SATURDAY 2
#define SUNDAY   3
#define MONDAY   4
#define TUESDAY  5
#define WEDNESDAY 6

#define JAN 31 
#define MAR 31
#define APR 30
#define MAY 31
#define JUN 30
#define JUL 31
#define AUG 31
#define SEP 30
#define OCT 31
#define NOV 30
#define DEC 31

#define TRUE 1
#define FALSE 0
#define DAYS_PER_WEEK 7
     
int dayOfWeek (int doomsday, int leapYear, int month, int day);
int numberOfDays (int leapYear, int month, int day);
int daysInMonth (int month, int leapYear); 
int february (int leapYear);
int dayBackwards (int backwardsDay);

int main (int argc, char *argv[]) {
       assert (dayOfWeek (THURSDAY,  FALSE,  4,  4) == THURSDAY);
       assert (dayOfWeek (FRIDAY,    FALSE,  6,  6) == FRIDAY);
       assert (dayOfWeek (MONDAY,    FALSE,  8,  8) == MONDAY);
       assert (dayOfWeek (WEDNESDAY, FALSE, 10, 10) == WEDNESDAY);
       assert (dayOfWeek (FRIDAY,    FALSE, 12, 12) == FRIDAY);
       assert (dayOfWeek (THURSDAY,  FALSE,  9,  5) == THURSDAY);
       assert (dayOfWeek (FRIDAY,    FALSE,  5,  9) == FRIDAY);
       assert (dayOfWeek (SUNDAY,    FALSE,  7, 11) == SUNDAY);
       assert (dayOfWeek (TUESDAY,   FALSE, 11,  7) == TUESDAY);
       assert (dayOfWeek (WEDNESDAY, FALSE,  3,  7) == WEDNESDAY);
       
       assert (dayOfWeek (FRIDAY, FALSE,  4,  26) == SATURDAY);
       assert (dayOfWeek (FRIDAY, FALSE,  4,  29) == TUESDAY);
       
       assert (dayOfWeek (THURSDAY,  FALSE,  4,  5) == FRIDAY);
       assert (dayOfWeek (SATURDAY,  FALSE,  6,  5) == FRIDAY);
       assert (dayOfWeek (MONDAY,    FALSE,  8,  9) == TUESDAY);
       assert (dayOfWeek (WEDNESDAY, FALSE, 10,  9) == TUESDAY);
       assert (dayOfWeek (FRIDAY,    FALSE, 12, 20) == SATURDAY);
       assert (dayOfWeek (THURSDAY,  FALSE,  9,  9) == MONDAY);
       assert (dayOfWeek (FRIDAY,    FALSE,  5,  5) == MONDAY);
       assert (dayOfWeek (SUNDAY,    FALSE,  7,  7) == WEDNESDAY);
       assert (dayOfWeek (TUESDAY,   FALSE, 11, 11) == SATURDAY);
       assert (dayOfWeek (THURSDAY,  FALSE,  3, 30) == SATURDAY);
     
       assert (dayOfWeek (TUESDAY,   FALSE,  2,  28) == TUESDAY);
       assert (dayOfWeek (TUESDAY,   FALSE,  2,  27) == MONDAY);
       assert (dayOfWeek (THURSDAY,  FALSE,  1,  3)  == THURSDAY);
       
       assert (dayOfWeek (THURSDAY,  TRUE,  4,  4) == THURSDAY);
       assert (dayOfWeek (FRIDAY,    TRUE,  6,  6) == FRIDAY);
       assert (dayOfWeek (MONDAY,    TRUE,  8,  8) == MONDAY);
       assert (dayOfWeek (WEDNESDAY, TRUE, 10, 10) == WEDNESDAY);
       assert (dayOfWeek (FRIDAY,    TRUE, 12, 12) == FRIDAY);
       assert (dayOfWeek (THURSDAY,  TRUE,  9,  5) == THURSDAY);
       assert (dayOfWeek (FRIDAY,    TRUE,  5,  9) == FRIDAY);
       assert (dayOfWeek (SUNDAY,    TRUE,  7, 11) == SUNDAY);
       assert (dayOfWeek (TUESDAY,   TRUE, 11,  7) == TUESDAY);
       assert (dayOfWeek (WEDNESDAY, TRUE,  3,  7) == WEDNESDAY);
       
       assert (dayOfWeek (WEDNESDAY, TRUE,  4,  26) == THURSDAY);
       assert (dayOfWeek (WEDNESDAY, TRUE,  4,  29) == SUNDAY);
       
       assert (dayOfWeek (WEDNESDAY, TRUE,  2,  29) == WEDNESDAY);
       assert (dayOfWeek (WEDNESDAY, TRUE,  3,  1) == THURSDAY);

       assert (dayOfWeek (FRIDAY, TRUE,  2,  28) == THURSDAY);
       assert (dayOfWeek (FRIDAY, TRUE,  2,  29) == FRIDAY);
       assert (dayOfWeek (FRIDAY, TRUE,  3,  1) == SATURDAY);
       
       printf ("all tests passed - You are awesome!\n");
       return EXIT_SUCCESS;
}
     

// given the doomsday for a year, and whether or not it is a
// leap year, this function return the day of the week for any
// given month and day in the year.

int dayOfWeek (int doomsday, int leapYear, int month, int day) {
       int dayOfWeek;
       int doomsdayDay;
       int days;
       int dayDifference;


       doomsdayDay = daysInMonth(6, leapYear) + 6;
       days = daysInMonth(month, leapYear) + day;
       //printf("doomsdayDay: %d, days: %d\n", doomsdayDay, days);
       
       if (days > doomsdayDay){
           dayDifference = (days - doomsdayDay) % DAYS_PER_WEEK;
           //printf("Difference: %d Mod: %d\n", (days-doomsdayDay), dayDifference); 
           dayOfWeek = (doomsday + dayDifference) % 7;
       }

       if (days < doomsdayDay) {
           dayDifference = (doomsdayDay - days) % DAYS_PER_WEEK;
           //printf("Difference: %d Mod: %d\n", (doomsdayDay - days), dayDifference); 
           //dayOfWeek = doomsday - dayBackwards(dayDifference);
           //printf("backwards: %d\n", dayBackwards(dayDifference));
           dayOfWeek = (doomsday + dayBackwards(dayDifference)) % 7;
       }

       if (days == doomsdayDay){
           dayOfWeek = doomsday;
       }
       //printf("%d\n", dayOfWeek);
       return (dayOfWeek);
}

int daysInMonth (int month, int leapYear) {
       int totalDays;

       if (month == 1) {
           totalDays = 0;        
       } 
       if (month == 2) {
           totalDays = JAN; 
       }
       if (month == 3) {
           totalDays = JAN + february(leapYear);        
       } 
       if (month == 4) {
           totalDays = JAN + february(leapYear) + MAR;        
       }
       if (month == 5) {
           totalDays = JAN + february(leapYear) + MAR + APR;        
       } 
       if (month == 6) {
           totalDays = JAN + february(leapYear) + MAR + APR + MAY;        
       }
       if (month == 7) {
           totalDays = JAN + february(leapYear) + MAR + APR + MAY + JUN;        
       } 
       if (month == 8) {
           totalDays = JAN + february(leapYear) + MAR + APR + MAY + JUN + JUL; 
       }
       if (month == 9) {
           totalDays = JAN + february(leapYear) + MAR + APR + MAY + JUN + JUL;
           totalDays = totalDays + AUG;        
       } 
       if (month == 10) {
           totalDays = JAN + february(leapYear) + MAR + APR + MAY + JUN + JUL; 
           totalDays = totalDays + AUG + SEP; 
       }
       if (month == 11) {
           totalDays = JAN + february(leapYear) + MAR + APR + MAY + JUN + JUL;       
           totalDays = totalDays + AUG + SEP + OCT; 
       } 
       if (month == 12) {
           totalDays = JAN + february(leapYear) + MAR + APR + MAY + JUN + JUL; 
           totalDays = totalDays + AUG + SEP + OCT + NOV; 
       }

       return totalDays;
}

int february (int leapYear){
    int days;

    if (leapYear == TRUE){
        days = 29;
    }    
    if (leapYear == FALSE) {
        days = 28;
    }

    return days;
}

int dayBackwards (int backwardsDay) {
    int day;

    if (backwardsDay == 6) {
        day = 1;
    }
    if (backwardsDay == 5) {
        day = 2;
    }
    if (backwardsDay == 4) {
        day = 3;
    }
    if (backwardsDay == 3) {
        day = 4;
    }
    if (backwardsDay == 2) {
        day = 5;
    }
    if (backwardsDay == 1) {
        day = 6;
    }
    if (backwardsDay == 0) {
        day = 0;
    }
    
    return day;
}

