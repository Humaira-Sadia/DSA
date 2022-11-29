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

void addition(int a[m][n], int b[m][n])
{
    int c[m][n];
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    display(c, m, n);
}

void substraction(int a[m][n], int b[m][n])
{
    int c[m][n];
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
    display(c, m, n);
}

void multiplication(int a[m][n])
{
    int b[m1][n1], c[m][n1], k ;
    printf("Enter the elements in the array B: \n");
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < n1; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n1; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < n; k++)
            {
                c[i][j] = c[i][j] + (a[i][k] * b[k][j]);
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
    printf("1. Transpose. \n2. Addition. \n3. Substraction. \n4. Multiplication. \n5. Display. \nEnter your choice: ");
    scanf("%d", &choice); 

    printf("Enter the value of rows: ");
    scanf("%d", &m1);
    printf("Enter the value of columns: ");
    scanf("%d", &n1);
    int b[m1][n1];
    if (choice == 2 || choice == 3)
    {
        if (m != m1 || n != n1)
        {
            printf("Operations not possible.");
            return 0;
        }

        else
        {
            printf("Enter the elements in the array B: \n");
            for (i = 0; i < m; i++)
            {
                for (j = 0; j < n; j++)
                {
                    scanf("%d", &b[i][j]);
                }
            }
            printf("***Array B***\n");
            display(b, m, n);
        }
    }
    else if (choice == 4)
    {
        if (n != m1)
        {
            printf("Multiplacation not possible.");
            return 0;
        }
    }
    switch (choice)
    {
    case 1:
        transpose(a);
        break;
    case 2:

        addition(a, b);
        break;
    case 3:
        substraction(a, b);
        break;
    case 4:
        multiplication(a);
        break;
    case 5:
        display(a, m, n);
        break;

    default:
        printf("Invalid choice.");
        break;
    }
    return 0;
}

