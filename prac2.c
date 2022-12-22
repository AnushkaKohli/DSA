#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *start=NULL;

void createcll(){
    struct node *newnode,*ptr;
    int num;
    printf("enter -1 to out from the create list\n");
    printf("enter the value of number\n");
    scanf("%d",&num);
    while (num!=-1){
        newnode=(struct node*)malloc(sizeof(struct node));
        if (start==NULL){
            newnode->data=num;
            newnode->next=newnode;
            start=newnode;
        }else{
            ptr=start;
            while(ptr->next!=start){
                ptr=ptr->next;
            }
            newnode->data=num;
            ptr->next=newnode;
            newnode->next=start;
        }
        printf("enter the value of number\n");
        scanf("%d",&num);
    }    
}
void displaycll(){
    struct node *ptr;
    ptr=start;
    while(ptr->next!=start){
        printf("%d \n",ptr->data);
        ptr=ptr->next;
    }
    printf("%d \n",ptr->data);
}
void insertbeg(){
    struct node *newnode, *ptr;
    int num;
    ptr = start;
    printf("enter the number\n");
    scanf("%d",&num);
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    while(ptr->next!= start)
        ptr = ptr->next;
    ptr->next = newnode;
    newnode->next=start;
    start=newnode;
}
void insertend(){
    struct node *newnode,*ptr;
    newnode=(struct node *)malloc(sizeof(struct node));
    int num;
    printf("Enter the number\n");
    scanf("%d",&num);
    ptr = start;
    while(ptr->next!=start){
        ptr=ptr->next;
    }
    newnode->data=num;
    ptr->next=newnode;
    newnode->next=start;

}
int main() {
    int option;
    while(1){
        printf("1-createcll\n");
        printf("2-displaycll\n");
        printf("3-insertbeg\n");
        printf("4-insertend\n");
        printf("5-exit\n");
        printf("enter the option\n");
        scanf("%d",&option);
        switch(option){
            case 1:
                createcll();
                break;
            case 2:
                displaycll();
                break;
            case 3:
                insertbeg();
                break;
            case 4:
                insertend();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("enter the valid option");
        }
    }
    return 0;
}