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

    for(int i=0; i<n/2; i++){
        int temp = array[i];
        array[i]=array[n-i-1];
        array[n-i-1]=temp;
    }

    printf("Reveresed Array is \n");
    for (int i=0; i<n; i++){
        printf("%d ",array[i]);  
    }
    printf("\n");


}