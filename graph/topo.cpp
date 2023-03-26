#include<bits/stdc++.h>
using namespace std;
#define maxN 200001
vector<int> Adj[maxN];
vector <bool > bVisited (maxN , false );
vector<int> iOrder;

int d[maxN];
int n,m;
void Topo_sort(int u){
    if (bVisited[u])return;
    bVisited[u] = true;
    for (int i = 0 ; i < Adj[u].size() ; ++i) {
        int v = Adj[u][i];
        Topo_sort(v);
    }
    iOrder.push_back(u);
}
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
int main(){
    input();
    for(int i = 1 ; i <= n ; i++ ){
        if(bVisited[i]==false)Topo_sort(i);
    }
    int sum = 0 ;
    for(int i = 0 ; i < iOrder.size() ; i ++ ){
        sum += d[iOrder[i]];
        printf("%d",iOrder[i]);
    }
    //printf("%d\n",iOrder.size());
    //printf("%d",sum);
    return 0;
}
