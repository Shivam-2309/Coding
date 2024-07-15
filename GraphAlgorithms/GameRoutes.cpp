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

int dp[200001];

ll dfs(ll node, vector<ll> adj[], ll n){
    if(node == n){
        return 1;
    }

    if(dp[node] != -1) return dp[node];

    ll ways = 0;
    for(auto &child : adj[node]){
        ways += dfs(child, adj, n);
        ways = (ways % mod7);
    }

    return dp[node] = ways;
}

void solve(){
    memset(dp, -1, sizeof(dp));
    ll n, m; cin >> n >> m;

    vector<ll> adj[n+1];
    for(ll i=0; i<m; i++){
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    dp[n] = 1;
    ll ans = dfs(1, adj, n);

    cout << dp[1] << endl;
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