#include<stdio.h>

int posOfSetBit(int n){
    int pos = 0;
    int count = 0;
    while(n){
        if((n & 1) == 1){
            count++;
        }
        if(count > 1){
            return -1;
        }
        n = n >> 1;
        pos ++;
    }
    return pos;

}

int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int pos = posOfSetBit(n);
    if(pos != -1){
        printf("Position of only set bit is %d", pos);
    }
    else{
        printf("Invalid Number");
    }
}