#include<stdio.h>

int calculateC( char x[], char y[], int i, int j){
    if( i<0 || j<0) {
        return 0;
    }
    if( x[i] == y[j]){
        return calculateC( x, y, i-1, j-1 ) + 1;
    }
    else{
        int shift_i = calculateC(x, y, i-1, j);
        int shift_j = calculateC(x, y, i, j-1);
        return shift_i > shift_j ? shift_i : shift_j;
    }
}

int strLen( char arr[]){
    int len = 0;
    while( arr[len] != '\0' ){
        len++;
    }
    return len;
}

int main(){
    char x[1000],y[1000];

    printf("Enter the First String: ");
    scanf("%s",x);

    printf("Enter the Second String: ");
    scanf("%s",y);

    int n = strLen(x);
    int m = strLen(y);

    int ans = calculateC(x,y,n-1,m-1);
    printf("LCS = %d\n", ans);

    return 0;
}