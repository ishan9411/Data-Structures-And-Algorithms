/*
Alphabet Pattern

A        A
AB      BA
ABC    CBA
ABCD  DCBA
ABCDEEDCBA

*/

#include<stdio.h>

int main(){
    int n = 5;
    int i,j;
    int spaces = 2*n - 2;
    
    for(i = 1; i <= n; i++){
        char alpha = 'A';
        for(j = 1; j <= i; j++){
            if(j == 1){
                printf("%c", alpha);
                continue;
            }
            alpha++;
            printf("%c", alpha);
        }
        for(j = 1; j <= spaces; j++){
            printf(" ");
        }
        for(j = 1; j <= i; j++){
            if(i == 1){
                printf("A");
                continue;
            }
            printf("%c", alpha);
            alpha--;
        }
        printf("\n");
        spaces = spaces - 2;
    }
}