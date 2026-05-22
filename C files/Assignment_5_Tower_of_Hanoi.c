#include <stdio.h>

int Passess = 0;
void Tower_of_Hanoi(int n, char A, char B, char C){
    if (n==1){
        printf("Move first Disk form %c to %c \n",A,C);
        Passess++;
        return;
    }
    else{ 
        Tower_of_Hanoi( n-1,A,C,B);
        printf("Move %d disk from %c to %c \n",n,A,C);
        Tower_of_Hanoi(n-1,B,A,C);
        Passess++;
    }
}
int main(){
    int n;
    printf("Enter the no. of disks :");
    scanf("%d",&n);
    if(n<1){
        printf("Enter the valid no. of disks...");
    }
    Tower_of_Hanoi(n,'A','B','C');
    printf("Total no. of Passess : %d",Passess);
    return 0;
}