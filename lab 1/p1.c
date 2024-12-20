#include <stdio.h>
#include <stdlib.h>

// Define a struct for a node in the linked list
struct LIST {
    int data;
    struct LIST* next;
};

// Function to insert a new node at the end of the linked list
void insertEnd(struct LIST** PList, int x) {
    struct LIST* newNode = (struct LIST*)malloc(sizeof(struct LIST));
    newNode->data = x;
    newNode->next = NULL;

    if (*PList == NULL) {
        *PList = newNode;
    } else {
        struct LIST* current = *PList;
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

struct LIST* DeleteAll(struct LIST* PList, int x) {
    if (PList == NULL) {
        return PList; // Empty list, nothing to delete
    }

    struct LIST* current = PList;

    while (current != NULL && current->next != NULL) {
        if (current->next->data == x) {
            struct LIST* temp = current->next;
            current->next = current->next->next;
            free(temp); // Free the memory of the deleted node
        } else {
            current = current->next;
        }
    }

    if( PList!=NULL && PList->data == x){
        struct LIST* temp = PList;
        PList = PList->next;
        free(temp);
    }

    return PList;

}

int main() {

    struct LIST* head = NULL;
    int n,x,value;

    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    printf("Linked List: ");
    printList(head);
    
    printf("Enter element to delete: ");
    scanf("%d", &x);
    head = DeleteAll(head, x);

    printf("Linked List: ");
    printList(head);

    // Free the allocated memory
    struct LIST* current = head;
    while (current != NULL) {
        struct LIST* temp = current;
        current = current->next;
        free(temp);
    }

}