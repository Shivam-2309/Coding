#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MAXN = 200000;
const ll LOG = 20;

ll up[MAXN][LOG];
vector<ll> adj[MAXN];
vector<ll> lvl(MAXN, 0);
vector<ll> parent(MAXN, -1); // Initialize parent vector

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

void dfs1(ll node, ll par){
    if(par != -1) parent[node] = par;
    for(auto &it : adj[node]){
        if(it == par) continue;
        dfs1(it, node);
    }
}

ll dfs2(ll node, vector<ll> &paths, ll par){
    ll path = paths[node];
    for(auto &child : adj[node]){
        if(child != par) path += dfs2(child, paths, node);
    }
    paths[node] = path;
    return path;
}

void solve(){
    ll n, m; cin >> n >> m;
    for(ll i=0; i<n-1; i++){
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, -1);
    blf(1, -1);
    
    queue<ll> q;
    q.push(1);
    ll currLevel = 0;
    while(!q.empty()){
        ll sz = q.size();
        for(ll i=0; i<sz; i++){
            ll frontNode = q.front();
            q.pop();
            lvl[frontNode] = currLevel;
            for(auto &it : adj[frontNode]){
                if(it == parent[frontNode]) continue;
                q.push(it);
            }
        }
        currLevel++;
    }

    vector<ll> paths(n + 1, 0);
    for(ll i = 1; i <= m; i++){
        ll u, v; cin >> u >> v;
        ll lca = LCA(u, v);
        paths[u] += 1;
        paths[v] += 1;
        paths[lca] -= 1;
        if(parent[lca] != -1) paths[parent[lca]] -= 1;
    }

    dfs2(1, paths, -1);
    for(ll i = 1; i <= n; i++) cout << paths[i] << " ";
    cout << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
