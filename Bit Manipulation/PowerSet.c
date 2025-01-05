#include<stdio.h>
#include<math.h>

void powerSet(int arr[], int n){
    
    
    for(int i = 0; i< pow(2,n); i++){
        
        if(i < 1){
            printf("{}\n");
        }
        else{
            int data = i;
            int pos = 0;
            while(data){
                if((data & 1) == 1){
                    printf("%d", arr[pos]);
                }
                data = data >> 1;
                pos++;
            }
            printf("\n");
        }
    }
}

int main(){
    int arr[] = {1,2,3};

    powerSet(arr, 3);
}