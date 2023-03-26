#include<bits/stdc++.h>
#define MAX 1000000
#define oo -(1e9+6)
using namespace std;
int n;
int a[MAX];
int MaxSub(int a[]){
	int smax = a[1];
	int maxendhere = a[1];
	int imax = 1;
	for (int i = 2 ; i < n ; i++ ){
		int u = maxendhere + a[i];
		int v = a[i];
		if(u>v) maxendhere=  u;
		else maxendhere = v;
		if (maxendhere>smax){
			smax=maxendhere;
			imax=i;
		}
	}
	return smax;
}
int main(){
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
	}
	cout << MaxSub(a);
	return 0;
}
