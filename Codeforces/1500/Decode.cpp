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
    vector<ll> p;
    p.push_back(0);
    ll n = s.length();
    for(ll i = 1; i <= n; i++){
        if(s[i - 1] == '1') p.push_back(1);
        else p.push_back(-1);
    }

    for(ll i=1; i<=n; i++) p[i] = (p[i]%mod7 + p[i-1]%mod7)%mod7;

    map<ll, vll> mp1;
    for(ll i = 0; i <= n; i++) mp1[p[i]].push_back(i);
    
    map<ll, vll> mp2;
    for(auto it : mp1){
        vll v = it.second;
        ll sz = v.size();
        for(ll i=0; i<sz; i++) v[i] = (n%mod7 - v[i]%mod7 + 1%mod7)%mod7;
        for(ll i=sz-2; i>=0; i--) v[i] = (v[i]%mod7 + v[i+1]%mod7)%mod7;
        mp2[it.first] = v;
    }

    ll ans = 0;

    for (ll i = 0; i <= n; i++) {
        ll sum = p[i];
        ll idx = upper_bound(mp1[sum].begin(), mp1[sum].end(), i) - mp1[sum].begin();
        if (idx < mp2[sum].size()) ans = (ans%mod7 +  ((mp2[sum][idx]%mod7) * ((i + 1)%mod7))%mod7)%mod7;
        
    }

    cout << ans%mod7 << endl;
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