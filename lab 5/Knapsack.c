#include<stdio.h>
#include<conio.h>

void print(float arr[], int n){
    for( int i=0; i<n; i++){
        printf("%f ", arr[i]);
    }
    printf("\n");
}

void sort( float profits[], float weights[], int n){

    for( int i=0; i<n; i++){
        for( int j=i+1; j<n; j++){

            float cmp1 = profits[i]/weights[i];
            float cmp2 = profits[j]/weights[j];

            if( cmp1 < cmp2){
                float x = profits[i];
                profits[i] = profits[j];
                profits[j] = x;

                x = weights[i];
                weights[i] = weights[j];
                weights[j] = x;
            }
        }
    }

}

float knapsack( float profits[], float weights[], float capacity, int n){

    print(profits,n);
    print(weights,n);

    sort( profits, weights, n);

    print(profits,n);
    print(weights,n);

    int i=0;
    float total = 0;

    while( i<n && capacity>0){
        if( capacity >= weights[i]){
            total += profits[i];
        }else{
            float ratio = profits[i] / weights[i];
            total += capacity*ratio;
            break;
        }
        capacity -= weights[i];
        i++;
    }

    return total;
}

int main(){

    float profits[] = {120,100,60};
    float weights[] = {30,20,10};
    int n = 3;
    float weight = 50;

    float ans = knapsack( profits, weights, weight, n);
    printf("%f\n", ans);

    return 0;

}