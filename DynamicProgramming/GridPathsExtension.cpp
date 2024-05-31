#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

    // This is a simple extension of the grid Paths where I am being to told to get all the paths which go through
    // A particular point or i say a checkpoint -> (Here I have taken only the single checkpoint).

    ll n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n, 0));

    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            char ch; cin >> ch;
            grid[i][j] = ch;
        }
    }

    ll sureRow, sureCol;
    cin >> sureRow >> sureCol;

    // Here we use two dp states
    // DP STATE 1
    // dp[i][j] -> Number of ways to go from {0, 0} to {i, j}
    // Transition State -> dp[i][j] = dp[i-1][j] + dp[i][j-1]
    // because we would get grid corresponding to the {0, 0} to {i, j}

    // DP STATE 2
    // dp[i][j] -> Number of ways to go from {i, j} to {n-1, n-1}
    // Transition State -> dp[i][j] = dp[i+1][j] + d[i][j+1]
    // because we would get grid corresponding to the {i, j} to {n-1, n-1}

    // The number of ways would be the multiplication of both

    vector<vector<ll>> dp1(n+1, vector<ll> (n+1, 0));
    dp1[0][0] = 1;

    for(ll i = 0; i < n;  i++){
        for(ll j = 0; j<n; j++){
            if(i == 0 && j == 0) continue;

            if(grid[i][j] == '*'){
                dp1[i][j] = 0;
            }
            else{
                if(i >= 1) dp1[i][j] += dp1[i-1][j];
                if(j >= 1) dp1[i][j] += dp1[i][j-1];
            }
        }
    }

    vector<vector<ll>> dp2(n+1, vector<ll> (n+1, 0));
    dp2[n-1][n-1] = 1;

    for(ll i = n-1; i >= 0; i--){
        for(ll j = n-1; j >= 0; j--){
            if(i == n-1 && j == n-1) continue;

            if(grid[i][j] == '*'){
                dp2[i][j] = 0;
            }
            else{
                if(i+1 < n) dp2[i][j] += dp2[i+1][j];
                if(j+1 < n) dp2[i][j] += dp2[i][j+1];
            }
        }
    }

    // Printing both the 2D DP vectors 

    // for(ll i=0; i<n; i++){
    //     for(ll j=0; j<n; j++){
    //         cout << dp1[i][j] << " ";
    //     }cout << endl;
    // }cout << endl;

    // for(ll i=0; i<n; i++){
    //     for(ll j=0; j<n; j++){
    //         cout << dp2[i][j] << " ";
    //     }cout << endl;
    // }cout << endl;
    // Now for the number of ways to go from {0, 0} to {n-1, n-1} by surely going through the checkpoint of {surePoint, surePoint} is ->

    ll ans = dp1[sureRow][sureCol] * dp2[sureRow][sureCol];

    cout << ans << endl;
    return 0;
}