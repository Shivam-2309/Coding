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
const ll mod9 = 998244353;

ll dp[21][1 << 20];

ll f(ll i, ll mask, vector<vector<ll>> &grid){
    // Base case
    if(i == grid.size()) return 0;
    // Check for overlapping subproblems
    if(dp[i][mask] != -1) return dp[i][mask];
    ll ans = LLONG_MAX;
    for(ll j = 0; j < grid.size(); j++){
        if(mask & (1 << j)){
            // If the jth bit is set, this bit has not yet been taken in the mask
            ans = min(ans, grid[i][j] + f(i + 1, (mask ^ (1 << j)), grid));
        }
    }
    return dp[i][mask] = ans;
}

void solve(){
    ll n; cin >> n;
    vector<vector<ll>> grid(n, vector<ll> (n));
    for (ll i = 0; i < 21; i++) {
        for (ll j = 0; j < (1 << n); j++) {
            dp[i][j] = -1;
        }
    }
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    cout << f(0, ((1 << n) - 1), grid);
}

int main(){
    fast_io
    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
