// Ciarán Mooney
// 2013-2-3
// Creates a cross flag

#include <stdlib.h>
#include <stdio.h>

#define FROM_END 1

void line(int size, int row);
void flag(int size);

int main(int argc, char* argv[]){
    int flag_size;
    scanf("%d", &flag_size);
    flag(flag_size);

    return EXIT_SUCCESS;
}

void line(int size, int row){
    int counter = 0;
    
    while (counter < size){
        if (counter == row || counter == (size-row-FROM_END)){
            printf("#");
        }
        else {
            printf("-");
        }
        counter = counter + 1;
    }
    printf("\n");
}

void flag(int size){
    int counter = 0;

    while (counter < size){
        //printf("counter %d, size %d" ,counter, size); 
        line(size, counter);
        counter = counter + 1;
    }

    printf("\n");

}
