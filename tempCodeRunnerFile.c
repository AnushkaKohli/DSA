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