#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll n, x;
    cin >> n >> x;

    vector<ll> wt(n);
    for(ll i=0; i<n; i++) cin >> wt[i];

    vector<ll> val(n);
    for(ll i=0; i<n; i++) cin >> val[i];

    // DP State
    // dp[i] -> This defines the maximum amount of sum which we make from the prefix of [0 --> i]
    // DP Transition
    // dp[i][j] = max(val[i] + dp[i-1][j-wt[i]], dp[i-1][j])

    // vector<vector<ll>> dp(n+1, vector<ll> (x+1, 0));
    // TC -> No. of transtion States * Average Transition time
    // TC -> O(N * X)
    vector<ll> prev(x+1, 0);
    for(ll i = 1; i <= n; i++){
        vector<ll> curr(x+1, 0);
        for(ll j = 0; j <= x; j++){
            ll w = wt[i-1];
            ll value = val[i-1];

            ll pick = 0;
            if(j >= w) pick = prev[j-w] + value;
            ll notPick = prev[j];

            curr[j] = max(pick, notPick);
        }
        prev = curr;
    }

    cout << prev[x] << endl;

    return 0;
}