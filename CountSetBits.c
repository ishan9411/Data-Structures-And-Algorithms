#include<stdio.h>
#include<stdlib.h>

int countSetBits(int n){
    int count = 0;
    while(n != 0){
        if((n & 1) == 1){
            count++;
        }
        n = n >> 1;
    }
    return count;
}

int main(){
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);

    printf("No. of set bits are: %d", countSetBits(n));

    return 0;
}