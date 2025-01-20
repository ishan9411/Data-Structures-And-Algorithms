/*
Hollow Hourglass Pattern

ABCDEFGHI
 A     G
  A   E
   A C
    A
   A C
  A   E
 A     G
ABCDEFGHI
*/

#include<stdio.h>

int main(){
    int n = 5;
    int i,j,k;
    int a = 2*n-1;                //for a single row alphabets
    int hollowSpace = 2*n-5;     //works for spaces of hollow
    int spaces = 0;

    for(i = 1; i <= 2*n-1; i++){
        char alpha = 'A';
        for(j = 1; j <= spaces; j++){
            printf(" ");
        }
        for(j = a; j > 0; j--){
            if(i == 1 || i == 2*n-1){
                printf("%c", alpha);
                alpha++;
            }
            else{
                if(j == a || j == 1){
                    printf("%c", alpha);
                    for(k = hollowSpace; k > 0; k--){
                        printf(" ");
                    }
                }
                alpha++;
            }
        }
        if(i < n){
            spaces++;
            a = a - 2;
            if(i != 1){
                hollowSpace = hollowSpace - 2;
            }
        }
        else{
            spaces--;
            a = a + 2;
            hollowSpace = hollowSpace + 2;
        }
        printf("\n");
    }
}