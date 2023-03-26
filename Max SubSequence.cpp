#include<bits/stdc++.h>
using namespace std;
#define maxN 1000000
int MaxLeft(int a[],int i,int j){
    int maxSum = -10;
    int sum = 0;
    for (int k = j; k >= i ; k-- ){
        sum += a[k];
        if(sum > maxSum)maxSum = sum;

    }
    return maxSum;
}
int MaxRight(int a[],int i,int j){
    int maxSum = -10;
    int sum = 0;
    for (int k = i; k <= j ; k++ ){
        sum += a[k];
        if(sum > maxSum)maxSum = sum;

    }
    return maxSum;
}
int MaxSub(int a[],int i,int j){
    if(i == j)return a[i];
    else{
        int m = (i+j)/2;
        int wL = MaxSub(a,i,m);
        int wR = MaxSub(a,m+1,j);
        int wM = MaxLeft(a,i,m) + MaxRight(a,m+1,j);
        int max =0 ;
        max = wL > wR ? wL : wR;
        max = max > wM ? max : wM;
        return max; 
    }
}
int main(){
    int n;
    int a[maxN];
    cin >> n;
    for(int g = 0; g < n ; g++ ){
        cin >> a[g];
    }
    int max;
    max=MaxSub(a,0,n-1);
    cout << max << endl;
    return 0;
}