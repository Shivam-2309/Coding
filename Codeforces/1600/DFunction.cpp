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

ll binpowmod(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

ll modInverse(ll a, ll mod) {
    return binpowmod(a, mod - 2, mod);  
}

void solve() {
    ll l, r, k;
    cin >> l >> r >> k;

    if (k > 9) {
        cout << 0 << endl;
        return;
    }
    
    ll t = 9 / k;
    l++;
    ll left = max(1LL, l);
    ll right = r;
    
    ll ans = t;
    // debug(ans);
    ll total_power = (right - left + 1);
    ll ans_geom_sum = (binpowmod(t + 1, total_power, mod7) - 1 + mod7) % mod7;
    ll inv_t_plus_1 = modInverse(t, mod7); 
    ans_geom_sum = (ans_geom_sum * inv_t_plus_1) % mod7;
    ll prefix_multiplier = binpowmod(t + 1, left - 1, mod7);
    ans = (ans * ((prefix_multiplier * ans_geom_sum) % mod7)) % mod7;

    cout << ans << endl;
}


int main(){
    fast_io
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
