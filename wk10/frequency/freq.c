// Ciarán Mooney
// 6/2/2013
// Analyse the frequency of letters in a string.

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define STOP -1
#define TRUE 1
#define FALSE 0


#define UPPER_A 65
#define UPPER_Z 90
#define LOWER_A 97
#define LOWER_Z 122
#define ALPHABET 26

void runTests();
void count(char inputString, int *countArray);
int letterCheck(char character);
int letterIndex(char character);
void setupArray (int *unfilledArray);
void output(int *counted, int total);

int main(int argc, char* argv[]){
    runTests ();
    int sumArray[ALPHABET];
    int totalLetters;

    totalLetters = 0;
    setupArray (sumArray);

    int inputChar = getchar();
    while (inputChar != STOP) {
        if (letterCheck(inputChar) == TRUE){
            count (inputChar, sumArray);
            totalLetters = totalLetters + 1;
        }
        inputChar = getchar();
    }

    output(sumArray, totalLetters);
    return EXIT_SUCCESS;
}

void runTests (){
    assert (letterCheck('a') == TRUE);
    assert (letterCheck('z') == TRUE);
    assert (letterCheck('A') == TRUE);
    assert (letterCheck('Z') == TRUE);
    assert (letterCheck('@') == FALSE);
    assert (letterCheck('[') == FALSE);
    assert (letterCheck('`') == FALSE);
    assert (letterCheck('{') == FALSE);
    
    assert (letterIndex('a') == 0);
    assert (letterIndex('z') == 25);
    assert (letterIndex('A') == 0);
    assert (letterIndex('Z') == 25);

    int testArray[ALPHABET];
    setupArray (testArray);
    assert (testArray[0] == 0);
    assert (testArray[24] == 0);
    assert (testArray[25] == 0);

    count ('a', testArray);
    assert (testArray[0] == 1);
    count ('a', testArray);
    assert (testArray[0] == 2);

    printf ("All tests passed.\n");
}

void count (char inputString, int *countArray){ 
    int charIndex;
    int letterTotal;

    charIndex = letterIndex(inputString);
    letterTotal = countArray[charIndex];
    letterTotal = letterTotal + 1;
    countArray[charIndex] = letterTotal;

}

int letterCheck(char character){
    int isLetter;

    isLetter = FALSE;

    if (character >= UPPER_A && character <= UPPER_Z){
        isLetter = TRUE;
    }
    if (character >= LOWER_A && character <= LOWER_Z){
        isLetter = TRUE;
    }
    
    return isLetter;
}

int letterIndex(char character){
    int index;
    
    if (character >= UPPER_A && character <= UPPER_Z){
        index = character - UPPER_A;
    }
    if (character >= LOWER_A && character <= LOWER_Z){
        index = character - LOWER_A;
    }
    
    return index;
}

void setupArray (int *unfilledArray){
    int letter;
    letter = 0;

    while (letter < ALPHABET) {
        unfilledArray[letter] = 0;
        letter = letter + 1;
        
    }
}

void output(int *counted, int total){
    char current;
    int letter;

    current = 'a';
    letter = 0;

    while (letter < ALPHABET){
        printf ("%c-%d/%d\n", current, counted[letter], total);
        letter = letter + 1;
        current = current + 1;
    }
}
