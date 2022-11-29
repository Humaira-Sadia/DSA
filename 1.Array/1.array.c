#include <stdio.h>
int a[] = {1, 2, 3, 4, 5, 6};

int main()
{
    printf("a[3]=%d\n",a[3]);
    int n;
    printf("Enter the number");
    scanf("%d\n", &n);
    a[3] = n;
    printf("a[3]=%d\n",a[3]);
    return 0;
}