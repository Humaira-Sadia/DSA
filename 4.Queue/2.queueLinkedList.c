// linked list implementation of queue
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;
void enqueue(int value)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = new_node;
        rear = new_node;
    }
    else
    {
        rear->next = new_node;
        rear = new_node;
    }
}
void display()
{
    struct node *temp = front;
    while (temp)
    {
        printf(" %d-> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void dequeue()
{
    struct node *temp = NULL;
    if (front == NULL)
    {
        printf("Queue is empty : deletion is not possible ");
    }
    else
        //12 / 10 / 22 66
        {
            temp = front;
            printf("Deleted element : %d\n", front->data);
            front = front->next;
            if (front == NULL)
            {
                rear = NULL;
            }
            free(temp);
        }
}
int main()
{
    enqueue(12);
    enqueue(13);
    enqueue(14);
    printf("Enqueue operation :\n");
    display();
    dequeue();
    printf("Dequeue operation : \n");
    display();
    return 0;
}
