#include<stdio.h>

long divide(long n, long d){
    //checking sign of the division
    int sign = ((n<0) ^ (d<0)) ? 0 : 1;

    n = abs(n);
    d = abs(d);

    long quotient = 0;

    while(n >= d){           
        int count = 0;
        
        while(n >= (d << (count+1))){         //Ex: 22 >= 3*2^1 -> increase count and again check
            count += 1; 
        }                                    //add largest number with how much we can subtract from dividend Ex: 3*2^2 : q += 2^2
        quotient += (1 << count);            
        n = n - (d << count);                // here we first minus 3 from 22 2^2 i.e. 4 times
    }                                        // subtract that much number from dividend
    return sign ? quotient : -quotient;
}

int main(){
    long n, d;
    printf("Enter dividend: ");
    scanf("%ld", &n);
    printf("Enter divisor: ");
    scanf("%ld", &d);

    long ans = divide(n,d);
    printf("Answer is:%ld", ans);
}   