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

    // Bubble Sort , Time complexity is O(n^2)
    for (int j=0; j<n-1; j++){
        for (int i=0; i<n-j-1; i++){
            if (array[i]>array[i+1]){
                int temp=array[i];
                array[i]=array[i+1];
                array[i+1]=temp;
            }
            // // printing in every step
            // for (int i=0; i<n; i++){
            //     printf("%d ",array[i]);  
            // }
            // printf("\n");
        }
    }

printf("Array after Selection Sort: ");
for (int i=0; i<n; i++){
        printf("%d ",array[i]);  
    }
}