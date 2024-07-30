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
    ll n, k, z;
    cin >> n >> k >> z;

    vll v(n);
    rep(i, n) cin >> v[i];
    v.insert(v.begin(), 0);
    vector<ll> p(n+1, 0);
    for(ll i=1; i<=n; i++) p[i] = p[i-1] + v[i];

    ll ans = 0;
    while(z >= 0){
        ll turn = z;
        z--;

        ll finalPos = k - 2*turn + 1;
        if(finalPos <= 0) continue;
        ll maxi = 0;
        for(ll i = 1; i <= finalPos; i++){
            maxi = max(maxi, v[i] + v[i+1]);
        }
        ans = max(ans, p[finalPos] + turn*maxi);
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