#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#define print(v) do { \
                    cout << "vect--" << #v << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << v[i] << " "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#define print2d(v) do { \
                    cout << "vect-- starts" << endl; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "[" << " "; \
                        for (int j = 0; j < v[i].size(); j++) { \
                            cout << v[i][j] << " "; \
                        } \
                        cout << "]" << endl; \
                    } \
                    cout << "vect-- ends" << endl; \
                } while(0)
#define printmap(m) do { \
                    cout << "map-- starts" << endl; \
                    for (auto it = m.begin(); it != m.end(); ++it) { \
                        cout << it->first << " -> " << it->second << endl; \
                    } \
                    cout << "map-- ends" << endl; \
                } while(0)
 
#define printpp(v) do { \
                    cout << "vect--" << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "(" << v[i].first << ", " << v[i].second << ") "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#define print2d(v)
#define printmap(m)
#define printpp(v)
#endif

#define vll vector<ll>
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end());
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < n; i++)
const ll mod7 = 1e9 + 7;
ll getSubtrees(ll node, vector<ll> adj[], vector<ll> &vis, vector<ll> &subtree) {
    vis[node] = 1;
    ll currSize = 1;

    for (auto &child : adj[node]) {
        if (!vis[child]) {
            currSize += getSubtrees(child, adj, vis, subtree);
        }
    }
    return subtree[node] = currSize;
}

void getLevels(ll node, vector<ll> adj[], vector<ll> &vis, vector<ll> &levels, ll currLevel){
    vis[node] = 1;
    levels[node] = currLevel;

    for(auto &child : adj[node]){
        if(!vis[child]){
            getLevels(child, adj, vis, levels, currLevel + 1);
        }
    }
}

void solve(){
    ll n, k; cin >> n >> k;
    vector<pair<ll, ll>> edges;
    for(ll i = 1; i <= (n - 1); i++){
        ll u, v; cin >> u >> v;
        edges.push_back({u, v});
    }

    vector<ll> adj[n + 1];
    for(auto &edge : edges){
        ll u = edge.first;
        ll v = edge.second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll> vis(n + 1, 0);
    vector<ll> subtree(n + 1, 0);
    vector<ll> levels(n + 1, 0);

    ll totalNodes = getSubtrees(1, adj, vis, subtree);
    fill(vis.begin(), vis.end(), 0);
    getLevels(1, adj, vis, levels, 0);

    vector<ll> v;
    for(ll i = 1; i <= n; i++){
        v.push_back(levels[i] - subtree[i]);
    }
    
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    print(v);

    ll ans = 0;
    for(ll i = 0; i < k; i++){ 
        ans += (v[i] + 1);
    }

    cout << ans << endl;
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