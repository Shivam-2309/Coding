#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#define print(v) do { \
                    cout << "vect--" << #v << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << v[i] << " "; \
                    } \
                    cout << "]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#endif
#define vll vector<ll>
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end());
#define rep(i, n) for (ll i = 0; i < n; i++)
const ll mod7 = 1e9 + 7;

bool isValid(ll x, vll &v, ll k){
    ll n = v.size();
    debug(x);
    for(ll pos = 0; pos < n-1; pos++){
        ll req = 0;
        ll currReq = x;
        for(ll j = pos; j < n; j++){
            req += max(0ll, currReq - v[j]);
            debug(req);
            currReq--;
        }
        debug(pos);
        debug(req);
        cout << "BREAK" << endl;
        if(req <= k) return true; 
    }
    return false;
}

void solve(){
    ll n, k; cin >> n >> k;
    vll v(n);
    rep(i, n) cin >> v[i];

    ll lo = 0;
    ll hi = *max_element(v.begin(), v.end()) + k;
    ll ans = 0;
    while(lo <= hi){
        ll mid = (lo + hi) / 2;

        if(isValid(mid, v, k)){
            ans = mid;
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }

    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.precision(15);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}