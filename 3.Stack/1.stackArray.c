#include<stdio.h>
int stack[100],choice,n,top,x,i;


void push()
{
    if(top>=n-1) printf("\nOVERFLOW!!");
    else
    {
        printf(" Enter a value to be pushed:");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}
void pop()
{
    if(top<=-1)  printf("\n UNDERFLOW!!");
    else
    {
        printf("\n The popped elements is %d",stack[top]);
        top--;
    }
}
void display()
{
    if(top>=0)
    {
        printf("\n The elements in stack \n");
        for(i=top; i>=0; i--)
            printf("\n%d",stack[i]);
        printf("\n Press Next Choice");
    }
    else
    {
        printf("\n The STACK is empty");
    }
   
}
int main()
{
    top=-1;
    printf("\n Enter the size of stack : ");
    scanf("%d",&n);
    printf("\n STACK OPERATIONS USING ARRAY\n");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT");
    do
    {
        printf("\n Enter your Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("\n EXIT POINT ");
                break;
            }
            default:
            {
                printf ("\n Please Enter a Valid Choice.");
            }
                
        }
    }
    while(choice!=4);
    return 0;
}