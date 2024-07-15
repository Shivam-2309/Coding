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
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end());
#define rep(i, n) for (ll i = 0; i < n; i++)
const ll mod7 = 1e9 + 7;
const ll mod9 = 998244353;
ll power(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return res;
}
ll lcm(ll a, ll b)
{
    return a * b / __gcd(a, b);
}
// ll dp[100001];

void dfs(ll node, vector<ll> adj[], vector<ll> &vis, ll col, vector<ll> &team, bool &f){
    vis[node] = 1;
    team[node] = col;

    for(auto &child : adj[node]){
        if(vis[child] && team[child] == col){
            f = true;
            return;
        }
        if(!vis[child]){
            dfs(child, adj, vis, !col, team, f);
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

    for(auto edge : edges){
        ll u = edge[0];
        ll v = edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // now make a bipartite graph simply

    ll col = 0;
    vector<ll> team(n+1, -1);
    vector<ll> vis(n+1, 0);

    for(ll i=1; i<=n; i++){
        ll col = 0;
        bool f = false;
        if(!vis[i]) dfs(i, adj, vis, col, team, f);
        if(f){
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }

    for(ll i=1; i<=n; i++){
        if(team[i] == 1) cout << team[i] << " ";
        else cout << 2 << " ";
    }
    cout << endl;
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
/*     The code finishes, I hope it gets Accepted      */