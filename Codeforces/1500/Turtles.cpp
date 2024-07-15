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
void solve(){
    ll n; cin >> n;

    vll v(n);
    rep(i, n) cin >> v[i];


    vll pre(n);
    pre[0] = v[0];

    for(ll i=1; i<n; i++){
        pre[i] = v[i] + pre[i-1];
    }

    // print(pre);

    ll q; cin >> q;

    vll ans;

    // 3 4 8 9 14 23

    while(q--){
        ll l, u; 
        cin >> l >> u;

        l--;
        ll temp = u;
        ll sum = (l >= 1 ? pre[l-1] : 0);
        // debug(sum);
        u += sum;
        // debug(u);

        ll idx = lower_bound(pre.begin(), pre.end(), u) - pre.begin();
        
        if(idx == n){
            ans.push_back(n);
            continue;
        }

        if(idx == l){
            ans.push_back(l+1);
            continue;
        }

        // 2 possibilty

        ll idx1 = idx;
        ll idx2 = idx-1;

        ll tot1 = pre[idx1] - (l >= 1 ? pre[l-1] : 0);
        ll poss1 = (tot1 * temp);
        poss1 -= (tot1 * (tot1 - 1))/2;

        ll tot2 = pre[idx2] - (l >= 1 ? pre[l-1] : 0);
        ll poss2 = (tot2 * temp);
        poss2 -= (tot2 * (tot2 - 1))/2;

         if(poss2 >= poss1){
            ans.push_back(idx2 + 1);
        }
        else{
            ans.push_back(idx1 + 1);
        }

    }

    for(auto i : ans){
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