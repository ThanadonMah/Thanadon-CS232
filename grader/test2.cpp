#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 1e5 + 5;
const int INF = 1e9;

vector<pii> adj[MAXN];
bool vis[MAXN];

int prim(int start) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});
    int mst_cost = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        mst_cost += w;
        for (auto [v, weight] : adj[u]) {
            if (!vis[v]) {
                pq.push({weight, v});
            }
        }
    }
    return mst_cost;
}

int main() {
    int n, v, s;
    cin >> n >> v >> s;
    if (s < 1 || s > n) {
        cout << "What did you expect?" << endl;
        return 0;
    }
    int u, w;
    for (int i = 0; i < v; i++) {
        cin >> u >> w;
        int v;
        cin >> v;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int start = 1;
    int mst_cost = prim(start);
    cout << mst_cost << endl;
    return 0;
}
