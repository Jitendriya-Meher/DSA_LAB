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
struct Node* mulPol(struct Node* pol1, struct Node* pol2){

    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* current = head;

    while ( pol1 != NULL )
    {
        struct Node* pl2 = pol2;

        while( pl2 != NULL ){

            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->coff = pol1->coff * pl2->coff;
            newNode->powX = pol1->powX + pl2->powX;
            newNode->powY = pol1->powY + pl2->powY;
            newNode->next = NULL;

            current->next = newNode;
            current = current->next;

            pl2 = pl2->next;
        }

        pol1 = pol1->next;
        
    }

    return head->next;

}

// remove duplicates
struct Node* removerDub( struct Node* head){

    struct Node* temp = head;

    while( temp != NULL ){
        struct Node* current = temp->next, *prev=temp;
        
        while( current != NULL){

            if( (current->powX == temp->powX) && (current->powY == temp->powY)){

                temp->coff = current->coff + temp->coff;
                prev->next = current->next;

                struct Node* freeNode = current;
                current = current->next;

                free(freeNode);
                continue;
            }

            prev = current;
            current = current->next;
        }

        temp = temp->next;

    }

    return head;

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
    struct Node* pol3 = mulPol(pol1,pol2);
    printList(pol3);

    pol3 = removerDub(pol3);
    printList(pol3);

    return 0;

}