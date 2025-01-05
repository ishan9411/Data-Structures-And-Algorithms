#include<stdio.h>

int countSetBits(int n){
    int count = 0;
    while(n){
        if((n&1) == 1){
            count++;
        }
        n = n >> 1;
    }
    return count;
}

int totalSetBits(int n){
    int total = 0;
    for(int i = 1; i <= n; i++){
        total += countSetBits(i);
    }
    return total;
}

int main(){
    int n;
    printf("Enter number upto which you want total set bits:");
    scanf("%d", &n);

    printf("Total Set Bits are: %d", totalSetBits(n));
}