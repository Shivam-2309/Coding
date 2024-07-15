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
                    cout << "]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#endif
#define ll long long
#define vll vector<ll>
 
void dfs(ll node, vector<ll> adj[], vector<ll> &vis, ll parent, vector<ll> &ans, vector<ll> &par, bool &f){
    vis[node] = 1;
    par[node] = parent;
 
    for(auto &child : adj[node]){
        if(child == parent) continue;
        if(!vis[child]) dfs(child, adj, vis, node, ans, par, f);
        else if(vis[child] && child != parent && !f){
            f = true;
            ans.push_back(child);
 
            ll currNode = node;
            while(currNode != child && par[node] != -1){
                ans.push_back(currNode);
                currNode = par[currNode];
            }
            ans.push_back(child);
            return;
        }
    }
}
 
void solve(){
    ll n, m; cin >> n >> m;
    vector<vector<ll>> edges;
 
    for(ll i=0; i<m; i++){
        ll u, v; cin >> u >> v;
        edges.push_back({u, v});
    }
 
    vector<ll> adj[n+1];
    for(auto &edge : edges){
        ll u = edge[0];
        ll v = edge[1];
 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll> par(n+1, -1);
    vector<ll> vis(n+1, 0);

    for(ll i=1; i<=n; i++){
        vector<ll> ans;
        bool f = false;
        if(!vis[i]){
            dfs(i, adj, vis, -1, ans, par, f);
        }

        if(ans.size()){
            cout << ans.size() << endl;
            for(auto points : ans){
                cout << points << " ";
            }cout << endl;
            return;
        }
    } 
 
    cout << "IMPOSSIBLE" << endl;
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
