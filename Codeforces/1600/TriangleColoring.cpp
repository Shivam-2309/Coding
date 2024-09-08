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
const ll MOD = 998244353;

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll modInverse(ll a, ll mod) {
    ll m0 = mod, y = 0, x = 1;
    if (mod == 1) return 0;
    while (a > 1) {
        ll q = a / mod;
        ll t = mod;
        mod = a % mod, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0) x += m0;
    return x;
}

ll nCr_mod(ll n, ll r) {
    ll p = 1, k = 1;
    if (n - r < r) r = n - r;
    if (r != 0) {
        while (r) {
            p = (p * n) % MOD;
            k = (k * r) % MOD;
            ll m = gcd(p, k);
            p /= m;
            k /= m;
            n--;
            r--;
        }
        p = (p * modInverse(k, MOD)) % MOD;
    } else {
        p = 1;
    }
    return p % MOD;
}


void solve(){
    ll n; cin >> n;
    vll v(n);
    rep(i, n) cin >> v[i];

    ll ans = 1;

    for(ll i = 0; i < n; i += 3){
        vll a;
        a.push_back(v[i]);
        a.push_back(v[i + 1]);
        a.push_back(v[i + 2]);

        srt(a);
        ll times = 1;
        if(a[0] != a[1] && a[1] != a[2] && a[2] != a[0]){
            times = 1;
        }
        else if(a[0] != a[1] && a[1] == a[2]){
            times = 1;
        }
        else if(a[0] == a[1] && a[1] != a[2]){
            times = 2;
        }
        else times = 3;

        ans = (ans * times) % MOD;
    }

    ll v1 = n/3;
    ll v2 = n/6;

    ll v3 = nCr_mod(v1, v2);
    ans = (ans * v3) % MOD;

    cout << ans << endl;
}

int main(){
    fast_io
    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
