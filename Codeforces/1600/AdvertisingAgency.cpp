#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

#ifndef ONLINE_JUDGE
#define debug(x) cout << "errr----  " << #x << " " << x << endl
#define print(v) do { \
                    cout << "vect--" << #v << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << v[i] << " "; \
                    } \
                    cout << " ]" << endl; \
                } while (0)
#else
#define debug(x)
#define print(v)
#endif

#define vll vector<ll>
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end())
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < n; i++)

const ll mod7 = 1e9 + 7;
const ll MAX = 1000000;

vector<ll> fact(MAX + 1), inv_fact(MAX + 1);

ll mod_pow(ll a, ll b, ll mod) {
    ll result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        b /= 2;
    }
    return result;
}

void precompute_factorials() {
    fact[0] = fact[1] = 1;
    for (ll i = 2; i <= MAX; i++) {
        fact[i] = fact[i - 1] * i % mod7;
    }
    inv_fact[MAX] = mod_pow(fact[MAX], mod7 - 2, mod7);
    for (ll i = MAX - 1; i >= 0; i--) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % mod7;
    }
}

ll mod_nCr(ll n, ll r) {
    if (r > n) return 0;
    return fact[n] * inv_fact[r] % mod7 * inv_fact[n - r] % mod7;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vll v(n);
    rep(i, n) cin >> v[i];

    srt(v);
    // print(v);

    ll e = n - 1;
    ll k_copy = k;
    ll sum = 0;

    while (k_copy--) {
        sum = (sum + v[e]) % mod7; // Applying mod7 to sum
        e--;
    }
    e++;
    ll last_val = v[e];

    // debug(e);
    // debug(last_val);

    ll times = 0;
    for (ll i = 0; i < n; i++) {
        if (v[i] == last_val) times++;
    }

    ll tot = 0;
    for (ll i = e; i < n; i++) {
        if (v[i] == last_val) tot++;
    }

    // debug(times);
    // debug(tot);

    cout << mod_nCr(times, tot) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    precompute_factorials(); // Precompute factorials

    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
