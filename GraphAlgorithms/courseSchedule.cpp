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
    vector<ll> adj[n+1];
    vector<ll> indegree(n+1, 0);

    for(ll i=0; i<m; i++){
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<ll> q;
    vector<ll> vis(n+1, 0);
    vector<ll> path;
    for(ll i=1; i<=n; i++){
        if(!indegree[i]){
            q.push(i);
        }
    }

    while(!q.empty()){
        ll node = q.front();
        q.pop();
        path.push_back(node);

        for(auto &ngb : adj[node]){
            indegree[ngb]--;

            if(!indegree[ngb]){
                q.push(ngb);
            }
        }
    }

    if(path.size() != n){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        for(auto it : path) cout << it << " ";
        cout << endl;
    }
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