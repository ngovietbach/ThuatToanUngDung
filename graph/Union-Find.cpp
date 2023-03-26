#include<bits/stdc++.h>
using namespace std;
struct edge {
    int u , v;
    int weight;
    edge(int _u , int _v , int _w) {
        u = _u;
        v = _v;
        weight = _w;
    }
}
vector<edge> Adj[5];
Adj[1].push_back(edge(1,2,9));
struct Union_Find {
    vector<int> iParent;
    Union_Find(int n ){
        iParent = vector<int>(n);
        for(int i = 0 ; i < n ; i++){
            iParent[i] = i ;
        }
    }
    int Find(int x){
        if (iParent[x] == x){
            return x;
        }
        else {
            iParent[x] = Find(iParent[x]);
            return iParent[x];
        }
    }
    void Unite(int x , int y){
        iParent[Find(x)] = Find(y);
    }
}

