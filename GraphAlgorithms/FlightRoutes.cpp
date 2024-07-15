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
void solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    vector<vector<ll>> edges;
    for(ll i = 0; i < m; i++) {
        ll u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }

    vector<vector<pair<ll, ll>>> adj(n+1);
    for(auto &edge : edges) {
        ll u = edge[0];
        ll v = edge[1];
        ll wt = edge[2];
        // Unidirected graph
        adj[u].push_back({v, wt});
    }

    // Run Dijkstra's
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<vector<ll>> dist(n+1, vector<ll>(k, 1e18));
    dist[1][0] = 0;
    pq.push({0, 1});

    while(!pq.empty()) {
        ll node = pq.top().second;
        ll wt = pq.top().first;
        pq.pop();

        if(dist[node][k-1] < wt) continue;

        for(auto &child : adj[node]) {
            ll v = child.first;
            ll d = child.second;

            if(dist[v][k-1] > wt + d) {
                dist[v][k-1] = wt + d;
                pq.push({wt + d, v});
                sort(dist[v].begin(), dist[v].end());
            }
        }
    }

    // Print all k shortest distances to node n
    for(auto it : dist[n]) {
        cout << it << " ";
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