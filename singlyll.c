#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

void create(){
    struct node *new_node, *ptr;
    int num;
    printf("Enter -1 to end the list.\n");
    printf("Enter the data: ");
        scanf("%d", &(num));
    while (num != -1) {

        new_node = (struct node *) malloc (sizeof(struct node));

        //Individual isolated nodes are created
 
        //Each isolated node is added to the list.
        //If the first node is added, head is null and the data at new node is the first data and head stores the address of new node
        if (head == NULL){
            new_node->data = num;
            new_node->next = NULL;
            head = new_node;
        }

        //A node other than the first node is added so a ptr is used to iterate through the list. A new node is added at the end of the list
        //45-> 34-> 11-> NULL        65-> NULL
        //45-> 34-> 11-> 65-> NULL
        else
        {
            ptr = head;
            while (ptr->next != NULL)
                ptr = ptr->next;
            
            new_node->data = num;
            ptr->next = new_node; 
            new_node->next = NULL;
        } 
        printf("Enter the data: ");
        scanf("%d", &(num));   
    } 
} 

void display(struct node *head){
    struct node *ptr = head;
    if (head == NULL)
    {
        printf("List is empty.");
        return;
    }
    while (ptr!=NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

void insert_beg(){
    struct node *ptr;
    ptr = (struct node *) malloc (sizeof(struct node));
    printf("\nEnter the data you want to insert at the beginning: ");
    scanf("%d", &(ptr->data));
    
    if (head==NULL){
        head = ptr;
        ptr->next = NULL;
    }

    ptr->next = head;
    head = ptr;
    printf("Node inserted at beginning.\n");
}

void insert_end(){
    struct node *ptr, *temp;
    int num;
    ptr = (struct node *) malloc (sizeof(struct node));
    printf("\nEnter the data you want to insert at the end: ");
    scanf("%d", &(ptr->data));
    ptr->next = NULL;
    if(head==NULL)
        head = ptr;
    else{
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = ptr;
    }
    printf("Node inserted at end.\n");
}

int size(){
    struct node *ptr;
    int count;
    ptr = head;
    while (ptr->next != NULL)
        count++;
    return count;
}

void insert_pos(){
    struct node *newnode, *ptr, *preptr;
    int pos, count;
    newnode = (struct node *) malloc (sizeof(struct node));
    printf("\nEnter the data you want to insert: ");
    scanf("%d", &(newnode->data));
    printf("\nEnter the position after which you want to insert: ");
    scanf("%d", &pos);
    count = size();
    if(pos>count)
        printf("Invalid Position\n");
    else{
        ptr = head;
        while (pos!=0){
            preptr = ptr;
            ptr = ptr->next;
            pos--;
        }
        preptr->next = newnode;
        newnode->next = ptr;
    }
    printf("Node has been inserted after %d position", pos);
}

void search(){
    struct node *ptr = head;
    int val;
    printf("Enter the element you want to search: ");
    scanf("%d", &val);
    while (ptr!=NULL){
        if(ptr->data == val){
            printf("The element has been found!\n");
            return;
        }
        else
            ptr = ptr->next;
    }
    printf("Element is not present in the list\n");
}

int main()
{
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
                insert_beg();
                break;
            case 4:
                insert_end();
                break;
            case 5:
                insert_pos();
                break;
            // case 6:
            //     create();
            //     break;
            // case 7:
            //     create();
            //     break;
            // case 8:
            //     create();
            //     break;
            case 9:
                search();
                break;
            // case 10:
            //     create();
            //     break;
            // case 11:
            //     create();
            //     break;
            case 12:
                size();
                break;
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

