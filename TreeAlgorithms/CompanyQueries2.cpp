#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MAXN = 1000000;
const ll LOG = 20;

ll up[MAXN][LOG];
vector<ll> adj[MAXN];
vector<ll> lvl(MAXN, 0);

void blf(ll src, ll par) {
    up[src][0] = par;
    for (ll i = 1; i < LOG; i++) {
        if (up[src][i-1] != -1) up[src][i] = up[up[src][i-1]][i-1];
        else up[src][i] = -1;
    }
    for (ll child : adj[src]) {
        if (child != par) blf(child, src);
    }
}

ll lift_node(ll node, ll jump_req) {
    for (ll i = LOG - 1; i >= 0; i--) {
        if (jump_req == 0 || node == -1) break;
        if (jump_req >= (1 << i)) {
            jump_req -= (1 << i);
            node = up[node][i];
        }
    }
    return node;
}

ll LCA(ll u, ll v) {
    if (lvl[u] < lvl[v]) swap(u, v);
    u = lift_node(u, lvl[u] - lvl[v]);
    if (u == v) return u;
    for (ll i = LOG - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

void solve() {
    ll n; cin >> n;
    ll qq; cin >> qq;
    vector<ll> parent(n + 1, -1);
    parent[1] = -1;
    for (ll i = 2; i <= n; i++) {
        cin >> parent[i];
        adj[i].push_back(parent[i]);
        adj[parent[i]].push_back(i);
    }

    // Initialize the levels using BFS
    queue<ll> q;
    q.push(1);
    lvl[1] = 0;
    while (!q.empty()) {
        ll frontNode = q.front();
        q.pop();
        for (auto &child : adj[frontNode]) {
            if (child != parent[frontNode]) {
                lvl[child] = lvl[frontNode] + 1;
                q.push(child);
            }
        }
    }

    // Build the binary lifting table
    blf(1, -1);

    // Process queries
    while (qq--) {
        ll u, v; cin >> u >> v;
        cout << LCA(u, v) << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
