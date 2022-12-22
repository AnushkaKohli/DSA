#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void traversal(struct node *ptr){
    while (ptr!=NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }   
}

int main()
{
    struct node* head;
    struct node* second;
    struct node* third;

    //Allocate memory for nodes in the linked list in heap
    head = (struct node*) malloc (sizeof(struct node));
    second = (struct node*) malloc (sizeof(struct node));
    third = (struct node*) malloc (sizeof(struct node));

    //Link first and second nodes
    head->data = 7;
    head->next = second;

    //Link second and third nodes
    second->data = 10;
    second->next = third;

    //TTerminate the list at third node
    third->data = 2;
    third->next = NULL;

    traversal(head); 
    return 0;
}
