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

void bitsToFlip(int a, int b){
    int xor = a^b;
    //set bits in a^b will tell us how many minimum bits are different to convert
    int count = countSetBits(xor);
    printf("Number of bits to be flipped are: %d", count);
}

int main(){
    int a,b;
    printf("Enter A number: ");
    scanf("%d", &a);
    printf("Enter B number: ");
    scanf("%d", &b);
    bitsToFlip(a,b);

}