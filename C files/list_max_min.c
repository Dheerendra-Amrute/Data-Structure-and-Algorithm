#include <stdio.h>

int main(){
    //Input array from the user
    int n;
    printf("Enter the no of element in the array: ");
    scanf("%d",&n);
    int array[n];
    for (int i=0; i<n; i++){
        printf("Enter the Element %d : ",i+1);
        scanf("%d",&array[i]);
    }

    // printing entered list
    printf("Array : ");
    for (int i=0; i<n; i++){
        printf("%d ",array[i]);  
    }
    printf("\n");

    int max=array[0];
    int min=array[0];
    for(int i=0; i<n; i++){
        if (array[i]>max){
            max=array[i];
        }
        else if(array[i]<min){
            min=array[i];
        }
        else{
            continue;
        }
    }

    printf("maximum = %d \n minimum = %d ", max,min);
}