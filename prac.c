#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *start=NULL;

struct node *createll(struct node *start){
    struct node *newnode,*ptr;
    int num;
    printf("\nenter the value -1 to come out from the craete list\n");
    // printf("enter the data\n");
    // scanf("%d",&num);
    while(num!=-1){
        printf("enter the data\n");
        scanf("%d",&num);
        newnode=(struct node *)malloc(sizeof(struct node));
        
        if(start==NULL){
            newnode->data=num;
            newnode->next=NULL;
            start=newnode;
        }else{
            ptr=start;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            newnode->data=num;
            ptr->next=newnode;
            newnode->next=NULL;
        }
        
    }
    return start;
}
struct node *displayll(struct node *start){
    struct node *ptr;
    ptr=start;
    
    while(ptr!=NULL){
            printf("%d ",ptr->data);
            ptr=ptr->next;
    }
    printf("\n");
    return start;
}
struct node *insertbeg(struct node *start){
    
}
int main() {
    // Write C code here
    int option;
    while(1){
        printf("1-create\n");
        printf("2-display\n");
        printf("3-exit\n");
        printf("enter the option\n");
        scanf("%d",&option);
        switch(option){
            case 1:
                start=createll(start);
                break;
            case 2:
                start=displayll(start);
                break;
            case 3:
                exit(0);
            default:
                printf("enter the valid option");
        }
    }

    return 0;
}