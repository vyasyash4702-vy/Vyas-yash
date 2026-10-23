/* 2. Array operations: traversal, insertion, deletion and searching */
#include <stdio.h>

int arr[100], n, i, pos, item;

int main()
{
    int found = 0;

    /* Input */
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter array elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    /* Traversal */
    printf("\nArray: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    /* Insertion */
    printf("\nEnter index for insertion: ");
    scanf("%d", &pos);
    printf("Enter element for insertion: ");
    scanf("%d", &item);
    if (pos < 0 || pos > n || n >= 100)
    {
        printf("Invalid index for insertion\n");
    }
    else
    {
        for (i = n; i > pos; i--)
            arr[i] = arr[i - 1];
        arr[pos] = item;
        n++;
    }
    printf("Array after insertion: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    /* Deletion */
    printf("\nEnter index for deletion: ");
    scanf("%d", &pos);
    if (pos < 0 || pos >= n)
    {
        printf("Invalid index for deletion\n");
    }
    else
    {
        for (i = pos; i < n - 1; i++)
            arr[i] = arr[i + 1];
        n--;
    }
    printf("Array after deletion: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    /* Searching (linear search) */
    printf("\nEnter element to search: ");
    scanf("%d", &item);
    for (i = 0; i < n; i++)
    {
        if (arr[i] == item)
        {
            printf("Element found at index %d\n", i);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Element not found\n");

    return 0;
}
