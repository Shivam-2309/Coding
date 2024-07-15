#include <bits/stdc++.h>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    vector<ll> coins(n);
    for (ll i = 0; i < n; i++) cin >> coins[i];

    unordered_set<ll> ans;
    vector<pair<ll, ll>> st1;
    vector<vector<int>> dp(200000, vector<int>(200, 0));

    for (ll i = 0; i < n; i++) {
        ans.insert(coins[i]);
        st1.push_back({coins[i], i});
        dp[coins[i]][i] = 1; 
    }

    ll start = 0;
    while (start < st1.size()) {
        ll initialSize = st1.size();
        for (ll i = start; i < initialSize; i++) {
            ll curr = st1[i].first;
            ll pos = st1[i].second;

            while (pos < n - 1) {
                ll newSum = curr + coins[pos + 1];
                pos++;

                if (dp[newSum][pos] == 0) { // Check if not visited
                    ans.insert(newSum);
                    st1.push_back({newSum, pos});
                    dp[newSum][pos] = 1; // Mark as visited
                }
            }
        }
        start = initialSize;
    }

    vector<ll> res(ans.begin(), ans.end());
    sort(res.begin(), res.end());

    cout << ans.size() << endl;
    for (auto &it : res) cout << it << " ";
    cout << endl;
}

int main() {
    solve();
    return 0;
}
