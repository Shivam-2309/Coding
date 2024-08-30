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

void solve() {
    ll n, m, k, d;
    cin >> n >> m >> k >> d;
    
    vector<vector<ll>> v(n, vll(m));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    
    vll pre(n);
    for (ll i = 0; i < n; i++) {
        vll a = v[i];
        map<ll, ll> dp;
        map<ll, ll> mp;
        
        for (ll j = 0; j < m; j++) a[j]++;
        print(a);
        
        dp[0] = 1;
        mp[1]++;
        
        for (ll j = 1; j <= min(d + 1, m - 1); j++) {
            dp[j] = 1 + a[j];
            mp[1 + a[j]]++;
        }
        for (ll j = d + 2; j < m; j++) {
            ll idx = j - (d + 2);
            ll val = dp[idx];
            mp[val]--;
            if(mp[val] == 0) mp.erase(val);
            dp[j] = a[j] + (mp.begin()->first);
            mp[a[j] + mp.begin()->first]++;
        }

        pre[i] = dp[m - 1];
    }

    for (ll i = 1; i < n; i++) {
        pre[i] += pre[i - 1];
    }

    ll l = 0, r = k - 1;
    ll minCost = LLONG_MAX;

    while (r < n) {
        ll sum = pre[r] - (l > 0 ? pre[l - 1] : 0);
        minCost = min(minCost, sum);
        l++;
        r++;
    }

    cout << minCost << endl;
}

int main(){
    fast_io
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
