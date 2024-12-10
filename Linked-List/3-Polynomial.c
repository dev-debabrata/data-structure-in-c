#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coeff;
    int expo;
    struct node *link;
};
struct node *start1=NULL, *start2=NULL, *start3=NULL;
struct node *create(struct node *start)
{
    int n, c, e, i;
    struct node *temp, *ptr;
    printf("Enter the number of node: ");
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        if(temp==NULL)
        {
            printf("Insufficient Memory");
            return 0;
        }
        printf("Enter Coefficient for term %d:", i);
        scanf("%d", &c);
        printf("Enter Exponent for term %d:", i);
        scanf("%d", &e);

        temp->coeff=c;
        temp->expo=e;
        if(start==NULL||e>start->expo)
        {
            temp->link=start;
            start=temp;
        }
        else
        {
            ptr=start;
            while(ptr->link!=NULL&&ptr->link->expo>=e)
            {
                ptr=ptr->link;
            }
            temp->link=ptr->link;
            ptr->link=temp;
        }
    }
    return start;
}

void display(struct node *ptr)
{
     if(ptr==NULL)
    {
        printf("No Node in Linked List to Display");
        return ;
    }
    while(ptr!=NULL)
    {
        printf("%d->", ptr->coeff);
        printf("%d->", ptr->expo);
        ptr = ptr->link;
    }
    printf("NULL");
}

void polyadd(struct node *p1, struct node *p2)
{
    struct node *ptr, *temp;
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->expo>p2->expo)
        {
             temp=(struct node*)malloc(sizeof(struct node));
             temp->coeff=p1->coeff;
             temp->expo=p1->expo;
             temp->link=NULL;
             if(start3==NULL)
             {
                 start3=temp;
             }
             else
             {
                 ptr=start3;
                 while(ptr->link!=NULL)
                    ptr=ptr->link;
                 ptr->link=temp;
             }
             p1=p1->link;
        }
        else if(p2->expo>p1->expo)
        {
             temp=(struct node*)malloc(sizeof(struct node));
             temp->coeff=p2->coeff;
             temp->expo=p2->expo;
             temp->link=NULL;
             if(start3==NULL)
             {
                 start3=temp;
             }
             else
             {
                 ptr=start3;
                 while(ptr->link!=NULL)
                    ptr=ptr->link;
                 ptr->link=temp;
             }
             p2=p2->link;
        }
        else if(p1->expo==p2->expo)
        {
             temp=(struct node*)malloc(sizeof(struct node));
             temp->coeff=p1->coeff+p2->coeff;
             temp->expo=p1->expo;
             temp->link=NULL;
             if(start3==NULL)
             {
                 start3=temp;
             }
             else
             {
                 ptr=start3;
                 while(ptr->link!=NULL)
                    ptr=ptr->link;
                 ptr->link=temp;
             }
             p1=p1->link;
             p2=p2->link;
        }
    }
    while(p1!=NULL)
    {
         temp=(struct node*)malloc(sizeof(struct node));
             temp->coeff=p1->coeff;
             temp->expo=p1->expo;
             temp->link=NULL;
             if(start3==NULL)
             {
                 start3=temp;
             }
             else
             {
                 ptr=start3;
                 while(ptr->link!=NULL)
                    ptr=ptr->link;
                 ptr->link=temp;
             }
             p1=p1->link;
    }
    while(p2!=NULL)
    {
         temp=(struct node*)malloc(sizeof(struct node));
             temp->coeff=p2->coeff;
             temp->expo=p2->expo;
             temp->link=NULL;
             if(start3==NULL)
             {
                 start3=temp;
             }
             else
             {
                 ptr=start3;
                 while(ptr->link!=NULL)
                    ptr=ptr->link;
                 ptr->link=temp;
             }
             p2=p2->link;
    }
    display(start3);
}

int main(void)
{
    int choice, item;
    while(1)
    {
        printf("\n1. Enter 1st Polynomial");
        printf("\n2. Enter 2nd Polynomial");
        printf("\n3. Addition of 1st polynomial and 2nd polynomial");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            start1=create(start1);
            printf("start1->");
            display(start1);
            break;

        case 2:
           start2=create(start2);
            printf("start2->");
            display(start2);
            break;
        case 3:
            polyadd(start1,start2);
            break;

        case 4:
            exit(0);

        default:
            printf("Wrong Input!!!");
            printf("Please provide correct option next time Onwards");
        }
    }
    return 0;
}

