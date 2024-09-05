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
    ll n, q;
    cin >> n >> q;
    vll v(n);
    rep(i, n) cin >> v[i];

    vector<ll> v1 = v;
    for (ll i = 0; i < n; i++) {
        v1.push_back(v[i]);
    }
    vector<ll> pre = v1;
    for (ll i = 1; i < 2 * n; i++) {
        v1[i] += v1[i - 1];
    }
    vector<ll> start;
    ll curr = 0;
    while (curr <= n * n) {
        start.push_back(curr);
        curr += n;
    }
    ll sum = 0;
    for (ll i = 0; i < n; i++) sum += v[i];

    vll a;

    while (q--) {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        ll leftBoundary = lower_bound(start.begin(), start.end(), l) - start.begin();
        ll rightBoundary = upper_bound(start.begin(), start.end(), r) - start.begin();
        ll complete = rightBoundary - leftBoundary - 1;
        ll res = complete * sum;

        if (n == 1) {
            a.push_back((r - l + 1) * v[0]);
            continue;
        }

        if (leftBoundary != 0) {
            ll st = leftBoundary - 1;
            ll val = start[leftBoundary];
            ll rem = val - l;
            ll idx1 = st + n - 1;
            ll idx2 = st + n - 1 - rem;

            ll toAdd = 0;

            // Check idx1
            if (idx1 >= 0 && idx1 < v1.size()) {
                toAdd += v1[idx1];
            }

            // Check idx2
            if (idx2 >= 0 && idx2 < v1.size()) {
                toAdd -= v1[idx2];
            }

            res += toAdd;
        }

        if (rightBoundary != n * n) {
            ll end = rightBoundary - 1;
            ll rem = r - start[end] + 1;
            ll idx1 = end + rem - 1;
            ll idx2 = end - 1;

            ll toAdd = 0;

            // Check idx1
            if (idx1 >= 0 && idx1 < v1.size()) {
                toAdd += v1[idx1];
            }

            // Check idx2
            if (idx2 >= 0 && idx2 < v1.size()) {
                toAdd -= v1[idx2];
            }

            res += toAdd;
        }

        a.push_back(res);
    }

    for (auto it : a) cout << it << endl;
}

int main(){
    fast_io
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
