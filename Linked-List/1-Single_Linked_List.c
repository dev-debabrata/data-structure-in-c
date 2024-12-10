#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *start=NULL;
void sll_insert_at_End(int item)
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
        start=temp;
    else
    {
        ptr=start;
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=temp;
    }
}
void sll_insert_at_Begin(int item)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Insufficient Memory");
        exit(0);
    }
    temp->data=item;
    temp->link=start;
    start=temp;
}
void sll_insert_at_Any(int item, int pos)
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
        temp->link=start;
        start=temp;
    }
    else
    {
        ptr=start;
        for(i=1; i<=pos-2&&ptr!=NULL; i++)
            ptr=ptr->link;
        if(ptr==NULL)
        {
            printf("Invalid Position");
            return;
        }
        temp->link=ptr->link;
        ptr->link=temp;
    }
}
void sll_deletion_at_Begin()
{
    struct node *ptr;
    if(start==NULL)
    {
        printf("No node in Linked List to delete");
        return;
    }
    ptr=start;
    start=start->link; //ptr->link
    free(ptr);
    // ptr becomes dangling
    ptr=NULL;
}
void sll_deletion_from_End()
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
void sll_deletion_from_Any(int pos)
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
        start=start->link;
    else
    {
        for(i=1; i<=pos-1; i++)
        {
            prevptr=ptr;
            ptr=ptr->link;
            if(ptr==NULL)
            {
                printf("Invalid Position");
                return;
            }
        }
        prevptr->link=ptr->link;
    }
    free(ptr);
    ptr=NULL;
}
int count()
{
    int nodeCount=0;
    struct node *ptr;
    if(start==NULL)
        return 0;
    ptr=start;
    while(ptr!=NULL)
    {
        nodeCount++;
        ptr=ptr->link;
    }
    return nodeCount;
}
void reverse()
{
    struct node *prev=NULL, *curr, *next=NULL;
    curr=start;
    while(curr!=NULL)
    {
        next=curr->link;
        curr->link=prev;
        prev=curr;
        curr=next;
    }
    start=prev;
}
void swap(struct node *a, struct node *b)
{
    int temp=a->data; //temp=10
    a->data=b->data; //9
    b->data=temp; //10
}
void bubbleSort()
{
    struct node *ptr, *lptr=NULL;
    int swapped;
    if(start=NULL)
    {
        printf("No node in Linked List to delete");
        return;
    }
    do
    {
        ptr=start;
        swapped=0;
        while(ptr->link!=lptr)
        {
            if(ptr->data>ptr->link->data)
            {
                swap(ptr,ptr->link); // swap(ptr->data, ptr->link->data)
                swapped=1;
            }
            ptr=ptr->link;
        }
        lptr=ptr;
    }while(swapped);
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
        printf("%d->", ptr->data);
        ptr=ptr->link;
    }
    printf("NULL");
}
int main(void)
{
    int ch, item, pos;
    while(1)
    {
        printf("\n\n****Single Linked List****\n");
        printf("\n1. Create Linked List by insertion at Begin");
        printf("\n2. Create Linked List by insertion at End");
        printf("\n3. Insert at Any position of Linked List");
        printf("\n4. Delete a node from beginning of Linked List");
        printf("\n5. Delete a node from end of Linked List");
        printf("\n6. Delete from Any position of Linked List except begin and end");
        printf("\n7. Count the no of nodes in the Linked List");
        printf("\n8. Reverse the Single Linked List");
        printf("\n9. Sort the Linked List");

        printf("\n11. Display the Linked List");
        printf("\n12. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            sll_insert_at_Begin(item);
            break;

        case 2:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            sll_insert_at_End(item);
            break;

        case 3:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            printf("Enter the position of insertion: ");
            scanf("%d", &pos);
            sll_insert_at_Any(item, pos);
            break;

        case 4:
            sll_deletion_at_Begin();
            break;

        case 5:
            sll_deletion_from_End();
            break;

        case 6:
            printf("Enter position of deletion except first and last: ");
            scanf("%d", &pos);
            sll_deletion_from_Any(pos);
            break;

        case 7:
            printf("No of nodes in the Linked List is: %d", count());
            break;

        case 8:
            reverse();
            break;

        case 9:
            bubbleSort();
            break;

        case 11:
            display();
            break;

        case 12:
            exit(0);

        default:
            printf("Wrong Input!!!");
            printf("Please provide correct option next time Onwards");
        }
    }
    return 0;
}
