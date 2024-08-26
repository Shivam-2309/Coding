// Author : Shivam Kapoor
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

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
    int n;
    cin >> n;
    vector<ld> pos(n), time(n);
    rep(i, n) cin >> pos[i];
    rep(i, n) cin >> time[i];

    ld lo = 0;
    ld hi = *max_element(all(time)) + (*max_element(all(pos)) - *min_element(all(pos)));
    ld epsilon = 0.000001; 
    ld ans = 0;

    while (hi - lo >= epsilon) {
        ld mid = (lo + hi) / 2.0;

        ld maxStart = -1e18;
        ld minEnd = 1e18;
        bool f = true;

        for(int i = 0; i < n; i++) {
            ld left = pos[i] - max(0.0L, mid - time[i]);
            ld right = pos[i] + max(0.0L, mid - time[i]);

            maxStart = max(maxStart, left);
            minEnd = min(minEnd, right);

            if(maxStart > minEnd) {
                f = false;
                break;
            }
        }

        if(f) {
            ans = maxStart;
            hi = mid;
        } else {
            lo = mid;
        }
    }

    cout << fixed << setprecision(6) << ans << endl;
}



int main(){
    fast_io
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
