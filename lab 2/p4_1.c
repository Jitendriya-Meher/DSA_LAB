#include <stdio.h>
#include <stdlib.h>

// Define a struct for a node in the linked list for polynomial
struct Node {
    int coff;
    int powX;
    int powY;
    struct Node* next;
};

// creation on polynomial
struct Node* createPol(){

    int n;
    printf("Enter the number of elements in the polynomial : ");
    scanf("%d", &n);

    struct Node* head = NULL;
    struct Node* current = NULL;

    for ( int i=0; i<n; i++){

        int coff,x,y;

        printf("Enter element %d: coefficient : ", i + 1);
        scanf("%d", &coff);
        printf("Enter element %d: power of x : ", i + 1);
        scanf("%d", &x);
        printf("Enter element %d: power of y : ", i + 1);
        scanf("%d", &y);
        
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->coff = coff;
        newNode->powX = x;
        newNode->powY = y;
        newNode->next = NULL;

        if( head == NULL){
            head = newNode;
            current = newNode;
        }
        else{
            current->next = newNode;
            current = current->next;
        }
    }

    return head;

}

// Function to print the polynomal
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d x%d y%d -> ", current->coff,current->powX,current->powY);
        current = current->next;
    }
    printf("NULL\n");
}

// add polynomial
struct Node* addPol(struct Node* pol1, struct Node* pol2){

    if( pol1 == NULL){
        return pol2;
    }

    if( pol2 == NULL){
        return pol1;
    }

    struct Node *p1 = pol1;

    while ( p1 != NULL)
    {
        struct Node *current = pol2, *prev=NULL;
        
        while( current != NULL){

            if( (p1->powX == current->powX) && ( p1->powY == current->powY) ){

                p1->coff = p1->coff + current->coff;

                if( prev == NULL){
                    pol2 = pol2->next;
                }
                else{
                    prev->next = current->next;
                }
                free(current);
                break;
            }
            
            prev = current;
            current = current->next;

        }

        if( p1->next == NULL){
            break;
        }
        p1 = p1->next;
    }

    if( pol2 != NULL){
        p1->next = pol2;
    }
    
    return pol1;

}

int main() {

    printf("Enter for polynomial 1 : \n");
    struct Node* pol1 = createPol();

    printf("\nEnter for polynomial 2 : \n");
    struct Node* pol2 = createPol();

    printf("\npolynomial 1 : \n");
    printList(pol1);
    printf("\npolynomial 2 : \n");
    printList(pol2);

    printf("\nResult polynomial 3: \n");
    struct Node* pol3 = addPol(pol1,pol2);
    printList(pol3);

    return 0;

}