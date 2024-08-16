#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define srt(v) sort(v.begin(), v.end())
#define rev(v) reverse(v.begin(), v.end())

void solve() {
    ll rows, cols, k;
    cin >> rows >> cols >> k;

    ll n; cin >> n;
    vll a(n);
    rep(i, n) cin >> a[i];

    vector<vector<ll>> grid(rows, vector<ll>(cols, 0));

    for(ll i = 0; i < rows; i++){
        for(ll j = 0; j < cols; j++){
            ll r_count = 0;
            ll c_count = 0;

            ll left_bound = j - k + 1;
            ll right_bound = j + k - 1;

            left_bound = max(left_bound, 0ll);
            right_bound = min(cols - 1, right_bound);
            ll space_between = right_bound - left_bound + 1;
            c_count = space_between - k + 1;

            ll left_b = i - k + 1;
            ll right_b = i + k - 1;

            left_b = max(left_b, 0ll);
            right_b = min(rows - 1, right_b);
            space_between = right_b - left_b + 1;
            r_count = space_between - k + 1;


            grid[i][j] = (c_count * r_count);
        }
    }

    // for(ll i = 0; i < rows; i++){
    //     for(ll j = 0; j < cols; j++){
    //         cout << grid[i][j] << " ";
    //     }cout << endl;
    // }

    vector<ll> v;
    ll ans = 0;
    for(ll i = 0; i < rows; i++){
        for(ll j = 0; j < cols; j++){
            v.push_back(grid[i][j]);
        }
    }

    sort(v.rbegin(), v.rend());
    sort(a.rbegin(), a.rend());

    for(int i = 0; i < a.size(); i++){
        ans += (a[i] * v[i]);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.precision(15);
    ll t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
