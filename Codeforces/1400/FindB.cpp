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
    ll n, q; cin >> n >> q;
    vll v(n);
    rep(i, n) cin >> v[i];

    vll pre(n, 0);
    pre[0] = (v[0] == 1 ? 1 : 0);
    for(ll i=1; i<n; i++){
        pre[i] = pre[i-1] + (v[i] == 1 ? 1 : 0);
    }
    vll pre2(n, 0);
    for(ll i=0; i<n; i++){
        if(v[i] >= 2) pre2[i] = (v[i] - 1);
    }
    for(ll i=1; i<n; i++){
        pre2[i] = pre2[i-1] + pre2[i]; 
    }

    while(q--){
        ll l, r; cin >> l >> r;
        l--;
        r--;

        ll len = (r - l + 1);
        if(len == 1){
            cout << "NO" << endl;
            continue;
        }

        ll num_ones = pre[r] - (l > 0 ? pre[l-1] : 0);

        if(num_ones > (len / 2)){
            ll sum = pre2[r] - (l > 0 ? pre2[l-1] : 0);
            if(sum >= num_ones){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        else{
            cout << "YES" << endl;
        }
    }
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