#include <stdio.h>
int a[10][10];
int b[10][10];
int c[10][10];
void display(int a[10][10], int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }
    printf("\n");
}

void transpose(int a[10][10],int m,int n){
    int i,j,c[10][10];
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            c[i][j] = a[j][i];
        }
    }
     display(c, m, n);
}
void add(int a[10][10], int b[10][10], int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
     display(c, m, n);
}

void sub(int a[10][10], int b[10][10], int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
    display(c, m, n);
}

void mul(int a[10][10], int b[10][10], int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] * b[i][j];
        }
    }
    display(c, m, n);
}

void div(int a[10][10], int b[10][10], int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] / b[i][j];
        }
    }
}

int main()
{
    int m, n, i, j,choice;
    printf("Enter the number of rows and columns: \n");
    scanf("%d%d", &m, &n);
 
    printf("Enter the elements in array a: \n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    printf("First array a\n");
    display(a, m, n);

    printf("Enter the elements in array b: \n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &b[i][j]);
    printf("Second array b\n");
    display(b, m, n);

    printf("Enter your choice: \n1.Transpose. \n2.Addition. \n3.Substraction. \n4.Multiplication. \n5.Division. \n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        printf("***Transpose***\n\n");
        transpose(a,m,n);
        break;
    case 2:
        printf("***Addition***\n\n");
        add(a, b, m, n);
        break;
    case 3:
        printf("***Substraction***\n\n");
        sub(a, b, m, n);
        break;
    case 4:
        printf("***Multiplication***\n\n");
        mul(a, b, m, n);
        break;
    case 5:
        printf("***Division***\n\n");
        div(a, b, m, n);
        break;
    default:
        printf("Invlid input,please try again");
        break;
    }

    return 0;
}