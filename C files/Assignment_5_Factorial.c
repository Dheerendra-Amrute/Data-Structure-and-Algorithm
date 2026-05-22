#include <stdio.h>

int factorial(int n){
    if (n==0 || n==1){
        return 1;
    }
    else{
        return n*factorial(n-1);
    }
}
int main(){
    int num;
    while (1){
    printf("Enter the no. to find the factorial :");
    scanf("%d",&num);
    int fact = factorial(num);
    printf("the factorial of %d is %d\n",num,fact);
    printf("Press 0 for exit and 1 for continue : ");
    int choice;
    scanf(" %d",&choice);
    if (choice==0){
        printf("Exiting...\n");
        break;
    }
    }
}