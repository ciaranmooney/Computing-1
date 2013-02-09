// Ciarán Mooney
// 13/01/2013 (British format)
// ROT 13 en/de-coder

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0

char rot(char cipher, int ROT);
int testEncode();
char encode (char letter);

int main (int argc, const char * argv[]){
    testEncode();
    printf("%c", encode('a'));
    return EXIT_SUCCESS;
}

char encode(char letter){
    char plain;

    plain = rot(letter, 13);
    printf("%c, %c\n", letter, plain);
    return plain;
}


char rot(char cipher, int ROT){
    char position;
    int plain;
    int base;
    int totalLetters;

    int uppercase;
    int lowercase;
    int symbol;
    
    totalLetters = 26;
    uppercase =  (cipher >= 65) && (cipher  <= 90);
    lowercase =  (cipher >= 97) && (cipher  <= 122);
    symbol = (uppercase == FALSE) && (lowercase == FALSE);

    //printf("u:%d l:%d s:%d \n", uppercase, lowercase, symbol);

    if (lowercase){
        base = 97;
     
        position = ((cipher + ROT) - base) % totalLetters;
        plain = position + base; 
    }
    
    if (uppercase){
        base = 65;
     
        position = ((cipher + ROT) - base) % totalLetters;
        plain = position + base;
    }

    if (symbol){
        plain = cipher;
    }
    return plain;
}

int testEncode(){

    assert(encode('h')=='u');
    assert(encode('u')=='h');
    assert(encode('m')=='z');
    assert(encode('p')=='c');
    assert(encode('t')=='g');
    assert(encode('y')=='l');
    assert(encode('z')=='m');
    assert(encode('Z')=='M');
    assert(encode('Y')=='L');
    assert(encode('.')=='.');
    assert(encode('@')=='@');
    assert(encode('`')=='`');
    assert(encode('[')=='[');
    assert(encode('{')=='{');
    printf("Tests passed. Well Done\n");
    return EXIT_SUCCESS;

}

