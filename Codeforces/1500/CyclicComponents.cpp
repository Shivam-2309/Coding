#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

#ifndef ONLINE_JUDGE
#define debug(x) cout << "errr----  " << #x << " " << x << endl 
#define print(v) do { \
                    cout << "vect--" << #v << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << v[i] << " "; \
                    } \
                    cout << "]" << endl; \
                } while (0)
#else
#define debug(x)
#define print(v)
#endif

#define vll vector<ll>
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end())
#define rep(i, n) for (ll i = 0; i < n; i++)
const ll mod7 = 1e9 + 7;

void dfs(ll node, vector<ll> adj[], vector<bool> &vis, vector<ll> &nodes) {
    nodes.push_back(node);
    vis[node] = true;
    for (auto &child : adj[node]) {
        if (!vis[child]) dfs(child, adj, vis, nodes);
    }
}

bool dfs1(ll node, map<ll, ll> &vis, map<ll, ll> &recStack, stack<ll> &st, vector<ll> adj[], ll &len, ll par){
    vis[node] = 1;
    recStack[node] = 1;
    st.push(node);
 
    for(auto &child : adj[node]){
        if(child == par) continue;
        if(!vis[child]){
            if(dfs1(child, vis, recStack, st, adj, len, node)){
                return true;
            }
        }
        else if(recStack[child] == 1){
            len = st.size();
            return true;
        }
    }
 
    recStack[node] = 0;
    st.pop();
 
    return false;
}



void solve() {
    ll n, m; 
    cin >> n >> m;
    vector<pair<ll, ll>> edges(m);
    
    for (ll i = 0; i < m; i++) {
        ll u, v; 
        cin >> u >> v;
        edges[i] = {u, v};
    }

    vector<ll> adj[n + 1];
    for (auto edge : edges) {
        ll u = edge.first;
        ll v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n + 1, false);
    ll cnt = 0;

    for (ll i = 1; i <= n; i++) {
        if (!vis[i]) {
            vector<ll> nodes;
            dfs(i, adj, vis, nodes);
            map<ll, ll> visited;
            map<ll, ll> recStack;
            stack<ll> st;

            ll num = 0;
            for(auto &it : nodes){
                num += adj[it].size();
            }
            num /= 2;

            ll len = 0;
            bool f1 = dfs1(i, visited, recStack, st, adj, len, -1);
            bool f2 = (len == num);

            if(f1 && f2){
                cnt++;
            }
        }
    }

    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}