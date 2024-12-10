#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int n, i;
    int *ptr;
    printf("Enter range: ");
    scanf("%d", &n);
    ptr = (int*)malloc(n*sizeof(int));
    printf("%u", ptr);
    for(i = 0; i<n; i++)
        scanf("%d", ptr+i);
    printf("Address                      value");
    printf("\n----------------------------------");
    for(i = 0; i<n; i++)
        printf("\n%u\t\t\t\t%d", ptr+i, *(ptr+i));
    return 0;
}
