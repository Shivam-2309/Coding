#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>

using namespace std;

using ll = long long;
using vll = vector<ll>;
#define rep(i, n) for(ll i = 0; i < (n); ++i)

map<tuple<ll, ll, ll, ll>, ll> memo; 

ll f(ll idx, vector<ll> &a, vector<ll> &b, ll scoreA, ll scoreB){
    if(idx == a.size()){
        return min(scoreA, scoreB);
    }

    tuple<ll, ll, ll, ll> state = make_tuple(idx, scoreA, scoreB, memo.size());
    if(memo.find(state) != memo.end()){
        return memo[state];
    }

    ll r1 = a[idx];
    ll r2 = b[idx];

    ll res;
    if(scoreA > scoreB){
        if(r2 > 0) res = f(idx+1, a, b, scoreA, scoreB+1); 
        else res = f(idx+1, a, b, scoreA+r1, scoreB); 
    }
    else if(scoreB > scoreA){
        if(r1 > 0) res = f(idx+1, a, b, scoreA+1, scoreB); 
        else res = f(idx+1, a, b, scoreA, scoreB+r2); 
    }
    else{
        if(r1 < 0 && r2 > 0) res = f(idx+1, a, b, scoreA, scoreB+1); 
        else if(r1 > 0 && r2 < 0) res = f(idx+1, a, b, scoreA+1, scoreB); 
        else{
            res = max(f(idx+1, a, b, scoreA, scoreB+r2), f(idx+1, a, b, scoreA+r1, scoreB));
        }
    }

    memo[state] = res;
    return res;
}

void solve(){
    ll n; cin >> n;

    vll a(n);
    rep(i, n) cin >> a[i];
    vll b(n);
    rep(i, n) cin >> b[i];

    memo.clear(); // Clear memoization map before solving the new case
    ll ans = LLONG_MIN;
    ll scoreA = 0;
    ll scoreB = 0;

    ans = f(0, a, b, scoreA, scoreB);

    cout << ans << endl;
}

int main(){
    ll t; cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
