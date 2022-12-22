#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;

// void create(){
//     struct node *newnode, *ptr;
//     int num;
//     printf("Enter -1 to end the list\n");
//     printf("Enter the data: ");
//     scanf("%d", &num);
//     while (num != -1){
//         newnode = (struct node*) malloc (sizeof(struct node));
//         newnode->data = num;
//         if (head == NULL){
//             head = newnode;
//             newnode->next = NULL;
//         }
//         else{
//             ptr = head;
//             while(ptr->next != NULL)
//                 ptr = ptr->next;
//             ptr->next = newnode;
//             newnode->next = NULL;
//         }  
//         printf("Enter the data: ");
//         scanf("%d", &num);    
//     }    
// }

void create(){
    struct node *newnode, *ptr;
    int num;
    printf("Enter -1 to end the list\n");
    printf("Enter the data: ");
    scanf("%d", &num);
    while(num!=-1){
        newnode = (struct node*) malloc (sizeof(struct node));
        newnode->data = num;
        if(head==NULL){
            newnode->next = NULL;
            head = newnode;
        }
        else{
            ptr = head;
            while(ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = newnode;
            newnode->next = NULL;
        }
        printf("Enter -1 to end the list\n");
        printf("Enter the data: ");
        scanf("%d", &num);
    }
}

void display(){
    struct node *ptr = head;
    if (head==NULL)
    {
        printf("The list is empty\n");
        return;
    }
    
    while (ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }   
}

void insertbeg(){
    struct node *newnode;
    newnode = (struct node *) malloc (sizeof(struct node));
    printf("Enter the value to be inserted at beginning: ");
    scanf("%d", &(newnode->data));
    if (head == NULL){
        head = newnode;
        newnode->next = NULL;
    }
    else{
        newnode->next = head;
        head = newnode;
    }
}

void insertend(){
    struct node *newnode, *ptr;
    ptr = head;
    while(ptr->next != NULL)
        ptr = ptr->next;
}

void reverse(){
    struct node* current = head, *prev = NULL, *next = NULL;
    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main(){
    int ch;
    while (ch!=13){
    printf("\n1.Create\n2.Display\n3.Insert at beginning\n4.Insert at end\n5.Insert after given position\n6.Delete from beginning\n7.Delete from end\n8.Delete from given position\n9.Search an element\n10.Reverse the list\n11.Sort the list\n12.Count the number of elements in the list\n13.Exit\n\nEnter your choice: ");
    scanf("%d", &ch);
        switch (ch){
            case 1:
                create();
                break;
            case 2:
                display(head);
                break;
            case 3:
                insertbeg();
                break;
            case 4:
                insertend();
                break;
            // case 5:
            //     insert_pos();
            //     break;
            // // case 6:
            // //     create();
            // //     break;
            // // case 7:
            // //     create();
            // //     break;
            // // case 8:
            // //     create();
            // //     break;
            // case 9:
            //     search();
            //     break;
            case 10:
                reverse();
                break;
            // // case 11:
            // //     create();
            // //     break;
            // case 12:
            //     size();
            //     break;
            case 13:
                printf("Program was terminated\n");
                break;
    
            default:
                printf("Enter a valid choice!\n");
                break;
        }       
    }
    return 0;
}
