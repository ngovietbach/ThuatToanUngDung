#include<bits/stdc++.h>
using namespace std;
#define maxN 1000000
int n;
int a[maxN];
int iMem[maxN];
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    iMem[0] = a[0];
    iMem[1] = max(a[0],a[1]);
    for(int i = 2 ; i <= n ; i++ ){
        iMem[i] = max(iMem[i-1],iMem[i-2]+a[i]);
    }
    printf("%d",iMem[n]);
    return 0;
}