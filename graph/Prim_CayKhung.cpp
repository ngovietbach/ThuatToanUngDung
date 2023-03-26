#include<bits/stdc++.h>
using namespace std;
struct edge{
    int u , v ;
    int weight;
    edge(int _u , int _v , int _w){
        u = _u;
        v = _v;
        weight = _w;
    }
}
vector<edge> Prim(int sn, vector<vector<edge>> Adj){
    vector<bool> bIn_T(n+1 , false);
    vector<edge> res;
    
}