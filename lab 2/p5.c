#include <stdio.h>
#include <stdlib.h>

// Define a struct for a node in the linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* nextNext;
};

struct Node* insertATEnd( struct Node* head, int data){

    if( head == NULL){
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;
        newNode->nextNext = NULL;
        return newNode;
    }

    if( head->next == NULL){
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;
        newNode->nextNext = NULL;

        head->next = newNode;
        return head;
    }

    struct Node *curr=head, *prev=NULL;

    while ( curr->next != NULL )
    {
        prev = curr;
        curr = curr->next;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->nextNext = NULL;

    curr->next = newNode;
    prev->nextNext = newNode;
    
    return head;
}

// Function to print the LL
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->nextNext;
    }
    printf("NULL\n");
}

// insert after an element
struct Node* insertAfter( struct Node* head, int data, int node){

    struct Node *curr=head, *prev=head;

    while ( curr != NULL )
    {

        if( curr->data == node ){

            struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = data;

            newNode->next = curr->next;
            newNode->nextNext = curr->nextNext;
            
            curr->next = newNode;
            curr->nextNext = newNode->next;

            if( curr != prev){
                prev->nextNext = newNode;
            }

            return head;
        }
        
        prev = curr;
        curr = curr->next;
    }

    printf("\n Element not found\n");
    
    return head;
}


int main(){

    int n,x;
    printf("Enter the number of elements in the LL : ");
    scanf("%d", &n);

    struct Node* head = NULL;

    for( int i=0; i<n; i++){
        printf("Enter element %d : ", i + 1);
        scanf("%d", &x);
        head = insertATEnd(head,x);
    }

    printList(head);

    printf("Enter the element you want to insert : ");
    scanf("%d",&x);

    printf("Enter the element after which you want to insert %d : ",x);
    scanf("%d",&n);

    head = insertAfter(head,x,n);
    printList(head);

    return 0;
}