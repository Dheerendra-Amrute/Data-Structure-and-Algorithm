#include <stdio.h>

int main(){
    //Input array from the user
    int n;
    printf("Enter the no of element in the array1: ");
    scanf("%d",&n);
    int array1[n];
    for (int i=0; i<n; i++){
        printf("Enter the Element %d : ",i+1);
        scanf("%d",&array1[i]);
    }

    // printing entered list
    printf("Array1 : ");
    for (int i=0; i<n; i++){
        printf("%d ",array1[i]);  
    }
    printf("\n");

    int m;
    printf("Enter the no of element in the array2: ");
    scanf("%d",&m);
    int array2[m];
    for (int i=0; i<m; i++){
        printf("Enter the Element %d : ",i+1);
        scanf("%d",&array2[i]);
    }

    // printing entered list
    printf("Array2 : ");
    for (int i=0; i<m; i++){
        printf("%d ",array2[i]);  
    }
    printf("\n");

    int array3[m+n];
    int i=0;
    int j=0;
    while (i<m+n){
        if (i<n){
            array3[i]=array1[i];
        }
        else{
            array3[i]=array2[j];
            j++;
        }
        i++;
    }
    printf("Array3 : ");
    for (int i=0; i<m+n; i++){
        printf("%d ",array3[i]);  
    }
    printf("\n");

}
