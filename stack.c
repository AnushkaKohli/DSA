#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int stack[MAX], top = -1;

void push(){
    int num;
    if(top==MAX-1)
        printf("STACK OVERFLOW!\n");
    else{
        printf("Enter the value you want to push: ");
        scanf ("%d", &num);
        top++;
        stack[top] = num;
    }
}

void pop(){
    int num;
    if(top == -1)
        printf("STACK UNDERFLOW!\n");
    else{
        printf("The value deleted from stack is: %d\n", stack[top]);
        top--;
    }
}

void peek(){
    if(top==-1)
        printf("The stack is empty\n");
    else
        printf("The value at the top of the stack is: %d\n", stack[top]);
}

void print(){
    int i;
    if(top==-1)
        printf("The stack is empty\n");
    else{
        for(i = top; i>=0; i--)
            printf("%d ", stack[i]);
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