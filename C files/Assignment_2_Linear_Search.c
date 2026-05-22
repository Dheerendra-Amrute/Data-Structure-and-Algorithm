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

    // linear Search , complexity O(n)
    printf("Enter the number to find: ");
    int find;
    int index;  // to store the location of the number 
    scanf("%d",&find);
    for (int i=0; i<n; i++ ){
        if (array[i]==find){
            index = i;
            break;
        }
        else {
            continue;
        }     
    }
    if (array[index]==find){
        printf("element is found at index %d ", index);
    }
    else {
        printf("element is not found");
    }
}