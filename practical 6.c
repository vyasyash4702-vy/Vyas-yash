
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void display(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main(void) {
    struct Node *head = NULL;
    struct Node *newNode, *temp;
    int i, value;

    for (i = 0; i < 3; i++) {
        printf("Enter value %d: ", i + 1);

        if (scanf("%d", &value) != 1) {
            printf("Invalid input!\n");
            return 1;
        }

        newNode = (struct Node *)malloc(sizeof(struct Node));

        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    printf("\nSingly Linked List: ");
    display(head);

    temp = head;
    while (temp != NULL) {
        struct Node *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return 0;
}

