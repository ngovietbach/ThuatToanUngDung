#include<bits/stdc++.h>
using namespace std;
#define maxN 10000000
void Try ( int k ){
    for (int v = 1 ; v <= n ; ++v){
        if (!bVisited[v]){
            iRes[k] = v;
            bVisited[v] = true;
            f = f + C[iRes[k-1]][v];
            if (k == n){
                if (f + C[v][iRes[1]] < f0) f0 = f + C[v][iRes[1]];
            }
            else{
                g = f + (n - k + 1) * cmin;
                if (g < f0) Try(k+1);
            }
            f = f - C C[iRes[k-1]][v];
            bVisited[v] = flase;
        }
    }
}
int main(){
    for(int v = 1 ; v <= n ; ++v ){
        bVisited[v] = false;
        f0 = INFINITY;
        f = 0;
        iRes[1] = 1;
        bVisited[1] = true;
        Try(2);
        return f0;
    }
}