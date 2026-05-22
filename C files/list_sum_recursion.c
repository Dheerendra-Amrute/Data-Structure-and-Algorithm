#include <stdio.h>


int sum_rec(int array[],int index){
    if (index<=0)
        return 0;
    return array[index-1]+sum_rec(array,index-1);
}

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
    int sum=sum_rec(array,n);
    printf("the sum of elements of array is %d \n",sum);
}