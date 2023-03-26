#include<bits/stdc++.h>
using namespace std;
#define maxN 1000001
int iMem[maxN];
int A[maxN];
int n,m;
bool bMark[maxN];
int B[10001][10001];
int X[10001];
int Y[10001];
int Fib(int n ){
    if(n <= 2) return 1;
    if(iMem[n] != -1 )return iMem[n];
    int res = Fib(n-2) + Fib(n-1);
    iMem[n] = res;
    return res;
}
int MaxSum(int i ){
    if ( i == 1)return A[i];
    if(bMark[i])return iMem[i];
    int res = max(A[i],A[i]+MaxSum(i-1));
    iMem[i] = res;
    bMark[i] = true;
    return res;
}
int LIS(int i ){
    if(iMem[i] != -1)return iMem[i];

    int res = 1;
    for(int j = 1 ; j < i ; j++){
        if(A[j] < A[i]){
            res = max(res,1+LIS(j));
        }
    }
    iMem[i] = res;
    return res;
}
int LCS(int i , int j){
    if(i==0)return 0;
    if(j==0)return 0;
    if(B[i][j]!= -1)return B[i][j];
    int res = 0;
    res = max(res,LCS(i,j-1));
    res = max(res,LCS(i-1,j));
    if(X[i] == Y [j]){
        res = max(res,1+LCS(i-1,j-1));
    }
    B[i][j] = res;
    return res;
}
int main(){
    cin >> n >> m;
        for(int i = 1 ; i < 10001 ; i++){
        for(int j = 1 ; j < 10001 ; j++){
                    B[i][j] = -1;

        }
        }
    for(int i = 1 ; i <= n ; i++ ){
        cin >> X[i];
    }
    for ( int j = 1 ; j <= m ; j++){
        cin >> Y[j];
    }
    for(int i = 1 ; i <= n ; i++){
        for ( int j = 1 ; j <= m ; j++){
            B[i][j]=LCS(i,j);
        }
    }

printf("%d",B[n][m]);
return 0 ;
}

