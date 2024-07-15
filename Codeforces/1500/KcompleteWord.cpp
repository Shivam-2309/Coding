#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define vll vector<ll>


void dfs(ll node, vector<ll> adj[], vector<ll> &vis, map<ll, ll> &mp, string &s){
    if(node < s.length()) mp[s[node]]++;
    if(node < s.length()) vis[node] = 1;

    for(auto &child : adj[node]){
        if(child < s.length() && !vis[child]){
            dfs(child, adj, vis, mp, s);
        }
    }
}

void solve(){
    ll n, k; cin >> n >> k;
    string s; cin >> s;

    vector<ll> vis(n, 0);
    vector<vector<ll>> edges;
    set<vector<ll>> st;

    for(ll i=0; i<n/2; i++){
        edges.push_back({i, n-i-1});
        st.insert({i, n-i-1});
    }

    for(ll i=0; i<n; i++){
        if(!vis[i]){
            vis[i] = 1;
            for(ll j = i; j < n; j += k){
                vis[j] = 1;
                if(i != j){
                    if(st.find({i, j}) != st.end()){
                        continue;
                    }
                    edges.push_back({i, j});
                }
            }
        }
    }

    vector<ll> adj[n];

    for(auto &edge : edges){
        ll u = edge[0];
        ll v = edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll> visited(n, 0);
    ll ans = 0;

    for(ll i=0; i<n; i++){
        if(!visited[i]){
            map<ll, ll> mp;
            dfs(i, adj, visited, mp, s);

            ll sz = 0;
            ll maxi = -1;

            for(auto &it : mp){
                sz += it.second;
                maxi = max(it.second, maxi);
            }

            ans += (sz - maxi);
        }
    }
    
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
