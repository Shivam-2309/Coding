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

bool isPossible(ll mid, vector<ll> &v, ll k){
    ll req = 0;
    for(ll i=0; i<v.size(); i++){
        if(v[i] >= mid){
            // balle balle
        }
        else{
            req += (mid - v[i]);
        }
    }

    return req <= k;
}

void solve(){
    ll n, k; cin >> n >> k;
    vll v(n);
    rep(i, n) cin >> v[i];

    ll lo = *min_element(v.begin(), v.end());
    ll hi = *max_element(v.begin(), v.end());
    ll ans = -1;

    while(lo <= hi){
        ll mid = ((lo + hi) >> 1);

        if(isPossible(mid, v, k)){
            ans = mid;
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }

    // debug(ans);
    ll kk = k;
    vll extra(n, 0);

    for(ll i=0; i<n; i++){
        if(v[i] >= ans){
            extra[i] = v[i]-ans;
        }
        else{
            k -= (ans - v[i]);
            v[i] = ans;
        }
    }
    ll more = 0;
    for(ll i=0; i<n; i++){
        more += (extra[i] > 0 ? 1 : 0);
    }
    more += k;
    ll res = (ans*n + more - n + 1);

    cout << res << endl;
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