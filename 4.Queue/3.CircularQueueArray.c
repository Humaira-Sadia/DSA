#include <stdio.h>
#include <stdlib.h>
#define size 5
int rear = -1;
int front = -1;
int queue[size];
int isFull()
{
    if ((rear + 1) % size == front)
        return 1;
    else
        return 0;
}
int isEmpty()
{
    if (rear == -1 && front == -1)
        return 1;
    else
        return 0;
}
void enqueue(int data)
{
    if (isFull())
    {
        printf("overflow condition : insertion not possible");
        exit(1);
    }
    else if (rear == -1 && front == -1)
    {
        rear = 0;
        front = 0;
    }
    else
    {
        rear = (rear + 1) % size;
    }
    queue[rear] = data;
    printf(" %d element is inserted\n", data);
}
void dequeue()
{
    if (isEmpty())
    {
        printf("Underflow condition : deletion not possible\n");
        exit(0);
    }
    else if (front == rear) // if there is one element in queue
    {
        printf("%d element is deleted\n", queue[front]);
        //12 / 10 / 22 70
        rear = -1;
        front = -1;
    }
    else
    {
        printf("%d element is deleted\n", queue[front]);
        front = (front + 1) % size;
    }
}
void display()
{
    if (isEmpty())
    {
        printf("The queue is empty \n");
        exit(0);
    }
    int i = front;
    // printf("%d is rear " , rear);
    while (i != rear)
    {
        printf("The elements of the queue are : %d \n", queue[i]);
        i = (i + 1) % size;
    }
    printf("The elements of the queue are : %d \n", queue[i]);
}
int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    dequeue();
    dequeue();
    display();
    return 0;
}