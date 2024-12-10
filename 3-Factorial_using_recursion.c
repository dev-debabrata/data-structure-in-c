#include<stdio.h>
int fact(int n)
{
    if(n==0)
        return 1;
    else
        return fact(n-1)*n;
}
int main(void)
{
    int n;
    /*Reading Input*/
    printf("Enter a Number: ");
    scanf("%d", &n);
    printf("The Factorial of %d is %d", n,fact(n));
    return 0;
}
