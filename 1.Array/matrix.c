#include <stdio.h>
int m, n, m1, n1;
int i, j;

void display(int a[m][n], int m2, int n2)
{
    for (i = 0; i < m2; i++)
    {
        for (j = 0; j < n2; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

void transpose(int a[m][n])
{
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", a[j][i]);
        }
        printf("\n");
    }
}

void multiplication(int a[m][n])
{
    printf("Enter the no of rows in array B :");
    scanf("%d",&m1);
    printf("Enter the no of colomns in array B :");
    scanf("%d",&n1);

    int b[m1][n1], c[m][n1], k ;
    printf("Enter the elements in the array B: \n");
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < n1; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<n1;j++){
            c[i][j] = 0;
        }
    }

    for(i=0;i<m;i++){
        for(j=0;j<n1;j++){
            for(k=0;k<n;k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    display(c, m, n1);
}

int main()
{
    int i, j, choice;
    printf("Enter the value of rows: ");
    scanf("%d", &m);
    printf("Enter the value of columns: ");
    scanf("%d", &n);
    int a[m][n];

    printf("Enter the elements in the array A : \n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    display(a, m, n);
    printf("\n");
    multiplication(a);
    return 0;
}
