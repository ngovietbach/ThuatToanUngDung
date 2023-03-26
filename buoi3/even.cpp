#include<bits/stdc++.h>
using namespace std;
#define maxN 1000001
int n ; 
int a[maxN];
int iC[maxN];
int iL[maxN];
void even(int i){
    if(i==1){
        if(a[i]%2==0){
            iC[1]=a[i];
            iL[1]=-2;
        }
        else{
            iC[1]=-1;
            iL[1]=a[i];
        }
        return ;
    }
    if(abs(a[i])%2==0){
        if(iC[i-1]!=-1)iC[i] = max(a[i],iC[i-1] + a[i]);
        else iC[i] = a[i];
        if(iL[i-1]!=-2)iL[i] = iL[i-1] + a[i];
        else iL[i] = -2;
    }
    else{
        if(iC[i-1]!=-1)iL[i] =max( a[i],iC[i-1] + a[i]);
        else iL[i] = a[i];
        if(iL[i-1]!=-2)iC[i] = iL[i-1] + a[i];
        else iC[i] = -1;
    }
}
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    for ( int i = 1 ; i <= n ; i++){
        even(i);
    }
    int ans = 0;
    for(int i = 1 ; i <= n ; i++){
        ans = max(ans,iC[i]);
    }
    printf("%d",ans);
}