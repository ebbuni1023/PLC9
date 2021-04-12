#include <stdio.h>

int main(void){
    // local variable
    // scope of the variable i and x
    int i;
    int x;
    // for loop
    // beginning a new block which is local to the block
    for (i = 0; i < 10; i++)
    {
        x += i;
    }
    // global variable
    // a variable is visible after the body of the for statement
    printf("%d", x);
}