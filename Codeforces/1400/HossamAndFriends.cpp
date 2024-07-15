#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll t;
    cin >> t;

    while(t--){
        ll n, m;
        cin >> n >> m;

        vector<pair<ll, ll>> v;
        for(ll i=0; i<m; i++){
            ll a, b;
            cin >> a >> b;

            v.push_back({a, b});
        }

        vector<ll> dp(n+1, n);
        // Here dp[i] means -> the minimum i such that all the elements between the value stored and the i are friends of index i.

        for(ll i=0; i<m; i++){
            ll a = min(v[i].first, v[i].second);
            ll b = max(v[i].first, v[i].second);

            dp[a] = min(dp[a], b-1);
        }

        // Now i want my dp state to change
        // dp[i] means -> the minimum i such that all the elements from the index i to value stored are friends of each other.

        for(ll i=n-1; i>=1; i--){
            dp[i] = min(dp[i], dp[i+1]);
        }

        ll ans = 0;

        for(ll i=1; i<=n; i++){
            ans += (dp[i] - i + 1);
        }

        cout << ans << endl;
    }
    return 0;
}