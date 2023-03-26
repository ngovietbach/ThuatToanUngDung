#include<bits/stdc++.h>
using namespace std;
int n ; 
int A[11];
void loigiai(){
    for(int i = 1 ; i <= n ; i++ ){
        printf("%d",A[i]);
    }
    printf("\n");
}
void Try(int k){
    for(int i = 0 ; i <= 1 ; i++ ){
        A[k] = i;
        if(k==n)loigiai();
        else Try(k+1);
    }
}
int main(){
    cin >> n;
    Try(1);
}