#include<bits/stdc++.h>
using namespace std;
#define maxN 100001
int T;
int N,C[21];
int x[maxN];
void input(){
    cin >> T;
    for(int i = 1 ; i <= T ; i++  ){
        cin >> N;
        cin >> C[i];
    }
    for (int i = 1 ; i <= N ; i++){
        cin >> x[i];
    }
}
void Partition(int A[] , int left , int right){
    if(left >= right){
        return;
    }
    else{
        int pivot = A[(left + right) / 2] ;
        int i = left;
        int j = right;
        while()

    }
}