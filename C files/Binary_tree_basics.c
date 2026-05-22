 #include <stdio.h>
 #include <stdlib.h>

 struct node {
    int data;
    struct node* left;
    struct node* right;
 };

struct node* createnode(int Data){
    struct node* newnode;
    newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data=Data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

 int main(){
    struct node* p = createnode(5);
    struct node* p1 = createnode(6);
    struct node* p2 = createnode(7);

    p->left = p1;
    p->right = p2;

    return 0;
 }