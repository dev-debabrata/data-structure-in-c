#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *link;
};
struct node *start=NULL;
void dll_insert_at_Begin(int item)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Insufficient Memory");
        exit(0);
    }
    temp->data=item;
    temp->prev=NULL;
    temp->link=start;
    if(start!=NULL)
        start->prev=temp;
    start=temp;
}
void dll_insert_at_End(int item)
{
    struct node *temp, *ptr;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Insufficient Memory");
        exit(0);
    }
    temp->data=item;
    temp->link=NULL;
    if(start==NULL)
    {
        temp->prev=NULL;
        start=temp;
    }
    else
    {
        ptr=start;
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=temp;
        temp->prev=ptr;
    }
}

void dll_insert_at_Any(int item, int pos)
{
    int i;
    struct node *temp, *ptr;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Insufficient Memory");
        exit(0);
    }
    temp->data=item;
    if(pos==1)
    {
        temp->prev=NULL;
        temp->link=start;
        if(start!=NULL)
            start->prev=temp;
        start=temp;
    }
    ptr=start;
    for(i=1; i<=pos-2&&ptr!=NULL; i++)
        ptr=ptr->link;
    if(ptr==NULL)
    {
        printf("Invalid Position");
        free(temp);
        return;
    }
    temp->link=ptr->link;
    if(ptr->link!=NULL)
        ptr->link->prev=temp;
    ptr->link=temp;
    temp->prev=ptr;
}

void dll_deletion_at_Begin()
{
    struct node *ptr;
    if(start==NULL)
    {
        printf("No node in Linked List to delete");
        return;
    }
    ptr=start;
    start=start->link;
    if(start!=NULL)
        start->prev=NULL; //ptr->link
    free(ptr);
    // ptr becomes dangling
    ptr=NULL;
}

void dll_deletion_from_End()
{
    struct node *ptr, *prevptr;
    /*case 1: No node in the Linked List*/
    if(start==NULL)
    {
        printf("No node in Linked List to delete");
        return;
    }
    ptr=start;
    /*case 2: There are exactly one node in the Linked List*/
    if(ptr->link==NULL)
    {
        start=NULL;
    }
    /*case 3: There are more than one node*/
    else
    {
        while(ptr->link!=NULL)
        {
            prevptr=ptr;
            ptr=ptr->link;
        }
        prevptr->link=NULL;
    }
    free(ptr);
    // ptr becomes dangling
    ptr=NULL;
}

void dll_deletion_from_Any(int pos)
{
    struct node *ptr, *prevptr;
    int i;
    if(start==NULL)
    {
        printf("No node in Linked List to delete");
        return;
    }
    ptr=start;
    if(pos==1)
    {
        start=start->link;
        if(start!=NULL)
            start->prev=NULL;
    }
    else
    {
        for(i=1; i<=pos-1; i++)
        {
            prevptr=ptr;
            ptr=ptr->link;
        }
        prevptr->link=ptr->link;
        if(ptr->link!=NULL)
            ptr->link->prev=prevptr;
    }
    free(ptr);
    ptr=NULL;
}

void display()
{
    struct node *ptr;
    if(start==NULL)
    {
        printf("No Node in Linked List to Display");
        return ;
    }
    ptr=start;
    printf("start->");
    while(ptr!=NULL)
    {
        printf("<-%d->", ptr->data);
        ptr=ptr->link;
    }
    printf("NULL");
}

int main(void)
{
    int ch, item, pos;
    while(1)
    {
        printf("\n\n****Double Linked List****\n");
        printf("\n1. Create Double Linked List by insertion at Begin");
        printf("\n2. Create Double Linked List by insertion at End");
        printf("\n3. Insert at Any position of Double Linked List");
        printf("\n4. Delete a node from beginning of Double Linked List");
        printf("\n5. Delete a node from end of Double Linked List");
        printf("\n6. Delete from Any position of Double Linked List except begin and end");

        printf("\n7. Display the Linked List");
        printf("\n8. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            dll_insert_at_Begin(item);
            break;

        case 2:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            dll_insert_at_End(item);
            break;

        case 3:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            printf("Enter the position of insertion: ");
            scanf("%d", &pos);
            dll_insert_at_Any(item, pos);
            break;

        case 4:
            dll_deletion_at_Begin();
            break;

        case 5:
            dll_deletion_from_End();
            break;

        case 6:
            printf("Enter position of deletion except first and last: ");
            scanf("%d", &pos);
            dll_deletion_from_Any(pos);
            break;

        case 7:
            display();
            break;

        case 8:
            exit(0);

        default:
            printf("Wrong Input!!!");
            printf("Please provide correct option next time Onwards");
        }
    }
    return 0;
}
