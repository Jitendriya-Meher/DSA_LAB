#include<stdio.h>

int MCM( int p[], int n){

    int dp[n][n];

    for( int i=0; i<n; i++){
        for( int j=0; j<n; j++){
            dp[i][j] = 0;
        }
    }

    for( int d=1; d<n; d++){
        // printf("%d :", d);

        for( int i=1; i<n-d; i++){

            int j=i+d;

            // printf("\t %d %d :", i,j);

            dp[i][j] = __INT_MAX__;

            for( int k=i; k<j; k++){
                int mul = dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j];
                if( dp[i][j] > mul ){
                    dp[i][j] = mul;
                }
            }
        }
    }

    return dp[1][n-1];

}

int main(){

    int p[1000]= {1,2,3,4,5};
    int n;

    // printf("Enter the number of elements in the array : ");
    // scanf("%d", &n);

    // for( int i=0; i<n; i++ ){
    //     printf("Element %d : ",i+1);
    //     scanf("%d", &p[i]);
    // }

    n = 5;
    
    int ans = MCM(p, n);

    printf("Answer : %d\n", ans);

    return 0;
}