#include <stdio.h>
#include <stdlib.h>

// Define a struct for a node in the linked list
struct LIST {
    int data;
    struct LIST* next;
};

// Function to insert a new node at the end of the linked list
void insertEnd(struct LIST** head, int value) {
    struct LIST* newNode = (struct LIST*)malloc(sizeof(struct LIST));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct LIST* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to print the linked list
void printList(struct LIST* head) {
    struct LIST* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

struct LIST* revrseLL(struct LIST* head) {
    if (head == NULL) {
        return NULL; // Empty list, nothing to delete
    }

    struct LIST* current = head;
    struct LIST* prev = NULL;
    struct LIST* nextNode = NULL;


    while( current != NULL ) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev;

}

int main() {

    struct LIST* head = NULL;
    int n,value;

    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    printf("Linked List: ");
    printList(head);

    head = revrseLL(head);

    printf("Reverse Linked List: ");
    printList(head);

    // Free the allocated memory
    struct LIST* current = head;
    while (current != NULL) {
        struct LIST* temp = current;
        current = current->next;
        free(temp);
    }

}