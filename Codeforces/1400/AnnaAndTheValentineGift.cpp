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
pair<ll, ll> findDigitsZeros(ll num){
    ll numZeros = 0;
    ll t = num;
    while(t!=0 && t%10==0){
        numZeros++;
        t /= 10;
    }
    ll numDigits = 0;
    while(num){
        num /= 10;
        numDigits++;
    }

    return {numDigits, numZeros};
}

void solve(){
    ll n, m;
    cin >> n >> m;

    vll v(n);
    rep(i, n) cin >> v[i];

    vector<pair<ll, ll>> a;

    for(ll i=0; i<n; i++){
        ll num = v[i];
        pair<ll, ll> p = findDigitsZeros(num);
        a.push_back(p);
    }
    ll ans = 0;
    for(ll i=0; i<n; i++){
        ans += a[i].first;
    }

    vll t;
    for(ll i=0; i<n; i++){
        t.push_back(a[i].second);
    }

    sort(t.begin(), t.end());
    reverse(t.begin(), t.end());

    for(ll i=0; i<t.size(); i+=2){
        ans -= t[i];
    }   

    if(ans > m){
        cout << "Sasha" << endl;
    }
    else{
        cout << "Anna" << endl;
    }
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