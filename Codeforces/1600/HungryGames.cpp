// Author : Shivam Kapoor
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x) cerr << #x << " = " << x << endl
#define print(v) cerr << #v << " = [ "; for (auto &el : v) cerr << el << " "; cerr << "]\n";
#define print2d(v) cerr << #v << ":\n"; for (auto &row : v) { cerr << "[ "; for (auto &el : row) cerr << el << " "; cerr << "]\n"; }
#define printmap(m) cerr << #m << ":\n"; for (auto &[key, value] : m) cerr << key << " -> " << value << "\n";
#define printpp(v) cerr << #v << " = [ "; for (auto &[first, second] : v) cerr << "(" << first << ", " << second << ") "; cerr << "]\n";

#define vll vector<ll>
#define rev(v) reverse(all(v))
#define srt(v) sort(all(v))
#define all(v) (v).begin(), (v).end()
#define rep(i, n) for (ll i = 0; i < (n); ++i)

const ll mod7 = 1e9 + 7;

void solve(){
    ll n, x; cin >> n >> x;
    vll v(n);
    rep(i, n) cin >> v[i];
    vll p = v;
    ll cnt = 0;
    for(ll i = 1; i < n; i++) p[i] += p[i - 1];
    vector<ll> dp(n, 0);
    // print(p);
    
    for(ll i = n - 1; i >= 0; i--){
        ll left = (i > 0 ? p[i - 1] + x : x);
        ll idx = upper_bound(p.begin(), p.end(), left) - p.begin();
        // debug(i);
        // debug(idx);
        dp[i] += max(0ll, idx - i);
        if(idx + 1 < n) dp[i] += dp[idx + 1];
        // debug(dp[i]);
        // cout << "NEXT" << endl;
    }

    rep(i, n) cnt += dp[i];
    cout << cnt << endl;
}

int main(){
    fast_io
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
