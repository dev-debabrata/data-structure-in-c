#include<stdio.h>
int main(void)
{
    int i = 10;
    int *iptr;
    double d = 12.34;
    double *dptr;
    void *vptr;
    iptr = &i;
    printf("i = %d", *iptr);
    vptr = &i;
    printf("\ni = %d", *(int*)vptr);
    dptr = &d;
    printf("\nd = %if", *dptr);
    vptr = &d;
    printf("\nd = %if", *(double*)vptr);
    return 0;
}
