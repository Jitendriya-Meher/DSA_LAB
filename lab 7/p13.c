#include<stdio.h>

int LCS( char x[], char y[], int n, int m){

    int dp[n+1][m+1];
    for( int i=0; i<=n; i++){
        for( int j=0; j<=m; j++){
            dp[i][j] = 0;
        }
    }

    for( int i=1; i<=n; i++){
        for( int j=1; j<=m; j++){
            if( x[i-1] == y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
            }
        }
    }

    return dp[n][m];
}

int findLength(char s[]){

    int len = 0;

    while( s[len] != '\0' ){
        len++;
    }

    return len;
}

int main(){

    char x[100], y[100];

    printf("Enter the First String : ");
    scanf("%s",x);

    printf("Enter the Second String : ");
    scanf("%s",y);

    int n = findLength(x);
    int m = findLength(y);

    printf("n = %d, m = %d\n",n,m);

    int ans = LCS(x,y,n,m);

    printf("Answer : %d",ans);

    return 0;
}