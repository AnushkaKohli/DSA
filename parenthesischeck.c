#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c){
    if(top == MAX-1)
        printf("Stack overflow\n");
    else{
        top++;
        stack[top] = c;
    }
}

char pop(){
    if (top == -1)
        printf("Stack underflow\n");
    else
        stack[top--];
}

int main(){
    char exp[MAX], temp;
    int i, flag = 1;
    printf("Enter an expression: ");
    gets(exp);
    for (i = 0; i < strlen(exp); i++){
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
            if(top==-1)
                flag = 0;
            else{
                temp = pop();
                if(exp[i] == ')' && (temp == '{' || temp == '['))
                    flag = 0;
                if(exp[i] == '}' && (temp == '(' || temp == '['))
                    flag = 0;
                if(exp[i] == ']' && (temp == '{' || temp == '('))
                    flag = 0;
            }
    }
    if(top>=0)
        flag = 0;
    if(flag == 1)   
        printf("Valid expression");
    else
        printf("Invalid expression");
}