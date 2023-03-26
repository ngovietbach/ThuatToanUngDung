#include<bits/stdc++.h>
using namespace std;
#define maxN 200001
struct Arc{
    int v;
    int w;
    Arc(int _v , int _w){
        v = _v;
        w = _w;
    }
};
int n , m ;
int d[maxN];
vector<Arc> A[maxN];
void input(){
    cin >> n >> m ;
    for(int i = 1 ; i <= n ; i++) {
        cin >> d[i];
    }
    for(int k = 1 ; k <= m ; k++){
        int i, j ; 
        cin >> i >> j;
        Adj[j].push_back(i);
    }
}