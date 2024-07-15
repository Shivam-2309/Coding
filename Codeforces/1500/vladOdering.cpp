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
    ll n, k; cin >> n >> k;

    if(n == 1 && k == 1){
        cout << 1 << endl;
        return;
    }
    // n = 21 k = 13
    vll pre;
    if(n%2) pre.push_back(n/2 + 1);
    else pre.push_back(n/2);
    // debug(n);
    ll curr = 0;
    ll s = 2;
    while(true){
        curr += ((n - s)/(2*s) + 1);
        pre.push_back((n - s)/(2*s) + 1);
        if(curr == n/2) break;
        s = (s << 1);
    }

    for(ll i=1; i<pre.size(); i++){
        pre[i] = pre[i-1] + pre[i];
    }

    ll idx = lower_bound(pre.begin(), pre.end(), k) - pre.begin();
    ll gap = (1 << (idx+1));
    ll start = (1 << idx);
    ll times = k - (idx > 0 ? pre[idx-1] : 0);
    ll ans = (start + (times-1)*gap);
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
/*     The code finishes, I hope it gets Accepted      */