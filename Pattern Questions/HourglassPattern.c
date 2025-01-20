/*
Hourglass Pattern 

ABCDEFGHI
 ABCDEFG 
  ABCDE  
   ABC   
    A    
   ABC   
  ABCDE  
 ABCDEFG 
ABCDEFGHI

*/
#include<stdio.h>

int main(){
    int n = 5;
    int i,j;
    int a = 2*n-1;
    int spaces = 0;
    for (i = 1; i <= 2*n-1; i++){
        char alpha = 'A';
        for(j = 1; j <= spaces; j++){
            printf(" ");
        }
        for (j = a; j > 0;  j--){
            printf("%c ", alpha);
            alpha++;
        }
        if(i < n){
            spaces = spaces + 2;
            a = a - 2;
        }
        else{
            spaces = spaces -2;
            a = a + 2;
        }
    printf("\n");
    }
}