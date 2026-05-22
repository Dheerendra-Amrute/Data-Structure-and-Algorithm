#include <stdio.h>

// Binary search,  Time complexity is O(logn)

int main(){
    int Array[9] = {10,20,30,40,50,60,70,80,90}; // Array must be storted for binaray search
    int Beg=0, End=9;
    int value;
    int pos=-1;
    printf("Enter the value to search: ");
    scanf("%d",&value);
    while(Beg<=End){
        int mid;
        mid = (Beg+End)/2; 
        if (Array[mid]==value){
            pos=mid;
            break;
        }
        else if (Array[mid]>value){
            End=mid-1;
        }
        else {
            Beg = mid+1;
        }
    }
    if (pos==-1){
        printf("value is not present in the array");
    }
    else{
        printf("Position of the element is %d", pos);
    }
}