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
#define vll vector<ll>
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end());
#define rep(i, n) for (ll i = 0; i < n; i++)
const ll mod7 = 1e9 + 7;

ll f(ll n, ll k, ll dir, vector<vector<vector<ll>>> &dp){
    if(n == 0) return 0;
    if(n == dp.size()) return 0;
    if(k == 1) return 1;

    if(dp[n][k][dir] != -1) return dp[n][k][dir];
    ll ans = 2;
    ans = (ans + f(n-1, k-1, !dir, dp))%mod7;
    ans = (ans + f(n+1, k, dir, dp))%mod7;

    return dp[n][k][dir] = ans;
}

void solve(){
    ll n, k; cin >> n >> k;
    vector<vector<vector<ll>>> dp(1000, vector<vector<ll>> (1000, vector<ll> (2, -1)));
    cout << f(n, k, 0, dp) << endl;
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