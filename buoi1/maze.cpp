#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
const int maxN = 999+100;
int A[maxN][maxN];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int D[maxN][maxN];
queue <ii> qe;
int i,j;
int n,m,r,c;
int solve(int a,int b){
    qe.push(ii(a,b));
    D[a][b]=0;
    A[a][b]=1;
    while(!qe.empty()){
        ii u=qe.front();
        qe.pop();
        for(i=0;i<4;i++){
            int x = dx[i]+u.first;
            int y = dy[i]+u.second;
            if( x<1 || x>n || y<1 || y>m ) return D[u.first][u.second]+1;
            if(A[x][y]!=1){
                D[x][y]=D[u.first][u.second]+1;
                qe.push(ii(x,y));
                A[x][y]=1;
            }
        }
    }
    return -1;
}
int main(){
    cin >> n;
    cin >> m;
    cin >> r;
    cin >> c;
    for( i= 1; i <= n ; i++){
        for( j = 1 ; j <= m ; j++){
            cin >> A[i][j];
        }
    }
    int k=solve(r,c);
    cout << k;
    return 0;
}

