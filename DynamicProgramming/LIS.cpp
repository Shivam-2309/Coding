#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll f(ll idx, ll prev_idx, vector<ll> &arr){
    if(idx == arr.size()){
        return 0;
    }

    // not take
    ll notTake = f(idx+1, prev_idx, arr);

    // take
    ll take = 0;
    if(prev_idx == -1 || arr[idx] > arr[prev_idx]){
        take = 1 + f(idx+1, idx, arr);
    }

    return max(take, notTake);
}

int main(){
    ll n; cin >> n;
    
    vector<ll> arr(n);

    for(ll i=0; i<n; i++) cin >> arr[i];

    // definition of the DP state
    // f(i, prev) -> gives us the length of the longest prefix from index i and the last index considered till now is prev_idx

    // cout << f(0, -1, arr) << endl;

    
    // for the dp state -> dp[i]
    // length of the longest increasing subsequence that can be made from index = 0 to index = i
    // vector<ll> dp(n, 1);

    // for(ll i = 0; i < n; i++){
    //     for(ll prev_idx = 0; prev_idx < i; prev_idx++){
    //         if(arr[i] > arr[prev_idx] && 1 + dp[prev_idx] > dp[i]){
    //             dp[i] = 1 + dp[prev_idx];
    //         }
    //     }
    // }

    // nlogn solution

    vector<ll> ans;
    ans.push_back(arr[0]);

    for(ll i = 1; i < n; i++){
        if(arr[i] > ans.back()){
            ans.push_back(arr[i]);
        }
        else{
            ll idx = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
            ans[idx] = arr[i];
        }
    }

    cout << ans.size() << endl;

    return 0;
}