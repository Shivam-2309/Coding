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
void solve(){
    ll n, k; cin >> n >> k;
    vll v(n);
    rep(i, n) cin >> v[i];

    ll maxi = *max_element(v.begin(), v.end());
    ll ans = maxi;
    for(ll i = 0; i < n; i++){
        if(v[i] == maxi) continue;
        ll left = maxi - v[i];
        ll times = left / k;
        ll val = v[i] + (times * k);
        if(val == maxi){
            if(times%2 == 1) {
                cout << -1 << endl;
                return;
            }
        }
        else if(val < maxi){
            times++;
            val += k;
            if(times % 2 == 0) ans = max(ans, val);
        }
    }

    for(ll i = 0; i < n; i++){
        ll left = ans - v[i];
        ll temp = left / k;
        if(temp % 2 == 1){
            cout << -1 << endl;
            return;
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