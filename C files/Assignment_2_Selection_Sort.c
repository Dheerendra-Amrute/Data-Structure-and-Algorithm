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

    // Selection sort , Time Complexity is O(n^2)
    for (int i=0; i<n-1; i++){
        int minimum = array[i];
        int index_of_min=i;
        for (int j=i+1; j<n; j++){
            if (minimum>array[j]){
                minimum=array[j];
                index_of_min=j;
            }
            else {
                continue;
            }
            }
            int temp=array[i];
            array[i]=minimum;
            array[index_of_min]=temp;

            // printing in every step
            for (int i=0; i<n; i++){
                printf("%d ",array[i]);  
            }
            printf("\n");

        }

printf("Array after Selection Sort: ");
for (int i=0; i<n; i++){
        printf("%d ",array[i]);  
    }

}

