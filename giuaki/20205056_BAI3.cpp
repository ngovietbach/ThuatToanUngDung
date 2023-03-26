#include<bits/stdc++.h>
using namespace std;
int n,A,B;
int a[21];
int b[21];
bool bMark[21]; 
int tong = 0;
int dem = 0;
void Try(int k ){
    if(k==n+1){
        if(tong >= A && tong <= B)dem++;
        return;
    }
    tong += a[k];
    Try(k+1);
    tong-=a[k];
    Try(k+1);
}
int main(){
    cin >> n >> A >> B;
    for(int i = 1 ; i <= n ; i++ ){
        cin >> a[i];
    }
    Try(1);
    printf("%d",dem);
    return 0;
}