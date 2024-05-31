#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;
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
#define vp vector<pair<long long, long long>>
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end());
#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
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
// ll dp[NUM];
void dfs(ll node, vector<ll> adj[], vector<ll> &vis, ll &col1, ll &col2, ll col, vector<ll> &temp){
    vis[node] = 1;
    if(col == 0){
        col1++;
        temp.push_back(node);
    }
    else{
        col2++;
        temp.push_back(-1*(node));
    }

    for(auto &child: adj[node]){
        if(!vis[child]){
            if(col == 0){
                dfs(child, adj, vis, col1, col2, 1, temp);
            }
            else{
                dfs(child, adj, vis, col1, col2, 0, temp);
            }
        }
    }
}

void solve(){
    ll n;
    cin >> n;

    vector<ll> adj[n+1];

    for(ll i=0; i<n-1; i++){
        ll u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll col1 = 0;
    ll col2 = 0;
    vector<ll> vis(n+1, 0);
    vector<ll> temp;
    dfs(1, adj, vis, col1, col2, 0, temp);

    // debug(col1);
    // debug(col2);
    // print(temp);

    set<ll> st1;
    set<ll> st2;

    for(ll i=0; i<temp.size(); i++){
        if(temp[i] < 0) st1.insert(abs(temp[i]));
        else st2.insert(abs(temp[i]));
    }

    // for(auto &i: st1){
    //     cout << i << " ";
    // }cout << endl;

    // for(auto &i: st2){
    //     cout << i << " ";
    // }cout << endl;

    ll sum = 0;

    for(ll i=1; i<=n; i++){
        ll sz = adj[i].size();
        // debug(sz);
        if(st1.find(i) != st1.end()){
            sum += max(0ll, st2.size() - sz);
        }
        else{
            sum += max(0ll, st1.size() - sz);
        }

        // debug(sum);
    }

    cout << sum/2 << endl;
}
// Read the question again
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // sieveOfEratosthenes()
    // memset(dp, -1, sizeof(dp));
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*     The code finishes, I hope it gets Accepted      */