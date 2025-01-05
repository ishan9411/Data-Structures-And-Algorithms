#include<stdio.h>

int squareUsingBit(int n){
    int pos = 0;
    int square = 0;
    int temp_n = n;
    while(n){
        //ex: n = 10101 ; n^2 = n*(2^4 + 2^2 + 2^0)
        //n^2 = (n << 4) + (n << 2) + (n << 0)      
        if((n & 1) == 1){
            square += (temp_n << pos);
        }
        n = n >> 1;
        pos++;
    }
    return square;
}

int main(){
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    if(n<0){
        n = -n;
    }
    int square = squareUsingBit(n);
    printf("%d", square);
}