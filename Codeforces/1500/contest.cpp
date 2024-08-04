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
#define srt(v) sort(v.begin(), v.end())
#define rep(i, n) for (ll i = 0; i < n; i++)
const ll mod7 = 1e9 + 7;

ll f(ll i, ll curr, map<ll, vll> &mp, ll n, vll &v, vector<vector<ll>> &dp) {
    if (i == n) return 0;
    if (dp[i][curr] != -1) return dp[i][curr];

    // curr -> defined ki curr i wala element mn le chuka hu ya nhi

    ll ans1 = curr + f(i + 1, 1, mp, n, v, dp);
    vll &a = mp[v[i]];
    ll idx = upper_bound(a.begin(), a.end(), i) - a.begin();
    if(idx < a.size()) ans1 = min(ans1, f(a[idx], 0,  mp, n, v, dp));

    return dp[i][curr] = ans1;
}

void solve() {
    ll n; 
    cin >> n;
    vll v(n);
    rep(i, n) cin >> v[i];
    
    map<ll, vll> mp;
    for (ll i = 0; i < n; i++) {
        mp[v[i]].push_back(i);
    }

    vector<vector<ll>> dp(n, vector<ll> (2, -1));
    ll curr = 1;
    cout << n - f(0, curr, mp, n, v, dp) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
