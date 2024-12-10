#include<stdio.h>
int main(void)
{
    int x = 10;
    /*Pointer variable Declaration*/
    int *ptr;
    ptr = &x;
    printf("The value of x is: %d", x);
    printf("\n The value of x is: %d", *ptr);
    *ptr = *ptr + 5;
    return 0;
}
