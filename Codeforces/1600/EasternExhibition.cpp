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
    vector<pair<ll, ll>> v;
    for(ll i = 0; i < n; i++){
        ll u, b; cin >> u >> b;
        v.push_back({u, b});
    }

    // set<pair<int, int>> st(all(v));
    if(v.size() % 2 == 1) {
        cout << 1 << endl;
        return;
    }
    // v.clear();
    // for(auto it : st) v.push_back(it);

    vll X;
    vll Y;
    for(ll i = 0; i < n; i++){
        X.push_back(v[i].first);
        Y.push_back(v[i].second);
    }
    n = v.size();
    srt(X);
    srt(Y);

    ll a = (X[n/2] - X[n/2 - 1] + 1);
    ll b = (Y[n/2] - Y[n/2 - 1] + 1);

    cout << a * b << endl;
}

int main(){
    fast_io
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
