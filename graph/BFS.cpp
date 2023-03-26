#include<bits/stdc++.h>
using namespace std;
vector<int> Adj[1001];
vector<bool> bVisited(1001 , false);
queue<int> Q;
Q.push(start);
bVisited[start] = true;
while (!Q.empty()){
    int u = Q.front();
    Q.pop();
    for(int i = 0 ; i < Adj[u].size() ; ++i) {
        int v = Adj[u][i];
        if (!bVisited[v]){
            Q.push(v);
            bVisited[v] = true ;
        }
    }
}