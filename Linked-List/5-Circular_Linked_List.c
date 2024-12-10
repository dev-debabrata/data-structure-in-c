#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *last=NULL;
void cll_insert_at_Begin(int item)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Insufficient Memory");
        exit(0);
    }
    temp->data=item;
    if(last==NULL)  /*Node inserted as first Node*/
    {
        last=temp;
    }
    else   /*Node inserted as any other Node*/
    {
        temp->link=last->link;
    }
    last->link=temp;
}

void cll_insert_at_End(int item)
{
    struct node *temp, *ptr;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Insufficient Memory");
        exit(0);
    }
    temp->data=item;
    if(last==NULL)
    {
        temp->link=temp;
    }
    else
    {
        temp->link=last->link;
    }
    last=temp;
}

void cll_insert_at_Any(int item, int pos)
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
        if(last==NULL)   /*Node inserted as first Node*/
        {
            last=temp;
        }
        else   /*Node inserted as any other Node*/
        {
            temp->link=last->link;
        }
        last->link=temp;
    }
    else
    {
        if(last==NULL)
        {
            printf("Invalid Position");
            free(temp);
            return;
        }
        ptr=last->link;
        for(i=1; i<=pos-2&&ptr!=NULL; i++)
        {
            ptr=ptr->link;
            if(ptr==last->link)
            {
                printf("Invalid Position");
                free(temp);
                return;
            }
        }
        temp->link=ptr->link;
        ptr->link=temp;
        if(ptr==last)
            last=temp;
    }
}

void cll_deletion_at_Begin()
{
    struct node *ptr;
    if(last==NULL)
    {
        printf("No node in Linked List to delete");
        return;
    }
    ptr=last->link;
    if(last==last->link)
        last=NULL;
    else
    {
        last->link=ptr->link;
    }
    free(ptr);
    // ptr becomes dangling
    ptr=NULL;
}

void cll_deletion_from_End()
{
    struct node *ptr, *prevptr;
    /*case 1: No node in the Linked List*/
    if(last==NULL)
    {
        printf("No node in Linked List to delete");
        return;
    }
    ptr=last->link;
    /*case 2: There are exactly one node in the Linked List*/
    if(last==last->link)
    {
        last=NULL;
    }
    /*case 3: There are more than one node*/
    else
    {
        while(ptr->link!=last->link)
        {
            prevptr=ptr;
            ptr=ptr->link;
        }
        prevptr->link=ptr->link;
        last=prevptr;
    }
    free(ptr);
    // ptr becomes dangling
    ptr=NULL;
}

void cll_deletion_from_Any(int pos)
{
    struct node *ptr, *prevptr;
    int i;
    if(last==NULL)
    {
        printf("No node in Linked List to delete");
        return;
    }
    ptr=last->link;
    if(pos==1)
    {
        if(last==last->link)
            last=NULL;
        else
            last->link=ptr->link;
    }
    else
    {
        for(i=1; i<=pos-1; i++)
        {
            prevptr=ptr;
            ptr=ptr->link;
            if(ptr==last->link)
            {
                printf("Invalid Position");
                return;
            }
        }
        prevptr->link=ptr->link;
        if(ptr==last)
            last=prevptr;
    }
    free(ptr);
    ptr=NULL;
}

void display()
{
    struct node *ptr;
    if(last==NULL)
    {
        printf("No Node in Linked List to Display");
        return ;
    }
    ptr=last->link;
    while(ptr!=last)
    {
        printf("%d->", ptr->data);
        ptr=ptr->link;
    }
    printf("%d->", ptr->data);
}

int main(void)
{
    int ch, item, pos;
    while(1)
    {
        printf("\n\n****Circular Linked List****\n");
        printf("\n1. Create Circular Linked List by insertion at Begin");
        printf("\n2. Create Circular Linked List by insertion at End");
        printf("\n3. Insert at Any position of Circular Linked List");
        printf("\n4. Delete a node from beginning of Circular Linked List");
        printf("\n5. Delete a node from end of Circular Linked List");
        printf("\n6. Delete from Any position of Circular Linked List except begin and end");

        printf("\n7. Display the Linked List");
        printf("\n8. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            cll_insert_at_Begin(item);
            break;

        case 2:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            cll_insert_at_End(item);
            break;

        case 3:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            printf("Enter the position of insertion: ");
            scanf("%d", &pos);
            cll_insert_at_Any(item, pos);
            break;

        case 4:
            cll_deletion_at_Begin();
            break;

        case 5:
            cll_deletion_from_End();
            break;

        case 6:
            printf("Enter position of deletion except first and last: ");
            scanf("%d", &pos);
            cll_deletion_from_Any(pos);
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
