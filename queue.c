#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int queue[MAX], front = -1, rear = -1;

void insert(){
    int num;
    printf("Enter the element you want to insert: ");
    scanf("%d", &num);
    if(rear == MAX -1)
        printf("OVERFLOW\n");
    else{
        if(front==-1 && rear ==-1)
            front = 0;
        rear++;
        queue[rear] = num;
    }
}

void delete(){
    if((front==-1) || (front > rear))
        printf("Queue is empty - UNDERFLOW\n");
    else{
        printf("The element deleted is: %d\n", queue[front]);
        front++;
        if(front > rear)
            front = rear = -1;
    }
}

void peek(){
    if((front==-1) || (front > rear))
        printf("Queue is empty - UNDERFLOW\n");
    else
        printf("The first element in the queue is: %d\n", queue[front]);
}

void display(){
    int i;
    if((front==-1) || (front > rear))
        printf("Queue is empty - UNDERFLOW\n");
    for(i=front; i<=rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main(){
    int ch;
    do{
        printf("1.Insert\n2.Delete\n3.Peek\n4.Display\n5.Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
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