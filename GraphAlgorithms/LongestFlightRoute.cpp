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

ll dfs(ll curr, vector<ll> adj[], vector<ll> &next, ll n){
    if(curr == n){
        dp[n] = 0;
        next[n] = 1;
        return 0;
    }

    if(dp[curr] != -1) return dp[curr];

    int dist = -1e9;
    for(auto &child : adj[curr]){
        ll distFromChild = dfs(child, adj, next, n);
        if(1 + distFromChild > dist){
            dist = 1 + distFromChild;
            next[curr] = child;
        }
    }

    return dp[curr] = dist;
}

void solve(){

    memset(dp, -1, sizeof(dp));
    ll n, m; cin >> n >> m;
    vector<ll> adj[n+1];

    for(ll i=0; i<m; i++){
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<ll> next(n+1, -1);
    dfs(1, adj, next, n);

    // dp[i] -> maximum distance from the current node to the nth node

    if(next[n] == -1){
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    vector<ll> ans;
    ll currNode = 1;
    ans.push_back(currNode);
    currNode = next[currNode];
    while(currNode != 1){
        ans.push_back(currNode);
        currNode = next[currNode];
    }

    cout << ans.size() << endl;
    for(ll i=0; i<ans.size(); i++){
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