#include<bits/stdc++.h>
using namespace std;
#define maxN 10^6
int n,M;
int coun = 0;
int A[maxN];

int t[maxN];
int X[maxN];
int f = 0;
void solution(){
    if(f==M) coun++;
}
void TRY(int k){
    int v;
    for(v= 1 ; v <= (M - f - (t[n] - t[k]))/A[k] ; v++){
        X[k] = v;
        cout << v ;
        f += A[k]*X[k];
        if(k==n)solution();
        else {TRY(k+1);}
        f -= A[k]*X[k];
    }
}

int main(){
    int i;
    int tong = 0;
    cin >> n;
    cin >> M;
    for(i = 0 ; i < n ; i++){
        cin >> A[i];
        cout << A[i];
    }
    for(i = 0 ; i < n ; i++){
        tong += A[i];
        t[i] = tong;
        cout << t[i];
    }
    TRY(0);
    cout << coun << endl;
    return 0;
}