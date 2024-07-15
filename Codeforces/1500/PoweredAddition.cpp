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
#define ll long long
#define vll vector<ll>
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end());
#define rep(i, n) for (ll i = 0; i < n; i++)
const ll mod7 = 1e9 + 7;
const ll mod9 = 998244353;
ll power(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return res;
}
ll lcm(ll a, ll b)
{
    return a * b / __gcd(a, b);
}
// ll dp[100001];
void solve(){
    ll n; cin >> n;
    vll v(n);
    rep(i, n) cin >> v[i];

    if(is_sorted(v.begin(), v.end())){
        cout << 0 << endl;
        return;
    }

    vector<pair<ll, ll>> allSums;

    vector<ll> t;
    for(ll i=0; i<32; i++){
        t.push_back((1ll << i));
    }

    // print(t);

    for(ll i=0; i<32; i++){
        ll sum = 0;
        for(ll j=i; j<32; j++){
            sum += t[j];
            allSums.push_back({sum, j+1});
        }
    }

    vector<ll> temp;
    srt(allSums);
    for(ll i=0; i<allSums.size(); i++){
        temp.push_back(allSums[i].first);
    }
    
    ll maxCnt = 0;

    for(ll i=1; i<n; i++){
        ll cnt = 0;
        if(v[i-1] > v[i]){
            // do the needful
            ll diff = v[i-1] - v[i];
            ll idx = lower_bound(temp.begin(), temp.end(), diff) - temp.begin();
            ll correspondingCnt = allSums[idx].second;
            maxCnt = max(maxCnt, correspondingCnt);
            v[i] += allSums[idx].first;
        }
        // print(v);
    }

    // print(v);

    cout << maxCnt << endl;
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
/*     The code finishes, I hope it gets Accepted      */