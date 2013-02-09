// Ciarán Mooney
// 14/1/13 (British Format)
// Outputs a Danish flag using a nest loop


#include <stdlib.h>
#include <stdio.h>

void showDanish(void);
void printLine(void);

int main(int argc, char* argv[]){

    showDanish();
    return EXIT_SUCCESS;
}

void showDanish(void){
    
    int flagCounter = 1;
    int firstLineCounter = 1;
    int secondLineCounter= 1;
    
    while (flagCounter <= 1){
        while (firstLineCounter<= 2){
            printLine();
            firstLineCounter++;
        }
    
        printf("\n");
        while (secondLineCounter<= 2){
            printLine();
            secondLineCounter++;
        }

        flagCounter++;
    }
}

void printLine(void){
    printf("** *********\n");
}
