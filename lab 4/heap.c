#include<stdio.h>
#include<conio.h>

int heapSize = 0;
int heap[1000] = {0};

void swap( int i , int j){
    int val = heap[i];
    heap[i] = heap[j];
    heap[j] = val;
}

void heapifyPush( int index){
    if( index <= 0){
        return;
    }
    int parentIndex = (index-1)/2;

    if( heap[index] < heap[parentIndex]){
        swap( index, parentIndex );
        heapifyPush(parentIndex);
    }
}

void push( int x){

    heap[ heapSize] = x;
    heapSize++;

    heapifyPush(heapSize-1);
}

void heapifyPop( int index){
    if( heapSize <= 0){
        return;
    }

    int leftChild = index*2 + 1;
    int rightChild = index*2 + 2;
    int newIndex = index;

    if( leftChild < heapSize){
        if( heap[leftChild] < heap[newIndex]){
            newIndex = leftChild;
        }
    }

    if( rightChild < heapSize){
        if( heap[rightChild] < heap[newIndex]){
            newIndex = rightChild;
        }
    }

    if( newIndex != index){
        swap( newIndex, index );
        heapifyPop( newIndex);
    }

}

void pop(){
    heap[0] = heap[ heapSize - 1];
    heapSize--;

    heapifyPop(0);
}

int top(){
    // printf("\ntop = %d", heap[0]);
    if( heapSize == 0 ){
        return -1;
    }
    return heap[0];
}

void print(){
    printf("\nHeap : ");
    for( int i = 0; i < heapSize; i++){
        printf(" %d", heap[i]);
    }
    printf("\n");
}

int searchHeadp( int x){
    for(int i = 0; i <heapSize; i++){
        if( heap[i] == x ){
            return 1;
        }
    }
    return 0;
}

int main(){

    int n = 30;

    printf("\n Enter the number of elements in the sequence : ");
    scanf("%d", &n);

    int i=1;
    push(1);
    int mul[3] = {2, 3, 5};
    printf("\n Sequence : ");

    while( i<=n){
        int x = top();
        pop();
        // printf(" %d = %d \n", i, x);
        printf(" %d", x);

        for( int j=0; j<3; j++){
            int val = mul[j]*x;
            if((searchHeadp(val) == 0) ){
                push(val);
            }
        }

        // if( (i+heapSize) > n){
        //     i++;
        //     printf(" ( %d = %d ) ", i, x);
        //     print();
        //     break;
        // }

        i++;
    }

    while( i<=n ){
        int x = top();
        pop();
        // printf(" %d = %d \n", i, x);
        printf(" %d",x);
        i++;
    }

    printf("\n\n");

    return 0;
}