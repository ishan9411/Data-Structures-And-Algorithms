#include<stdio.h>

void twoUnique(int arr[],int n){
    int xor = 0;
    int set1 = 0;
    int set2 = 0;
    //doing xor to know thich set bit is different in both numbers
    for(int i = 0; i<n; i++){
        xor = xor ^ arr[i];
    }
    //calculate right most bit to differ the numbers in 2 sets
    xor = xor & ~(xor-1);
    for(int i = 0; i<n; i++){
        //(arr[i] & xor) == xor -> non zero(True)
        if(arr[i] & xor){     
            //all numbers having set bit at our xor rightmost bit position
            set1 ^= arr[i];
        }
        else{
            //all numbers having clear bit at our xor rightmost bit position
            set2 ^= arr[i];
        }
    }
    printf("%d , %d", set1, set2);
}

int main(){
    int arr[6] = {1,2,3,2,1,4};

    twoUnique(arr, 6);
}