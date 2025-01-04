#include<stdio.h>
#include<stdbool.h>

bool powerOfTwo(int n){
    if(n < 1){
        return false;
    }
    return((n & (n-1)) == 0);
}

int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if(powerOfTwo(n)){
        printf("%d is a power of 2", n);
    }
    else{
        printf("%d is a not power of 2", n);
    }
}