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
    string s; cin >> s;
    ll n = s.length();
    vll preA(n, 0);
    vll suffA(n, 0);
    vll preB(n, 0);
    vll suffB(n, 0);
    for(ll i = 0; i < n; i++){
        preA[i] = (i > 0 ? preA[i - 1] : 0) + (s[i] == 'a');
        preB[i] = (i > 0 ? preB[i - 1] : 0) + (s[i] == 'b');
    }
    for(ll i = n - 1; i >= 0; i--){
        suffA[i] = (i < n - 1 ? suffA[i + 1] : 0) + (s[i] == 'a');
        suffB[i] = (i < n - 1 ? suffB[i + 1] : 0) + (s[i] == 'b');
    }

    ll ans = 0;
    for(ll i = 0; i < n; i++){
        if(s[i] == 'a') ans++;
    }


    for(ll i = 0; i < n; i++){
        for(ll j = i; j < n; j++){
            ll cnt1 = 0;
            if(i > 0) cnt1 += preB[i-1];
            if(j + 1 < n) cnt1 += suffB[j+1];
            if(i > 0) cnt1 -= preA[i-1];
            cnt1 += preA[j];
            ans = max(ans, n - cnt1);
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
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}