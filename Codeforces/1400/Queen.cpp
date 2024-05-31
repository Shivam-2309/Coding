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
// ll dp[100001];

void dfs(ll node, vector<ll> adj[], vector<ll> &parent, vector<ll> &numberAssigned, vector<ll> &ans){
    ll cnt = 0;
    for(auto children : adj[node]){
        if(parent[node] != children && numberAssigned[children] == 1){
            cnt++;
        }
        if((children != parent[node]) || (parent[node] == -1)) dfs(children, adj, parent, numberAssigned, ans);
    }
    if((cnt == (adj[node].size()-1)) && numberAssigned[node]){
        ans.push_back(node);
    }
}

void solve(){
    ll n;
    cin >> n;

    vector<pair<ll, ll>> v(n);
    
    rep(i, n){
        ll a, b;
        cin >> a >> b;

        v[i] = {a, b};
    }

    // Make a directed graph
    // 1 based indexing
    vector<ll> adj[n+1];
    vector<pair<ll, ll>> edges;
    vector<ll> parent(n+1);
    vector<ll> numberAssigned(n+1);
    ll root = 01;
    for(ll i=0; i<n; i++){
        if(v[i].first == -1){
            // Root of the graph
            parent[i+1] = v[i].first;
            numberAssigned[i+1] = v[i].second;
            root = i+1;
        }
        else{
            parent[i+1] = v[i].first;
            numberAssigned[i+1] = v[i].second;

            edges.push_back({parent[i+1], i+1});
        }
    }

    for(auto &edge : edges){
        ll x = edge.first;
        ll y = edge.second;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vll ans;

    // print(parent);
    // print(numberAssigned);
    // debug(root);

    // for(ll i=1; i<=n; i++){
    //     vll v = adj[i];
    //     print(v);
    // }

    dfs(root, adj, parent, numberAssigned, ans);

    // cout << "CHECK" << endl;

    if(ans.size() == 0){
        cout << -1 << endl;
        return;
    }
    srt(ans);
    for(auto i: ans){
        cout << i << " ";
    }cout << endl;
}
// Read the question again
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // sieveOfEratosthenes()
    // memset(dp, -1, sizeof(dp));
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