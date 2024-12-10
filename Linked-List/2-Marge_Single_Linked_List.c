#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *start1=NULL, *start2=NULL, *start3=NULL;
struct node *create(struct node *start, int item)
{
    struct node *temp, *ptr;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Insufficient Memory");
        return 0;
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
    return start;
}
void display1(struct node *ptr)
{
    if(ptr==NULL)
    {
        printf("No Node in Linked List to Display");
        return ;
    }
    printf("start1->");
    while(ptr!=NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL");
}
void display2(struct node *ptr)
{
    if(ptr==NULL)
    {
        printf("No Node in Linked List to Display");
        return ;
    }
    printf("start2->");
    while(ptr!=NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL");
}
void display3(struct node *ptr)
{
    if(ptr==NULL)
    {
        printf("No Node in Linked List to Display");
        return ;
    }
    printf("start3->");
    while(ptr!=NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL");
}
void marge(struct node *ptr1, struct node *ptr2)
{
    while(ptr1!=NULL&&ptr2!=NULL)
    {
        if(ptr1->data<ptr2->data)
        {
            start3=create(start3,ptr1->data);
            ptr1=ptr1->link;
        }
        else if(ptr1->data>ptr2->data)
        {
            start3=create(start3,ptr2->data);
            ptr2=ptr2->link;
        }
        else if(ptr1->data==ptr2->data)
        {
            start3=create(start3,ptr2->data);
            ptr1=ptr1->link;
            ptr2=ptr2->link;
        }

    }
     while(ptr1!=NULL)
    {
        start3=create(start3,ptr2->data);
        ptr1=ptr1->link;
    }
     while(ptr2!=NULL)
    {
        start3=create(start3,ptr2->data);
        ptr2=ptr2->link;
    }
}
int main(void)
{
    int choice, item;
    while(1)
    {
        printf("\n1. Input 1st Linked List");
        printf("\n2. Input 2nd Linked List");
        printf("\n3. Display First Linked List");
        printf("\n4. Display Second Linked List");
        printf("\n5. Marge Linked List");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("Enter item for First Linked List: ");
            scanf("%d", &item);
            start1=create(start1, item);
            break;

        case 2:
            printf("Enter item for Second Linked List: ");
            scanf("%d", &item);
            start2=create(start2, item);
            break;

        case 3:
            display1(start1);
            break;

        case 4:
            display2(start2);
            break;

        case 5:
            marge(start1,start2);
            display3(start3);
            break;

        case 6:
            exit(0);

        default:
            printf("Wrong Input!!!");
            printf("Please provide correct option next time Onwards");
        }
    }
    return 0;
}
