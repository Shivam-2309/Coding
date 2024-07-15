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

void bellmanford(ll n, vector<vector<ll>> &edges){

    // do iterations n-1 times to check if there is presence of any cycle or not
    vector<ll> dist(n+1, 1e18);
    dist[0] = 0;
    vector<ll> relaxent(n+1, -1);
    ll x;

    for(ll i = 1; i <= n; i++){
        x = -1;
        for(auto edge : edges){
            ll u = edge[0];
            ll v = edge[1];
            ll wt = edge[2];

            if(dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
                relaxent[v] = u;
                x = v;
            }
        }
    }

    if(x == -1){
        cout << "NO" << endl;
        return;
    }
    else{
        // find the nodes which are a part of a negative cycle
       // trace back to the node in a negative cycle

        for(ll i=1; i<=n; i++){
                x = relaxent[x];
        }

        vector<ll> cycle;
        for(ll v = x; ;v = relaxent[v]){
            cycle.push_back(v);
            if(v == x && cycle.size() > 1){
                break;
            }
        }
        rev(cycle);
        cout << "YES" << endl;
        for(ll i=0; i<cycle.size(); i++){
            cout << cycle[i] << " ";
        }cout << endl;
    }
}

void solve(){
    ll n, m; cin >> n >> m;

    vector<vector<ll>> edges;
    for(ll i=0; i<m; i++){
        ll u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }

    for(ll i=1; i<=n; i++){
        edges.push_back({0, i, 0});
    }

    // cout << "CHECK" << endl;

    // simply run bellman ford and try to find out the 
    // number of vertices which are part of ngeative cycle

    bellmanford(n, edges);
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