#include<stdio.h>

int calculateM( int arr[], int i, int j){
    
    if( i==j){
        return 0;
    }
    int ans = __INT_MAX__;
    for( int k=i; k<j; k++){
        int res = calculateM(arr,i,k) + calculateM(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
        ans = res < ans ? res : ans;
    }
    return ans;
}

int main(){
    int p[10000];
    int n;

    printf("Enter the length of the Array : ");
    scanf("%d", &n);

    printf("Enter the Values\n");

    for( int i=0; i<n; i++){
        printf("Value %d : ",i+1);
        scanf("%d", &p[i]);
    }

    int res = calculateM(p, 1, n-1);
    printf("ans = %d\n", res);

    return 0;
}