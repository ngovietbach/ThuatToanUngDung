//Mã này giả định rằng đầu vào được cung cấp theo định dạng sau:

//Dòng đầu tiên chứa ba số nguyên n, m và s, trong đó n là số đỉnh, m là số cạnh và s là đỉnh nguồn.
//m dòng tiếp theo mỗi dòng chứa ba số nguyên, đại diện cho một cạnh (u, v) có trọng số w.
//Đầu ra của chương trình là trọng số tối thiểu của Cây Steiner bao gồm đỉnh nguồn s.
#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX

int n,m,s;
vector<pair<int,int>> adj[2001];
int dist[2001];
bool vis[2001];
int parent[2001];

int prim()
{
    for(int i=1;i<=n;i++)
    {
        dist[i]=INF;
        vis[i]=false;
        parent[i]=-1;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,s});
    dist[s]=0;
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        vis[u]=true;
        for(auto it:adj[u])
        {
            int v=it.first;
            int weight=it.second;
            if(!vis[v] && weight<dist[v])
            {
                dist[v]=weight;
                parent[v]=u;
                pq.push({dist[v],v});
            }
        }
    }
    int sum=0;
    for(int i=1;i<=n;i++)
        sum+=dist[i];
    return sum;
}

int main()
{
    cin>>n>>m>>s;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    cout<<prim()<<endl;
    return 0;
}
