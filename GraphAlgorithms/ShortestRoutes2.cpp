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
    // This is a classic Question of Floyd Warshall Algorithm
    ll n, m, q; cin >> n >> m >> q;

    vector<vector<ll>> edges;

    for(ll i=0; i<m; i++){
        ll u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }

    vector<vector<ll>> mat(n+1 ,vector<ll> (n+1, 1e18));
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=n; j++){
            if(i == j) mat[i][j] = 0;
        }
    }

    for(auto edge : edges){
        ll u = edge[0];
        ll v = edge[1];
        ll wt = edge[2];

        mat[u][v] = min(mat[u][v], wt);
        mat[v][u] = min(mat[u][v], wt);
    }

    for(ll k=1; k<=n; k++){
        for(ll i=1; i<=n; i++){
            for(ll j=1; j<=n; j++){
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }

    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=n; j++){
            if(mat[i][j] == 1e18) mat[i][j] = -1;
        }
    }

    while(q--){
        ll u, v; cin >> u >> v;
        cout << mat[u][v] << endl;
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