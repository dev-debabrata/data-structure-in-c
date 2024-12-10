#include<stdio.h>
int main()
{
    int choice, a, b;
    printf("1. Addition: ");
    printf("\n2. Subtraction: ");
    printf("\n3. Multiplication: ");
    printf("\n4. Division: \n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1:
        printf("\nEnter two value: ");
        scanf("%d%d", &a,&b);
        printf("Addition is: %d",a+b);
        break;
    case 2:
        printf("\nEnter two value: ");
        scanf("%d%d", &a,&b);
        printf("Subtraction is: %d",a-b);
        break;
    case 3:
        printf("\nEnter two value: ");
        scanf("%d%d", &a,&b);
        printf("Multiplication is: %d",a*b);
        break;
    case 4:
        printf("\nEnter two value: ");
        scanf("%d%d", &a,&b);
        printf("Division is: %d",a/b);
        break;
    case 5:
        exit(0);
    default:
        printf("Wrong input!!! Please provide correct option next time...");
    }
}
