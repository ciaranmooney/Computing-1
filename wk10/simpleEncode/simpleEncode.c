/*
*  simpleEncode.c
*
*  reads in a permutation of the alphabet then encodes
*  lower case letters using that permutation
*
*  Created by Julian Saknussemm on 01/04/11.
*  Copyright 2011 Licensed under Creative Commons SA-BY-NC 3.0.
*
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
#define STOP -1
#define ALPHABET_SIZE 26
#define A_ASCII 97
#define Z_ASCII 122


char encode (int plainChar, char *permuation);
void testEncode (void);
 
int main (int argc, char *argv[]) {
 
   testEncode();
 
   char permutation[ALPHABET_SIZE];
 
   scanf ("%s", permutation);
 
   // getchar() reads and returns one character from the keyboard
   // returns -1 when it reads end-of-file character (^D in linux)
   int plainCharacter = getchar();
   while (plainCharacter != STOP) {
	  int encodedCharacter = encode (plainCharacter, permutation);
	  printf ("%c", encodedCharacter);
	  plainCharacter = getchar();
   }
   return EXIT_SUCCESS;
}
 
void testEncode (void) {
   assert (encode ('A',"abcdefghijklmnopqrstuvwxyz") == 'A');
   assert (encode ('?',"abcdefghijklmnopqrstuvwxyz") == '?');
   assert (encode (' ',"abcdefghijklmnopqrstuvwxyz") == ' ');
   assert (encode ('\n',"abcdefghijklmnopqrstuvwxyz") == '\n');
 
   assert (encode ('a',"abcdefghijklmnopqrstuvwxyz") == 'a');
   assert (encode ('m',"abcdefghijklmnopqrstuvwxyz") == 'm');
   assert (encode ('z',"abcdefghijklmnopqrstuvwxyz") == 'z');
 
   assert (encode ('a',"bcdefghijklmnopqrstuvwxyza") == 'b');
   assert (encode ('m',"bcdefghijklmnopqrstuvwxyza") == 'n');
   assert (encode ('z',"bcdefghijklmnopqrstuvwxyza") == 'a');
 
   assert (encode ('a',"qwertyuiopasdfghjklzxcvbnm") == 'q');
   assert (encode ('b',"qwertyuiopasdfghjklzxcvbnm") == 'w');
   assert (encode ('z',"qwertyuiopasdfghjklzxcvbnm") == 'm');

   printf("All tests passed.\n");
}
 
char encode (int plainChar, char *permutation) {
    char cipher;

    printf("Calling encode ('%c', \"%s\")...\n", plainChar, permutation );

    if (plainChar >= A_ASCII && plainChar <= Z_ASCII){
        plainChar = plainChar - A_ASCII;
        cipher = permutation[plainChar];
    }
    else {
        cipher = plainChar;      
    }

    return cipher;
}
