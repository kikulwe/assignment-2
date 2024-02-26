#include <stdio.h>
#include <stdlib.h>

// # Operations
// Insertion[At the start, end, arbitrary]
// Deletion [By index, value, first, last]
// Searching[By value or by index]
// [40, 3, 5, 40, 50]
// [3 | next] -> [5 | next] ->[40 | next]->[50 | next]->NULL
// [3 | next] -> NULL

struct Node {
    int number;
    struct Node *next;
};


// Function to create a new node with given data
struct Node* createNode(int number) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Error: Unable to allocate memory for a new node\n");
        exit(1);
    }

    newNode->number = number;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the beginning of the list
void prepend(struct Node **head, int num) {
    struct Node *newNode = createNode(num);
    newNode->next = *head;
    *head = newNode;
}

// Function to add a node at the end of the list
void append(struct Node **head, int num) {
    struct Node *newNode = createNode(num);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to print all nodes in the list
void printList(struct Node *head) {
    struct Node *current = head;
    printf("[");
    while (current != NULL) {
        printf("%d", current->number);
        current = current->next;

        if(current != NULL){
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    struct Node *head = NULL;

    append(&head, 20); // [20]
    append(&head, 30); // [20, 30]
    prepend(&head, 10); // [10, 20, 30]
    printList(head); // [10, 20, 30]

    append(&head, 50); // [10, 20, 30, 50]
    prepend(&head, 95); // [95, 10, 20, 30, 50]
    printList(head); // [95, 10, 20, 30, 50]

    return 0;
}