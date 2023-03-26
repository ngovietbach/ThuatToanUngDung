#include<bits/stdc++.h>
using namespace std;
#define maxN 100001
int n,k,m;
int a[maxN];
int iMem[maxN];
int dem = 0;
void input(){
    cin >> n >> k >> m;
    for ( int i = 1 ; i < n ; i++){
        cin >> a[i];
    }
}
void solution(){
    int ans = 0;
    for(int i = 1 ; i <= k ; i++){
        ans += a[i];
    }
    //printf("%d\n",ans);
    if(ans==m)dem++;
    for(int i = k+1 ; i <= n;i++){
        ans = ans + a[i] - a[i-k];
        //printf("%d\n",ans);
        if(ans==m)dem++;
    }
}
int main(){
    input();
    solution();
    printf("%d",dem);
}