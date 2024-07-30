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
                    cout << "]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#endif

#define vll vector<ll>
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end());
#define rep(i, n) for (ll i = 0; i < n; i++)
const ll mod7 = 1e9 + 7;

bool isValid(ll mid, vector<ll> v, vector<ll> &q, vector<pair<ll, ll>> &intervals) {
    for (ll i = 0; i < mid; i++) {
        v[q[i] - 1] = 1;
    }

    vector<ll> pre(v.size(), 0);
    pre[0] = v[0];
    for (ll i = 1; i < v.size(); i++) {
        pre[i] = pre[i - 1] + v[i];
    }

    for (ll i = 0; i < intervals.size(); i++) {
        ll l = intervals[i].first - 1;
        ll r = intervals[i].second - 1;

        ll sum = pre[r] - (l > 0 ? pre[l - 1] : 0);
        if (sum > 0) return true;
    }

    return false;
}

void solve() {
    ll n, m; cin >> n >> m;
    vector<pair<ll, ll>> ivl;
    for (ll i = 0; i < m; i++) {
        ll a, b; cin >> a >> b;
        ivl.push_back(make_pair(a, b));
    }

    vector<ll> a(n, -1);

    ll q;
    cin >> q;
    vll queries(q);
    for (ll i = 0; i < q; i++) {
        cin >> queries[i];
    }

    ll lo = 1;
    ll hi = q;
    ll ans = -1;

    // O(logM*(N + M + M))
    // O(logM*(N + M))

    while (lo <= hi) {
        ll mid = ((lo + hi) >> 1);
        if (isValid(mid, a, queries, ivl)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << endl;
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
