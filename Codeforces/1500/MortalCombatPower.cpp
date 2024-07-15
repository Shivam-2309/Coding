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

ll f(ll i, ll turn, vll &v, vector<vector<ll>> &dp){
    if(i == v.size()) return 0;

    if(dp[i][turn] != -1) return dp[i][turn];

    ll ans = 1e18;
    if(turn == 0){
        if(i+1<v.size()){
            ll toAdd = 0;
            if(v[i] == 1) toAdd++;
            if(v[i+1] == 1) toAdd++;
            ans = min(ans, toAdd + f(i+2, !turn, v, dp));
        }
        ll toAdd = 0;
        if(v[i] == 1) toAdd++;
        ans = min(ans, toAdd + f(i+1, !turn, v, dp));
    }
    else {
        if(i+1 < v.size()){
            ans = min(ans, f(i+2, !turn, v, dp));
        }
        ans = min(ans, f(i+1, !turn, v, dp));
    }
    return dp[i][turn] = ans;
}

void solve(){
    ll n; cin >> n;

    vll v(n);
    rep(i, n) cin >> v[i];

    // dp[i][turn] -> minimum number of skip points from index i =0 to index i = i-1 such that the current baari is of turn
    vector<vector<ll>> dp(n+1, vector<ll> (2, -1));
    cout << f(0, 0, v, dp) << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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