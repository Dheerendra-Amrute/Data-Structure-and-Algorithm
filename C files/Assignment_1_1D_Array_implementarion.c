#include<stdio.h>
void Traverse();
void Insert();
void Delete();
void Search();
void exit();
void main(){
    int n;
    int no_of_element;
    printf("Enter the no. of elements in the list : ");
    scanf("%d" ,&no_of_element);
    int array[no_of_element];
    for (int i=0; i< no_of_element; i++){
        int element;
        printf("Enter the %d element : ",i+1);
        scanf("%d",&element);
        array[i]=element;
    }
    while(1){
        printf("\n***** Implementation of 1D array *****\n\n");
        printf("1. Traverse\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Search\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &n);
        switch(n){
        case 1:
            Traverse(array,no_of_element);
            break;
        case 2:
            Insert(array,no_of_element);
            break;
        case 3:
            Delete(array,no_of_element);
            break;
        case 4:
            Search(array,no_of_element);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid Choice...\n\n");
        }
}
    }
void Traverse(int array[],int no_of_element){
    printf("array :");
    for(int i=0; i< no_of_element; i++){
        printf("%d ",array[i]);
    }
    printf("\n\n");
}
void Insert(int array[],int no_of_element){
    if ((array[no_of_element-1] != 0)){
        printf("array is full........\n\n");
    }
    else{
    printf("Enter the number to insert : ");
            int num;
            scanf("%d",&num);
            printf("Enter the positive index where to insert : ");
            int index;
            scanf("%d",&index);
            if (0 <= index && index < no_of_element){
                for(int i=(no_of_element-1); i>=index; i-- ){
                    array[i] = array[i-1];
                    if (index == i){
                        array[index]= num;
                    }
                }
            }
            else{
                printf("Entered index does not exist in list\n"); 
    }
}
}

void Delete(int array[],int no_of_element){
    printf("Enter the Number to delete : ");
            int num1;
            int index_to_del;
            scanf("%d",&num1);
            for(int i=0; i<no_of_element; i++){
                if (array[i]==num1){
                    index_to_del=i;
                    break;
                }
                else{
                    continue;
                }
            }
            if (array[index_to_del]==num1){
                for(int i=index_to_del; i<no_of_element; i++ ){
                    if (array[i]!= 0 && (i+1<no_of_element)){
                        array[i] = array[i+1];
                    }
                    else{
                        array[i]= 0;
                        break;;
                    }
                    }
                }
            else{
                printf("Entered no. does not exist in the list \n");
            }
 }

 void Search(int array[],int no_of_element){
    printf("Enter the Number to Search : ");
    int num2;
    int index_of_num2;
    scanf("%d",&num2);
    for(int i=0; i<no_of_element; i++){
        if (array[i]==num2){
            index_of_num2=i;
            break;
        }
        else{
            continue;
            }
    }
    if (array[index_of_num2]==num2){
            printf("The index of the entered element is : %d \n", index_of_num2);
    }
    else{
        printf("Entered element does not exist in the array\n");
        }
 }
