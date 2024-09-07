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

// Function to calculate modular exponentiation
ll mod_exp(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vll v(n);
    rep(i, n) cin >> v[i];
    
    srt(v);
    map<ll, ll> mp2;
    for (ll i = 0; i < n; i++) mp2[v[i]]++;

    set<ll> done;
    ll cnt = 0;

    ll currProd = 1;

    set<ll> t;
    for (ll i = 0; i < n; i++) t.insert(v[i]);
    v.clear();
    for (auto &i : t) v.push_back(i);

    map<ll, ll> mp;

    for (ll i = 0, j = 0; i < t.size(); i++) {
        currProd = (currProd * mp2[v[i]]) % mod7; 
        mp[v[i]] = mp2[v[i]];

        while (j <= i && mp.size() > 0 && (mp.rbegin()->first - mp.begin()->first) >= k) {
            currProd = (currProd * mod_exp(mp2[v[j]], mod7 - 2, mod7)) % mod7;  
            mp[v[j]] = 0;
            if (mp[v[j]] == 0) mp.erase(v[j]);
            j++;
        }

        while (j <= i && mp.size() > k) {
            currProd = (currProd * mod_exp(mp2[v[j]], mod7 - 2, mod7)) % mod7;  
            mp[v[j]] = 0;
            if (mp[v[j]] == 0) mp.erase(v[j]);
            j++;
        }

        if (done.find(v[i]) == done.end() && mp.size() == k) {
            cnt = (cnt + currProd) % mod7;  
            done.insert(v[i]);
        }
    }

    cout << cnt % mod7 << endl; 
}

int main() {
    fast_io
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
