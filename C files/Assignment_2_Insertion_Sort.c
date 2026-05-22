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

    // Insertion Sort , Time Complexity O(n^2) , Best case O(n)

    for (int i=1; i<n; i++){
        
        int value = array[i]; //current value
        int prev = i-1;        // previous index
        while (value < array[prev] && prev>=0){   //
            array[prev+1]=array[prev]; //shift the right side
            prev=prev-1;
        }
        array[prev+1]=value; // inserting the value at their position

        // printing in every step
            for (int i=0; i<n; i++){
                printf("%d ",array[i]);  
            }
            printf("\n");
        }

    // printing the Array after sorting
    printf("Array after Intertion Sort: ");
    for (int i=0; i<n; i++){
        printf("%d ",array[i]);  
    }
    }


