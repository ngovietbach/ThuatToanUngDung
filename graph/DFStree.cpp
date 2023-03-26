#include<bits/stdc++.h>
using namespace std;
const int n = 1001;
vector<int> Adj[n];
vector<int> Low(n), Num(n,-1);
int cur_num= 0 ; 
void AnalyzeDFS(int u , int p ){
    Low[u] = Num[u] = ++cur_num;
    for(int i = 0 ; i < Adj[u].size() ; ++i) {
        int v = Adj[u][i];
        if (v == p)continue;
        if (Num[v] == -1) {
            AnalyzeDFS(v,u);
            Low[u] = min (Low[u], Low[v]);
        }else {
           Low [u] = min(Low[u], Num[v]); 
        }
    }
}