#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *top;

void push(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->link = top;
    top = newnode;
}

void show()
{
    struct node *tmp;
    tmp = top;

    if (tmp == 0)
    {
        printf("\nStack is Empty!!");
    }
    else
    {
        while (tmp != 0)
        {
            printf("\n%d", tmp->data);
            tmp = tmp->link;
        }
    }
}

void peek()
{
    if (top == 0)
    {
        printf("\nStack is Empty!!");
    }
    else
    {
        printf("\nPresent Element = %d", top->data);
    }
}

void pop()
{
    struct node *tmp;
    tmp = top;
    if (tmp == 0)
        printf("\nUnderflow");
    else
    {
        printf("\nDeleted node %d", top->data);
        top = top->link;
        free(tmp);
    }
}
void main()
{
    int choice, ch = 1, x;
    while (ch == 1)
    {
        ch = 0;
        printf("Enter ypur choice : \n1. PUSH\n2. POP\n3. SHOW\n4. PEEK\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the Element to push into the stack\n");
            scanf("%d", &x);
            push(x);
            break;
        case 2:
            pop();
            break;
        case 3:
            show();
            break;
        case 4:
            peek();
            break;
        default:
            printf("Invalid choice");
        }
        
        printf("\nDo you want to continue then press 1 otherwise any other Integer\n");
        scanf("%d",&ch);
    }
}