#include<bits/stdc++.h>
using namespace std;
#define maxN 1000000
int n,M;
int a[maxN];
int x[maxN];
int f = 0 ;
int t = 0;
int dem = 0;
void input(){
    cin >> n;
    cin >> M;
    for(int i = 0 ; i < n ; i++ ){
        cin >> a[i];
        t += a[i];
    }
}
void loigiai(){
    dem++;
}
void Try(int k){
    if(k==n-1){
        if(((M-f)%a[k])!=0)dem--;
        x[k] =(int) (M-f) / a[k];
        return loigiai();
    }
    int cTren =(int)(M - f - t + a[k] )/a[k];
    for(int i = 1 ; i <= cTren ; ++i){
        x[k] = i;
        f += x[k] * a[k];
        t -= a[k];
        Try(k+1);
        f -= x[k] * a[k];
        t += a[k];      
    }
}
int main(){
    input();
    Try(0);
    printf("%d",dem);
}