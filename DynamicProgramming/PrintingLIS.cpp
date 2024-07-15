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
    vector<ll> insertedAt(n);

    vector<ll> res;
    for(ll i=0; i<n; i++){
        ll idx = lower_bound(res.begin(), res.end(), v[i]) - res.begin();
        if(idx == res.size()){ 
            res.push_back(v[i]);
            insertedAt[i] = idx+1;
        }
        else {
            res[idx] = v[i];
            insertedAt[i] = idx+1;
        }
    }

    print(insertedAt);
    vector<ll> ans;
    ll maxi = *max_element(insertedAt.begin(), insertedAt.end());
    for(ll i=n-1; i>=0; i--){
        if(maxi == insertedAt[i]){
            ans.push_back(v[i]);
            maxi--;
        }
    }

    rev(ans);
    for(auto it : ans) cout << it << " ";
    cout << endl;
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
/*     The code finishes, I hope it gets Accepted      */