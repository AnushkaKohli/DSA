#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *left;
    int data;
    struct node *right;
};

struct node *create(){
    struct node *newnode;
    int x;
    newnode = (struct node *) malloc (sizeof(struct node));
    printf("Enter -1 for no node\n");
    printf("Enter the data: ");
    scanf("%d", &x);
    if (x == -1)
        return 0;
    newnode->data = x;
    printf("Enter the left child of %d: ", x);
    printf("\n");
    newnode->left = create();
    printf("Enter right child of %d: ", x);
    printf("\n");
    newnode->right = create();
    return newnode;
}

void preorder(struct node *root){
    if(root==NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root){
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void postorder(struct node *root){
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main(){
    struct node *root;
    root = NULL;
    root = create();
    printf("Pre-order is: ");
    preorder(root);
    printf("\n");
    printf("In-order is: ");
    inorder(root);
    printf("\n");
    printf("Post-order is: ");
    postorder(root);
    return 0;
}