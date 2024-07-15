#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007

int main(){
    ll n, k;
    cin >> n >> k;

    vector<ll> v(n);
    for(ll i = 0; i < n; i++) cin >> v[i];

    /*
        dp[i][j] -> number of prefixes of lenth 1 such that their last element is j
    */

    vector<vector<ll>> dp(n+1, vector<ll> (k+1, 0));

    // Either the value of the last element is equal to k and we want also k
    // or the value of the last element is 0 (I can put k) so base case comes as ->
    
    for(ll j = 1; j <= k; j++){
        if(v[0] == 0 || v[0] == j){
            dp[1][j] = 1;
        }
    }

    // Now Space Optimising it ->
    vector<ll> prev(k+1, 0);
    for(ll j = 1; j <= k; j++){
        if(v[0] == 0 || v[0] == j) prev[j] = 1;
    }

    // Now comes the transition state
    // dp[i][k] can come from a cumulative sum of dp[i-1][k+1], dp[i-1][k], dp[i-1][k-1]

    for(ll i = 2; i <= n; i++){
        vector<ll> curr(k+1, 0);
        for(ll j = 1; j <= k; j++){
            
            if(v[i-1] != 0 && v[i-1] != j){
                continue;
            }

            curr[j] = (curr[j] + prev[j])%MOD;
            if(j >= 1) curr[j] = (curr[j] + prev[j-1])%MOD;
            if(j+1 <= k) curr[j] = (curr[j] + prev[j+1])%MOD;
        }
        prev = curr;
    }

    // Final answer would be -> The cumulative sum of ->
    // All the dp[N][i's] -> As i want all the segments which ar eof length N and end at any of the i

    ll sum = 0;
    for(ll j = 1; j <= k; j++){
        sum = (sum + prev[j])%MOD;
    }

    cout << sum << endl;

    return 0;
}