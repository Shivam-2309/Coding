/*      Jai Shree Ram      */
/*      Code Snippet of Shivam Kapoor      */
#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin >> n;
    string v;
    cin >> v;

    vector<ll> zeros(n, 0);
    vector<ll> ones(n, 0);

    for(ll i=0; i<n; i++){
        if(v[i] == '0') zeros[i] = 1 + (i>0? zeros[i-1]: 0);
        else zeros[i] = i>0? zeros[i-1]:0;
    }

    for(ll i=n-1; i>=0; i--){
        if(v[i] == '1') ones[i] = 1 + (i<n-1? ones[i+1]: 0);
        else ones[i] = 0 + (i<n-1? ones[i+1]: 0);
    }

    vector<ll> res;

    for(ll i=0; i<n-1; i++){
        if((zeros[i] >= ceil((i+1)/(double)2)) && (ones[i+1] >= ceil((n-i-1)/(double)2))){
            res.push_back(i+1);
        }
    }

    if(ones[0] >= ceil(n/(double)2)){
        res.insert(res.begin(), 0);
    }
    if(zeros[n-1] >= ceil(n/(double)2)){
        res.push_back(n);
    }

    // for(ll i=0; i<res.size(); i++){
    //     cout << res[i] << " ";
    // }cout << endl;

    double mid = n/(double)2;
    // cout << mid << endl;
    ll idx = 0;
    ll ans = INT_MAX;

    for(ll i=0; i<res.size(); i++){
        if(abs(res[i] - mid) < ans){
            idx = res[i];
            ans = abs(res[i] - mid);
        }
    }
    
    cout << idx << endl;
}
// clear all data structures between test cases
// handle all corner cases
// confusing between n and m , i and j?
// uninitialized variables?
// Read the question again
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // sieveOfEratosthenes()
    // memset(dp, -1, sizeof(dp));
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*     The code finishes, I hope it gets Accepted      */