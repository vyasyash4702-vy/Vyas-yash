/* 5. Queue using an array: INSERT (enqueue), DELETE (dequeue) and DISPLAY */
#include <stdio.h>
#include <stdlib.h>
#define size 5

void enqueue();
void dequeue();
void display();

int front = -1, rear = -1, ch, que_arr[size];

int main()
{
    while (1)
    {
        printf("\n1 Enqueue\n2 Dequeue\n3 Display\n4 Exit\n");
        printf("Ch = ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

void enqueue()
{
    if (rear == size - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        int data;
        printf("Data: ");
        scanf("%d", &data);
        if (front == -1)
        {
            front = 0;
        }
        rear = rear + 1;
        que_arr[rear] = data;
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Deleted element: %d\n", que_arr[front]);
        front = front + 1;
    }
}

void display()
{
    int i;
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for (i = front; i <= rear; i++)
        {
            printf("%d\t", que_arr[i]);
        }
        printf("\n");
    }
}
