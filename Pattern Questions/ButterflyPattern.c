/*
Butterfly Pattern for n = 5

*       *
**     **
***   ***
**** ****
*********
**** ****
***   ***
**     **
*       *

*/

#include<stdio.h>

int main(){
    int n = 5;

    int spaces = 2*n -1;
    int stars = 0;
    int j,i;
    for(i = 1; i <= 2*n-1; i++){
        if(i <= n){
            spaces = spaces - 2;
            stars++;
        }
        else{
            spaces = spaces + 2;
            stars--;
        }
        for(j = 1; j<=stars; j++){
            printf("*");
        }
        for(j = 1; j <= spaces; j++){
            printf(" ");
        }
        for(j = 1; j<=stars; j++){
            if(j == n){
                continue;
            }
            printf("*");
        }
    printf("\n");
    }
}