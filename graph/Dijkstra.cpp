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
vector<edge> Adj[100];
vector<int> iDist(100,INF);
void Dijkstra(int start){
    iDist[start] = 0 ;
    priority_queue<pair<int , int >, vector<pair<int,int>>,greater<pair<int,int>>> PQ;
    PQ.push(make_pair(iDist[start],start));
    while(!PQ.empty()){
        int u = PQ.top().second;
        PQ.pop();
        for (int i = 0 ; i < Adj[u].size(); i++){
            int v = Adj[u][i].v;
            int w = Adj[u][i].weight;
            if (w + iDist[u] < iDist[v]){
                iDist[v] = w + iDist[u];
                PQ.push(make_pair(iDist[v],v));
            }
        }
    }
}