#include<bits/stdc++.h>
using namespace std;
#define maxN 1000001
int n;
int a[maxN];
int iMem[maxN];
int Trung(int i){
    if(i==1)return 1;
    if(iMem[i]!=-1)return iMem[i];
    int res;
    if(a[i]>a[i-1])res = Trung(i-1)+1;
    else res = 1;
    iMem[i]=res;
    return res;
}
int main(){
    cin >> n;
    for ( int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    memset(iMem, -1 , sizeof(iMem));
    for(int i = 1 ; i <= n ; i++){
        Trung(i);
    }
    int ans = 0;
    for(int i = 1 ; i <= n ; i++){
        ans = max(ans,iMem[i]);
    }
    printf("%d",ans);
}