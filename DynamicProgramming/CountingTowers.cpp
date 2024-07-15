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
 
    if(n == 1){
        cout << 2 << endl;
        return;
    }
    
    ll dp[n+2][2];
    dp[n+1][0] = 1;
    dp[n+1][1] = 1;
 
    for(ll rowNum = n; rowNum >= 2; rowNum--){
        for(ll j = 0; j <= 1; j++){
            if(j == 0){
                dp[rowNum][j] = (4ll*dp[rowNum+1][0] + dp[rowNum+1][1])%mod7;
            }
            else{
                dp[rowNum][j] = (2ll*dp[rowNum+1][1] + dp[rowNum+1][0])%mod7;
            }
        }
    }
 
    cout << (dp[2][1] + dp[2][0])%mod7 << endl;
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
