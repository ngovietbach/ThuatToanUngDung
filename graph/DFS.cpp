#include<bits/stdc++.h>
using namespace std;
vector<int> Adj[1001];
vector<bool> bVisited(1001,false);
vector<bool> bMarked(1001,false);
void DFS(int u){
    if (bMarked[u])return;
    bMarked[u] = true;
    bVisited[u] = true;
    for(int i = 0 ; i < Adj[u].size() ; ++i ){
        int v = Adj[u][i];
        bVisited[v] = true;
        DFS(v);
    }
}