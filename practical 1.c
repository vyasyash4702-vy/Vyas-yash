/* 1. Pointers: call by value and call by reference */
#include <stdio.h>

/* Call by value: swaps copies, original values do not change */
void swap_value(int a, int b)
{
    int c;
    c = a;
    a = b;
    b = c;
}

/* Call by reference: swaps using addresses, original values change */
void swap_reference(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

int main()
{
    int a = 10;
    int b = 20;
    int *p = &a;

    printf("Value of a = %d, address of a = %p, pointer p holds %p, *p = %d\n", a, (void *)&a, (void *)p, *p);

    printf("\n--- Call by value ---\n");
    swap_value(a, b);
    printf("No 1 = %d\n", a);
    printf("No 2 = %d\n", b);

    printf("\n--- Call by reference ---\n");
    swap_reference(&a, &b);
    printf("No 1 = %d\n", a);
    printf("No 2 = %d\n", b);

    return 0;
}
