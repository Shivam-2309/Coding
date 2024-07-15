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


// for finding the single source shortest path
// Assumption is made that the graph must not have any negative weights or negative cycle
// Works for both the Directed and undirected edge

vector<ll> dijkstra(ll V, vector<vector<ll>> adj[], ll S) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll> distTo(V+1, LLONG_MAX);

    distTo[S] = 0;
    pq.push({0ll, S});
    vector<ll> vis(V+1, 0);

    while (!pq.empty()) {
        ll node = pq.top().second;
        ll dis = pq.top().first;
        pq.pop();

        if(vis[node]) continue;
        vis[node] = 1;

        for (auto &it : adj[node]) {
            ll v = it[0];
            ll w = it[1];
            if (dis + w < distTo[v]) {
                distTo[v] = dis + w;
                pq.push({dis + w, v});
            }
        }
    }
    return distTo;
}

void solve(){
    ll n, m; cin >> n >> m;

    vector<vector<ll>> edges;
    for(ll i=0; i<m; i++){
        ll u, v, wt; cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }

    vector<vector<ll>> adj[n+1];

    for(auto edge : edges){
        ll u = edge[0];
        ll v = edge[1];
        ll wt = edge[2];

        adj[u].push_back({v, wt});
    }

    vector<ll> ans = dijkstra(n, adj, 1);
    for(ll i=1; i<=n; i++){
        cout << ans[i] << " ";
    }cout << endl;
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