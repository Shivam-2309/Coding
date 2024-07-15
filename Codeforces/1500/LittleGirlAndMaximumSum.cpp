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
#define NUM 2000000
// #define ll long long

// Think about Node Structure
// Thing about Merge Logic
// Think about Leaf Value

struct node {
    ll val = 0;
    node(){
        val = 0;
    }
};

node merge(node a, node b){
    node ans;
    ans.val = a.val + b.val;
    return ans;
}

node t[4*NUM];

void build(ll id, ll l, ll r, vector<ll> &nums){
    if(l == r){
        // leaf node
        t[id].val = nums[l];
        return;
    }

    ll mid = (l+r)/2;

    // node array is one based indexing
    build(2*id, l, mid, nums);
    build(2*id+1, mid+1, r, nums);

    t[id] = merge(t[2*id], t[2*id+1]);
}

void update(ll id, ll l, ll r, ll pos, ll val){
    if(pos < l || pos > r) return;
    if(l == r){
        t[id].val = val;
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

// ll dp[100001];
void solve(){
    ll n, q; cin >> n >> q;

    vll v(n);
    rep(i, n) cin >> v[i];

    // build(1, 0, n-1);

    // for(ll i=1; i<=n; i++){
    //     cout << t[i].sum << " ";
    // }cout << endl;

    vll store(n+1, 0);

    vector<pair<ll, ll>> temp;

    while(q--){
        ll l, r;
        cin >> l >> r;

        l--;
        r--;

        temp.push_back({l, r});

        store[l] += 1;
        store[r+1] -= 1;
    }

    for(ll i=1; i<n; i++){
        store[i] = store[i] + store[i-1];
    }

    // for(ll i = 0; i < n; i++){
    //     cout << store[i] << " ";
    // }cout << endl;

    vector<pair<ll, ll>> a;

    for(ll i=0; i<n; i++){
        a.push_back({store[i], i});
    }

    sort(a.begin(), a.end());

    vll final(n);

    vll t = v;
    srt(t);

    for(ll i=0; i<n; i++){
        ll idx = a[i].second;
        final[idx] = t[i];
    }

    // print(final);

    ll result = 0;

    build(1, 0, n-1, final);

    for(ll i = 0; i<temp.size(); i++){
        ll l = temp[i].first;
        ll r = temp[i].second;

        node ans = query(1, 0, n-1, l, r);

        result += ans.val;
    }
    
    cout << result << endl;
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