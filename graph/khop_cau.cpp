#include<bits/stdc++.h>
using namespace std;
#define maxN 43001
int V,E;
vector<int> Adj[maxN];
int Low[maxN], Num[maxN],pa[maxN];
int cur_num = 0 ;
int Bridges = 0 ;
int Articulation = 0;
void input(){
    cin >> V >> E ;
    for(int i = 1 ; i <= E ; i++){
        int a,b ;
        cin >> a >> b ; 
        Adj[a].push_back(b);
        Adj[b].push_back(a);
    }
}
void Finds(int u , int p ) {
    Low[u] = Num[u] = ++cur_num;
    for(int i = 0 ; i < Adj[u].size() ; ++i) {
        int v = Adj[u][i];
        if(v == p ) continue;
        if (Num[v] == -1 ){
            pa[v] = u ;
            Finds(v,u);
            Low[u] = min(Low[u],Low[v]);
        }else{
            Low[u] = min(Low[u],Num[v]);
        }
    }
}
int find_cau() {
	int cau = 0;
	for(int i = 1 ; i <= V ; i++)if(pa[i] > 0 && Low[i] >= Num[i])cau++;
	return cau;
}
int find_khop() {
	int khop[maxN] = {0}, con[maxN] = {0};
	for(int v = 1 ; v <= V ; v++) {
		int u = pa[v];
		if (u > 0) con[u]++;
	}
	for(int v = 1 ; v <= V ; v++) {
		int u = pa[v];
		if (u > 0 && pa[u] > 0 && Low[v] >= Num[u]) khop[u] = 1;
	}
	for(int u = 1 ; u <= V ; u++)if(pa[u] == 0 && con[u] >= 2)khop[u] = 1;
	for(int u = 1 ; u <= V ; u++) khop[0] += khop[u] == 1;
	return khop[0];
}
int main(){
    for(int i = 0 ; i < maxN ; i++) Num[i] = -1;
    input();
    for(int i = 1 ; i <= V ; i++)if(Num[i]==-1)Finds(i,-1);
    printf("%d %d",find_khop(),find_cau());
    return 0;
}