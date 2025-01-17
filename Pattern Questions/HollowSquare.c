/*
Hollow Square

1 2 3 4 5       
1       5       
1       5       
1       5       
1 2 3 4 5  
*/

#include<stdio.h>

int main(){
    int n = 5;
    int i,j,k;

    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            if(i == 1 || i == n){
                printf("%d ", j);
            }
            else{
                if(j == 1 || j == n){
                    printf("%d", j);
                    for(k = 1; k <= 2*n-3; k++){
                        printf(" ");
                    }
                }
            }
            
        }
    printf("\n");
    }
}