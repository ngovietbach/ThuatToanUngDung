#include<bits/stdc++.h>
using namespace std;
#define maxN 100000000
int A[maxN];
int n;
int dem = 0;
int x[maxN];
bool bMark[maxN];
int m ;
int f = 0;
int iRes[maxN]  ; // row = hang
bool bCol[maxN] ; // cot
bool bDiag1[maxN] ; // duong cheo 1
bool bDiag2[maxN] ; // duong cheo 2
void loigiai(){
    for(int i = 1 ; i <= n ; i++){
        printf("%d",A[i]);
    }
    printf("\n");
}
void Try1(int k){// liet ke xau nhi phan do dai n
    for(int i = 0 ; i <= 1; i++){
        A[k] = i;
        if(k==n)loigiai();
        else Try1(k+1);
    }
}
void Try2(int k){// liet ke hoan vi cua n phan tu
    for(int i = 1 ; i <= n ; i++){
        if(!bMark[i]){
            A[k] = i;
            bMark[i] = true;
            if(k == n)loigiai();
            else Try2(k+1);
            bMark[i] = false;
        }
    }
}
void Try3(int k){// chia keo 
    if(k == n){
        x[k] = m - f;
        return loigiai();
    }
    int m0 = m - f - (n - k);
    for (int v = 1 ; v <= m0 ; ++v){
        x[k] = v;
        f = f + v;
        Try3(k+1);
        f = f - v ;  
    }
}
void Try4(int i){// bai toan xep hau
    for(int j = 1 ; j  <=  n ; j++){
        if(bCol[j] && bDiag1[i+j] && bDiag2[i-j]){
            iRes[i] = j;
            bCol[j] = false;
            bDiag1[i+j] = false ; bDiag2[i - j] = false;
            if(i==n)loigiai();
            else Try4(i+1);
            bCol[j] = true;
            bDiag1[i+j] = true ; bDiag2[i - j] = true;
        }
    }
}
int main(){
   cin >> n ;
   Try1(1);
}