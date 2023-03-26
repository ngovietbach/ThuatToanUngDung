#include <bits/stdc++.h>
using namespace std;
const int N=100100;
int a[N],Log[N],st[N][20];
long long value = 0;
void pre_process(int n){
    Log[1]=0;
    for(int i=2;i<=n;i++) Log[i]=Log[i/2]+1;
    for(int i=0;i<n;i++) st[i][0]=i;
    for(int j=1;j<=Log[n];j++)
        for(int i=0;i+(1<<j)<=n;i++){
            int x=st[i][j-1],y=st[i+(1<<(j-1))][j-1];
            st[i][j]=a[x]<=a[y]?x:y;
        }
}

int query(int l,int r){
    int k=Log[r-l+1];
    int x=st[l][k],y=st[r-(1<<k)+1][k];
    return a[x]<=a[y]?x:y;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    pre_process(n);
    int q,l,r;
    cin>>q;
    while(q--){
        cin>>l>>r;
        value+=a[query(l,r)];
    }
    printf("%ld",value);
    return 0;
}
