#include <stdio.h>
// #include <stdlib.h>
void display(int (*array)[], int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", *(*array+i)+j);
        }
        printf("\n");
    }
}
int main()
{
    int a[10][10], b[10][10], c[10][10], i, j, m, n;
    int *ptra[10][10], *ptrb[10][10], *ptrc[10][10];
    printf("Enter the number of rows and columns: \n");
    scanf("%d%d", &m, &n);
    printf("Enter the elements in matrix a: \n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
            ptra[i][j] = &a[i][j];
        }
    // for (i = 0; i < m; i++)
    // for (j = 0; j < n; j++)
    // printf("%u",*ptra[i][j]);
    printf("***First Matrix***\n");
    display(a,m,n);
}