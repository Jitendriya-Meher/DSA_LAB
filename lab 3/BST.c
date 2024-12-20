#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* insert(struct Node* root, int data){

    if( root == NULL ){
        struct Node* newNode = (struct Node*)malloc( sizeof( struct Node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if( data < root->data ){
        root ->left = insert( root->left, data);
    }
    else{
        root->right = insert( root->right, data);
    }
}

void preOrder( struct Node* root){

    if( root == NULL ){
        return;
    }

    printf("%d ", root->data );

    preOrder(root->left);
    preOrder(root->right);

}

void inOrder( struct Node* root){

    if( root == NULL ){
        return;
    }

    inOrder(root->left);
    printf("%d ", root->data );
    inOrder(root->right);
    
}

void postOrder( struct Node* root){

    if( root == NULL ){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    
    printf("%d ", root->data );
}

int heightOfBST( struct Node* root){

    if( root == NULL ){
        return 0;
    }

    int leftHeight = heightOfBST(root->left);
    int rightHeight = heightOfBST(root->right);

    int height = leftHeight>rightHeight ? leftHeight : rightHeight;

    return height+1;
}

int totalNodesBST( struct Node* root){

    if( root == NULL ){
        return 0;
    }

    int leftNodes = totalNodesBST(root->left);
    int rightNodes = totalNodesBST(root->right);

    return 1+leftNodes+rightNodes;
}

int totalLeafNodesBST( struct Node* root){

    if( root == NULL ){
        return 0;
    }

    if( ( root->left == NULL) && ( root->right == NULL) ){
        return 1;
    }

    int leftNodes = totalLeafNodesBST(root->left);
    int rightNodes = totalLeafNodesBST(root->right);

    return leftNodes+rightNodes;
}

int searchBST( struct Node* root, int x){

    if( root==NULL){
        return 0;
    }

    if( x == root->data){
        return 1;
    }
    else if( x < root->data ){
        return searchBST(root->left, x);
    }
    else{
        return searchBST(root->right, x);
    }

}

int totalExternalNodes( struct Node* root){

    if( root == NULL ){
        return 0;
    }

    if( ( root->left == NULL) && ( root->right == NULL) ){
        return 1;
    }

    int leftNodes = totalExternalNodes(root->left);
    int rightNodes = totalExternalNodes(root->right);

    return leftNodes+rightNodes;
}

int totalInternalNodes( struct Node* root){

    if( root == NULL ){
        return 0;
    }

    if( ( root->left == NULL) && ( root->right == NULL) ){
        return 0;
    }

    int leftNodes = totalInternalNodes(root->left);
    int rightNodes = totalInternalNodes(root->right);

    return (1+leftNodes+rightNodes);
}

int findPred(struct Node* root){

    int ans = root->data;

    while( root != NULL){
        ans = root->data;
        root = root->right;
    }

    return ans;

}

struct Node* deleteNode(struct Node* root, int data){

    if( root == NULL ){
        return NULL;
    }

    if( root->data == data){

        struct Node* temp = root;

        if( root->left == NULL && root->right == NULL ){
            temp = NULL;
            return NULL;
        }
        else if( root->left == NULL){
            temp = root->right;
            return temp;
        }
        else if( root->right == NULL ){
            temp = root->left;
            return temp;
        }
        else{
            int pred = findPred( root->left);
            temp->data = pred;
            root->left = deleteNode( root->left, pred);
        }

    }

    if( data < root->data ){
        root ->left = deleteNode( root->left, data);
    }
    else{
        root->right = deleteNode( root->right, data);
    }
}

int main(){

    int opt = 1,src,result;
    struct Node* root = NULL;

    while ( opt > 0)
    {
        printf("\n 1 . Insert a new element \n");
        printf(" 2 . Search a given number \n");
        printf(" 3 . Delete a given number \n");
        printf(" 4 . In-order Traversal \n");
        printf(" 5 . Pre-order Traversal \n");
        printf(" 6 . Post-order Traversal \n");
        printf(" 7 . Height of the tree \n");
        printf(" 8 . Total number of nodes \n");
        printf(" 9 . Total number of internal nodes \n");
        printf(" 10 . Total number of external nodes \n");
        printf(" 11 . Total number of leaf nodes \n");
        printf(" -1 . To Exit \n");

        printf("\n Enter your option : ");
        scanf("%d",&opt);

        switch (opt)
        {
            case 1 :
                printf("\nEnter the element to insert : "); 
                int data;
                scanf("%d", &data);
                root = insert( root, data );
                break;

            case 2 :
                printf("\nEnter a element to Serach : ");
                scanf("%d",&src);

                int find = searchBST(root, src);

                if( find == 1 ){
                    printf("The element %d is present in BST\n", src);
                }
                else{
                    printf("The element %d is not present in BST\n", src);
                } 
                break;

            case 3 :
                printf("\nEnter a element to Delete : ");
                scanf("%d",&src);
                root = deleteNode(root, src);
                break;

            case 4 :
                printf("\nIn Order Traversal : ");
                inOrder(root);
                break;
            
            case 5 :
                printf("\nPre Order Traversal : ");
                preOrder(root);
                break;

            case 6 :
                printf("\nPost Order Traversal : ");
                postOrder(root);
                break;

            case 7 :
                result = heightOfBST(root);
                printf("\nHeight of BST : %d \n", result);
                break;

            case 8 :
                result = totalNodesBST(root);
                printf("\nTotal nodes in BST : %d \n", result);
                break;

            case 9 :
                result = totalInternalNodes(root);
                printf("\nTotal Internal nodes in BST : %d \n", result);
                break;

            case 10 :
                result = totalExternalNodes(root);
                printf("\nTotal External nodes in BST : %d \n", result);
                break;

            case 11 :
                result = totalLeafNodesBST(root);
                printf("\nTotal leaf nodes in BST : %d \n", result);
                break;

            default:
                opt = -1;
                break;
        }
    }

    return 0;

}