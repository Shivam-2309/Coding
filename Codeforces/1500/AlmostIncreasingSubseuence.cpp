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
    ll n, q;
    cin >> n >> q;
    vll v(n);
    rep(i, n) cin >> v[i];

    vll prePatch(n-1, 0);
    for(ll i=1; i < n-1; i++){
        if(v[i] <= v[i-1] && v[i] >= v[i+1]){
            prePatch[i] = prePatch[i-1] + 1;
        }
        else{
            prePatch[i] = prePatch[i-1];
        }
    }

    print(prePatch);

    while(q--){
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        if(l == r){
            cout << 1 << endl;
            continue;
        }
        ll sum2 = (r > 0 ? prePatch[r-1] : 0) - prePatch[l];
        cout <<  (r - l + 1) - sum2 << endl;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.precision(15);
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}