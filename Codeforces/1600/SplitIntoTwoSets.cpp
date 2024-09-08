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
    vector<pair<ll, ll>> a;
    ll cnt = 0;
    map<ll, ll> mp;
    for(ll i = 0; i < n; i++){
        ll u, v; cin >> u >> v;
        a.push_back({u, v});
        mp[u]++;
        mp[v]++;
        cnt++;
    }

    for(ll i = 1; i <= n; i++){
        if(mp[i] != 2){
            cout << "NO" << endl;
            return;
        }
    }

    set<ll> st1;
    for(ll i = 0; i < a.size(); i++){
        ll u = a[i].first;
        ll v = a[i].second;

        if(u == v){
            cout << "NO" << endl;
            return;
        }

        if(st1.find(u) == st1.end() && st1.find(v) == st1.end()){
            st1.insert(u);
            st1.insert(v);
        }
    }

    for(ll i = 1; i <= n; i++){
        if(st1.find(i) == st1.end())
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int main(){
    fast_io
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
