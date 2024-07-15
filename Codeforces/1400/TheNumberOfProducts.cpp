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

    /*
    // let pos[i] -> is the number of segements such that they end at index i and had product as positve
    // let neg[i] -> is the numbe rof segments such that they end at index i and has product as negative

    // As a result of this
    // if(v[i] < 0){
        pos[i] = neg[i-1];
    }
    else{
        pos[i] = pos[i-1] + 1
    }

    and for neg[i]

    if(v[i] < 0){
        neg[i] = pos[i-1] + 1
    }
    else{
        neg[i] = neg[i-1]
    }
    */

    vll pos(n, 0);
    vll neg(n, 0);

    // base case
    if(v[0] < 0){
        pos[0] = 0;
        neg[0] = 1;
    }
    else{
        pos[0] = 1;
        neg[0] = 0;
    }

    for(ll i=1; i<n; i++){
        if(v[i] < 0){
            pos[i] = neg[i-1];
            neg[i] = pos[i-1] + 1;
        }
        else{
            pos[i] = pos[i-1] + 1;
            neg[i] = neg[i-1];
        }
    }

    ll sumPos = 0;
    ll sumNeg = 0;

    for(ll i=0; i<n; i++) sumPos += pos[i];
    for(ll i=0; i<n; i++) sumNeg += neg[i];

    cout << sumNeg << " " << sumPos << endl;
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