/* 8. Doubly linked list: insertion and deletion (beginning/end/specified position) */
#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *prev, *next;
};

struct node* start = NULL;

void traverse() {
    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }
    struct node* temp = start;
    while (temp != NULL) {
        printf("Data = %d\n", temp->info);
        temp = temp->next;
    }
}

void insertAtFront() {
    int data;
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    temp->info = data;
    temp->prev = NULL;
    temp->next = start;
    if (start != NULL)
        start->prev = temp;
    start = temp;
}

void insertAtEnd() {
    int data;
    struct node *temp, *trav;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    temp->info = data;
    if (start == NULL) {
        start = temp;
    } else {
        trav = start;
        while (trav->next != NULL)
            trav = trav->next;
        temp->prev = trav;
        trav->next = temp;
    }
}

void insertAtPosition() {
    int data, pos, i = 1;
    struct node *temp, *newnode;
    printf("\nEnter position : ");
    scanf("%d", &pos);

    if (pos == 1 || start == NULL) {
        insertAtFront();
        return;
    }

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->prev = NULL;
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    newnode->info = data;

    temp = start;
    while (i < pos - 1 && temp->next != NULL) {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newnode;
    temp->next = newnode;
}

void deleteFirst() {
    struct node* temp;
    if (start == NULL)
        printf("\nList is empty\n");
    else {
        temp = start;
        start = start->next;
        if (start != NULL)
            start->prev = NULL;
        free(temp);
    }
}

void deleteEnd() {
    struct node* temp;
    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }
    temp = start;
    while (temp->next != NULL)
        temp = temp->next;
    if (temp->prev == NULL)
        start = NULL;
    else
        temp->prev->next = NULL;
    free(temp);
}

void deletePosition() {
    int pos, i = 1;
    struct node *temp, *position;

    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }
    printf("\nEnter position : ");
    scanf("%d", &pos);

    if (pos == 1) {
        deleteFirst();
        return;
    }
    temp = start;
    while (i < pos - 1 && temp->next != NULL) {
        temp = temp->next;
        i++;
    }
    position = temp->next;
    if (position == NULL) {
        printf("\nPosition out of bounds\n");
        return;
    }
    if (position->next != NULL)
        position->next->prev = temp;
    temp->next = position->next;
    free(position);
}

int main() {
    int choice;
    while (1) {
        printf("\n\t1 To see list\n");
        printf("\t2 For insertion at starting\n");
        printf("\t3 For insertion at end\n");
        printf("\t4 For insertion at any position\n");
        printf("\t5 For deletion of first element\n");
        printf("\t6 For deletion of last element\n");
        printf("\t7 For deletion of element at any position\n");
        printf("\t8 To exit\n");
        printf("\nEnter Choice :\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: traverse(); break;
            case 2: insertAtFront(); break;
            case 3: insertAtEnd(); break;
            case 4: insertAtPosition(); break;
            case 5: deleteFirst(); break;
            case 6: deleteEnd(); break;
            case 7: deletePosition(); break;
            case 8: exit(1); break;
            default:
                printf("Incorrect Choice. Try Again \n");
                continue;
        }
    }
    return 0;
}
