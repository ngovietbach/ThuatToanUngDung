#include<bits/stdc++.h>
#define MAX 1000000
using namespace std;
int a[MAX];
int main(){
    int n;
    int Q = 0;
    cin >> n;
    for(int i = 1 ; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 2 ; i <= n-1 ; i++){
        if((a[i] > a[i+1]) && (a[i] > a[i-1]) ){
            Q += 1;
        }
    }
    printf("%d",Q);
    return 0;
}