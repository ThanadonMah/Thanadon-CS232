#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int n, m, s;
int adj[MAXN][MAXN];
bool vis[MAXN];
int d[MAXN];

void prim() {
    memset(vis, 0, sizeof(vis));
    memset(d, 0x3f, sizeof(d));
    d[s] = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && (u == -1 || d[j] < d[u])) {
                u = j;
            }
        }

        vis[u] = true;

        for (int v = 1; v <= n; v++) {
            if (adj[u][v] != -1 && adj[u][v] < d[v]) {
                d[v] = adj[u][v];
            }
        }
    }
}

int main() {
    cin >> n >> m >> s;

    if(s != 1)
    {
        cout <<  "What did you expect?";
        return 0;
    }

    memset(adj, -1, sizeof(adj));

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if(u > n || v > n || w < 0 || n <= 0 || v < 0)
        {
            cout <<  "What did you expect?";
            return 0;
        }
        adj[u][v] = adj[v][u] = w;
    }

    prim();

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += d[i];
    }

    cout << ans << endl;

    return 0;
}
