#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int INF = 1e9;
const int MAXN = 20;
const int MAXS = (1 << MAXN);
int n, m, q, s;
int dist[MAXN][MAXN], dp[MAXS][MAXN], w[MAXN];
bool is_terminal[MAXN];

int main() {
    cin >> n >> m >> q >> s;
    for(int i = 0; i < n; i++) {
        w[i] = INF;
        is_terminal[i] = false;
    }
    w[s] = 0;
    for(int i = 0; i < q; i++) {
        int x; cin >> x;
        is_terminal[x] = true;
    }
    for(int i = 0; i < m; i++) {
        int u, v, d; cin >> u >> v >> d;
        dist[u][v] = dist[v][u] = d;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(dist[i][j] == 0) {
                dist[i][j] = INF;
            }
        }
    }
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for(int i = 0; i < MAXS; i++) {
        for(int j = 0; j < n; j++) {
            dp[i][j] = INF;
        }
    }
    for(int i = 0; i < n; i++) {
        if(is_terminal[i]) {
            dp[1 << i][i] = w[i];
        }
    }
    for(int mask = 1; mask < (1 << n); mask++) {
        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) {
                for(int j = 0; j < n; j++) {
                    if(i != j && (mask & (1 << j))) {
                        dp[mask][i] = min(dp[mask][i], dp[mask ^ (1 << i)][j] + dist[j][i] + w[i]);
                    }
                }
            }
        }
    }
    int ans = INF;
    for(int mask = 1; mask < (1 << n); mask++) {
        if((mask & (1 << s)) == 0) {
            continue;
        }
        int cur = 0;
        for(int i = 0; i < n; i++) {
            if((mask & (1 << i)) && is_terminal[i]) {
                cur += w[i];
            }
        }
        for(int i = 0; i < n; i++) {
            ans = min(ans, cur + dp[mask][i]);
        }
    }
    cout << ans << endl;
    return 0;
}
