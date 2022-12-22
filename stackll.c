#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int data;
    struct stack *next;
} st;

struct stack *top = NULL;

void push(){
    st* newnode;
    newnode = (st*) malloc (sizeof(st));
    printf("Enter the data you want to push: ");
    scanf("%d", &(newnode->data));
    if(top==NULL){
        newnode->next = NULL;
        top = newnode;
    }
    else{
        newnode->next = top;
        top = newnode;
    }
}

void pop(){
    st* ptr = top;
    if(top==NULL)
        printf("The stack is empty!\n");
    else{
        printf("The value deleted from the top of the stack is: %d\n", top->data);
        top = top->next;
        free(ptr);
    }
}

void peek(){
    if(top==NULL)
        printf("The stack is empty!\n");
    else
        printf("The element at the top of the stack is: %d", top->data);
}

void print(){
    st* ptr = top;
    if(top==NULL)
        printf("The stack is empty!\n");
    while (ptr!=NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }  
    printf("\n");
}

int main(){
    int ch;
    do{
        printf("1.Push\n2.Pop\n3.Peek\n4.Print\n5.Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                print();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Enter a valid choice!\n");
        }
    }while(ch != 5);
    return 0;
}