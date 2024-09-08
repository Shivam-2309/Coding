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
    ll n; cin >> n;
    vll v(n + 1);
    for(ll i = 1; i <= n; i++) cin >> v[i];

    vector<ll> dp(n + 1, false);
    dp[0] = true;
    // dp[i] -> is it possible to make the sequence for the length of the prefix i following the given constraints
    for(ll i = 1; i <= n; i++){
        if(dp[i - 1] == true && i + v[i] <= n) dp[i + v[i]] = true;
        if(i - v[i] - 1 >= 0 && dp[i - v[i] - 1]) dp[i] = true;
    }

    if(dp[n]) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
    fast_io
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
