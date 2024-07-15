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

    queue<ll> q;
    vector<ll> vis(n+1, 0);
    q.push(1);

    // i would store the previous possible go to node for that node
    vector<ll> prev(n+1, -1);

    while(!q.empty()){
        auto node = q.front();
        q.pop();

        // debug(node);

        for(auto &child: adj[node]){
            if(child == n){
                prev[child] = node;
                // print(prev);
                // node back track the path
                vector<ll> path;
                path.push_back(child);
                ll currNode = child;
                while(child != 1){
                    path.push_back(prev[child]);
                    child = prev[child];
                }

                reverse(path.begin(), path.end());
                cout << path.size() << endl;
                for(auto &points : path) cout << points << " ";
                cout << endl;
                return;
            }
            if(!vis[child]){
                vis[child] = 1;
                prev[child] = node;
                q.push(child);
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
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