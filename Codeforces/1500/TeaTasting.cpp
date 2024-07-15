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

#define NUM 2000000

// Think about Node Structure
// Thing about Merge Logic
// Think about Leaf Value
 
struct node {
    ll sum = 0;
    node(){
        sum = 0;
    }
};
 
node merge(node a, node b){
    node ans;
    ans.sum = a.sum + b.sum;
    return ans;
}
 
node t[4*NUM];
 
void build(ll id, ll l, ll r){
    if(l == r){
        // leaf node
        t[id].sum = 0;
        return;
    }
 
    ll mid = (l+r)/2;
 
    // node array is one based indexing
    build(2*id, l, mid);
    build(2*id+1, mid+1, r);
 
    t[id] = merge(t[2*id], t[2*id+1]);
}
 
void update(ll id, ll l, ll r, ll pos, ll val){
    if(pos < l || pos > r) return;
    if(l == r){
        t[id].sum += val;
        return;
    }
 
    ll mid = (l+r)/2;
    update(2*id, l, mid, pos, val);
    update(2*id+1, mid+1, r, pos, val);
 
    t[id] = merge(t[2*id], t[2*id + 1]);
}
 
node query(ll id, ll l, ll r, ll leftQ, ll rightQ){
    if((leftQ>r) || (l>rightQ)){
        return node();
    }
    if((leftQ<=l) && (r<=rightQ)){
        return t[id];
    }
    ll mid = (l+r)/2;
    return merge(query(2*id, l, mid, leftQ, rightQ), query(2*id+1, mid+1, r, leftQ, rightQ));
}

void solve(){
    ll n; cin >> n;

    vll a(n);
    rep(i, n) cin >> a[i];
    vll b(n);
    rep(i, n) cin >> b[i];

    vll pre(n);
    pre[0] = b[0];

    for(ll i=1; i<n; i++){
        pre[i] = pre[i-1] + b[i];
    }

    // print(pre);
    vll temp2(n, 0);

    build(1, 0, n-1);
    ll s = 0;

    for(ll i=0; i<n; i++){
        // cout << "CHECK" << endl;
        ll num = a[i];
        ll idx = lower_bound(pre.begin(), pre.end(), s + num) - pre.begin();

        if(idx == n){
            // cout << "HERE" << endl;
            update(1, 0, n-1, i, 1);
            update(1, 0, n-1, idx, -1);
            s += b[i];
            continue;
        }

        if(s + num < pre[idx]){
            ll have = s + num - (idx > 0 ? pre[idx-1] : 0);
            temp2[idx] += (have);
            idx--;
        }

        // debug(idx);

        update(1, 0, n-1, i, 1);
        update(1, 0, n-1, idx+1, -1);

        s += b[i];
    }

    // print(temp2);

    vll ans;
    for(ll i=0; i<n; i++){
        node v = query(1, 0, n-1, 0, i);
        ans.push_back(temp2[i] + (v.sum * b[i]));
    }

    for(auto &i : ans){
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
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*     The code finishes, I hope it gets Accepted      */