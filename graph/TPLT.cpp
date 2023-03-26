#include<bits/stdc++.h>
using namespace std;
vector<int> Adj[1001];
vector<int> iComponent(1001,-1);
void Find_Component(int cur_comp , int u) {
    if(iComponent[u] != -1 )return;
    iComponent[u] = cur_comp;
    for(int i = 0 ; i < Adj[u].size() ; ++i){
        int v = Adj[u][i];
        Find_Component(cur_comp,v);
    }
}
int num_comp = 0;
for(int u = 1 ; u <= n ; ++u){
    if (iComponent[u] == -1){
        Find_Component(num_comp,u);
        num_comp++;
    }
}