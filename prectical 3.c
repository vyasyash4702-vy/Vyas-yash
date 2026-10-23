/* 3. Stack using an array: PUSH, POP, PEEP, CHANGE and DISPLAY */
#include <stdio.h>
#include <stdlib.h>
#define size 5

int top = -1, inp_array[size];

void push();
void pop();
void peep();
void change();
void show();

int main()
{
    int choice;
    while (1)
    {
        printf("\nPerform operations on the stack:");
        printf("\n1. Push the element\n2. Pop the element\n3. Peep the element\n4. Change the element\n5. Show the elements\n6. End\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peep();
                break;
            case 4:
                change();
                break;
            case 5:
                show();
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    }
    return 0;
}

void push()
{
    int x;
    if (top == size - 1)
    {
        printf("\nOverflow!\n");
    }
    else
    {
        printf("\nEnter the element to be added onto the stack: ");
        scanf("%d", &x);
        top = top + 1;
        inp_array[top] = x;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("\nUnderflow!\n");
    }
    else
    {
        printf("\nPopped element: %d\n", inp_array[top]);
        top = top - 1;
    }
}

void peep()
{
    int v1;
    if (top == -1)
    {
        printf("\nUnderflow!\n");
        return;
    }
    printf("\nEnter position from top (0 = top element): ");
    scanf("%d", &v1);
    if (v1 < 0 || top - v1 < 0)
    {
        printf("\nInvalid position!\n");
    }
    else
    {
        printf("\nElement at position %d from top: %d\n", v1, inp_array[top - v1]);
    }
}

void change()
{
    int v1, v2;
    printf("\nEnter position for change (0 = top element): ");
    scanf("%d", &v1);
    printf("\nEnter the number for change: ");
    scanf("%d", &v2);
    if (top == -1 || v1 < 0 || top - v1 <= -1)
    {
        printf("\nInvalid position or stack is empty!\n");
    }
    else
    {
        inp_array[top - v1] = v2;
        printf("\nChange successful!\n");
    }
}

void show()
{
    if (top == -1)
    {
        printf("\nUnderflow!\n");
    }
    else
    {
        printf("\nElements present in the stack:\n");
        for (int i = top; i >= 0; --i)
        {
            printf("%d\n", inp_array[i]);
        }
    }
}
