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

void dfs(ll node, vector<ll> adj[], vector<ll> &parent, ll par, ll level){
    if(par != -1) parent[node] = par;
    lvl[node] = level;
    for(auto &it : adj[node]){
        if(it == par) continue;
        dfs(it, adj, parent, node, level+1);
    }
}

void solve(){
    ll n, qq; cin >> n >> qq;
    vector<ll> parent(n + 1, -1);
    parent[1] = -1;
    for (ll i = 2; i <= n; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<ll> q;
    q.push(1);
    lvl[1] = 0;
    dfs(1, adj, parent, -1, 0);
    // for(ll i=1; i<=n; i++) cout << lvl[i] << " ";
    // cout << endl;
    blf(1, -1);

    while(qq--){
        ll a, b; cin >> a >> b;
        ll lca = LCA(a, b);
        // cout << "LCA is -> " << lca << endl;
        cout << lvl[a] + lvl[b] - 2*lvl[lca] << endl;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.precision(15);
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}