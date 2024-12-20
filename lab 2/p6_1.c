#include <stdio.h>
#include <stdlib.h>

// Define a struct for a node in the doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// creation of DDL
struct Node* createDDL(){

    int n;
    printf("Enter the number of elements in the DLL : ");
    scanf("%d", &n);

    struct Node* head = NULL;
    struct Node* current = NULL;

    for ( int i=0; i<n; i++){

        int data;

        printf("Enter element %d : ", i + 1);
        scanf("%d", &data);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;

        if( head == NULL){
            head = newNode;
            current = newNode;
        }
        else{
            current->next = newNode;
            newNode->prev = current;
            current = current->next;
        }
    }

    return head;

}

// Function to print the DDL
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        if( current->next == NULL){
            break;
        }
        current = current->next;
    }
    printf("NULL\n");

        while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

// add after an element
struct Node* delAfterDLL( struct Node* head, int n)
{
    struct Node* current = head;

    while( current != NULL ) {

        if( current->data == n ){

            if( current->next == NULL ){
                break;
            }
            if( current->next->next == NULL){
                current->next = NULL;
                break;
            }
            
            current->next = current->next->next;
            current->next->prev = current;

            break;

        }

        current = current->next;
    }

    return head;
}


int main(){

    struct Node *head = createDDL();
    printList(head);

    int n;

    printf("Enter the element after which you want to delete : ");
    scanf("%d",&n);

    head = delAfterDLL(head , n);
    printList(head);
    
    return 0;

}