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

#define vll vector<ll>
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end());
#define rep(i, n) for (ll i = 0; i < n; i++)
const ll mod7 = 1e9 + 7;
const ll mod9 = 998244353;

ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return res;
}

ll lcm(ll a, ll b) {
    return a * b / __gcd(a, b);
}

class Bridges {
private:
    int timer = 1;

    void dfs(ll node, ll parent, vector<ll> adj[], vector<ll> &vis, vector<vector<ll>> &bridges, ll dfsInsertionTime[], ll lowestInsertionTime[]) {
        vis[node] = 1;
        dfsInsertionTime[node] = lowestInsertionTime[node] = timer++;
        
        for (auto child : adj[node]) {
            if (child == parent) continue;

            if (!vis[child]) {
                dfs(child, node, adj, vis, bridges, dfsInsertionTime, lowestInsertionTime);

                if (lowestInsertionTime[child] > dfsInsertionTime[node]) {
                    bridges.push_back({node, child});
                }
                lowestInsertionTime[node] = min(lowestInsertionTime[node], lowestInsertionTime[child]);
            } else {
                lowestInsertionTime[node] = min(lowestInsertionTime[node], dfsInsertionTime[child]);
            }
        }
    }

public:
    vector<vector<ll>> getAllBridges(ll n, vector<ll> adj[]) {
        vector<vector<ll>> bridges;
        vector<ll> vis(n + 1, 0);
        ll dfsInsertionTime[n + 1];
        ll lowestInsertionTime[n + 1];
        memset(dfsInsertionTime, 0, sizeof(dfsInsertionTime));
        memset(lowestInsertionTime, 0, sizeof(lowestInsertionTime));

        for (ll i = 1; i <= n; i++) {
            if (!vis[i]) {
                dfs(i, -1, adj, vis, bridges, dfsInsertionTime, lowestInsertionTime);
            }
        }

        return bridges;
    }
};

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

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> edges(m, vector<ll>(2));
    
    for (ll i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<ll> adj[n + 1];
    for (auto edge : edges) {
        ll u = edge[0];
        ll v = edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Bridges obj;
    vector<vector<ll>> bridges = obj.getAllBridges(n, adj);
    vector<ll> subtrees(n + 1, 1);
    vector<ll> vis(n + 1, 0);

    getSubtrees(1, adj, vis, subtrees);

    ll ans = (n * (n-1))/2;

    for (auto bridge : bridges) {
        ll u = bridge[0];
        ll v = bridge[1];
        
        ll sz1 = subtrees[u];
        ll sz2 = subtrees[v];

        ll left = min(sz1, sz2);
        ll right = n - left;

        // debug(left);
        // debug(right);

        ans = min(ans, (left * (left - 1)) / 2 + (right * (right - 1)) / 2);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
/*     The code finishes, I hope it gets Accepted      */
