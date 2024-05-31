/*      Jai Shree Ram      */
/*      Code Snippet of Shivam Kapoor      */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end());
#define endl '\n'
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
const int NUM = 2e5 + 7;
const ll INF = 1e18 + 5;
bool sieve[NUM];
void sieveOfEratosthenes() {
    memset(sieve, true, sizeof(sieve));
    sieve[1] = false;
    sieve[0] = false; 
    for (ll p = 2; p * p <= NUM; p++) {
        if (sieve[p]) {
            for (ll i = p * p; i <= NUM; i += p)
                sieve[i] = false;
        }
    }
}
// ll dp[NUM];
void solve(){
    ll n;
    cin >> n;
    
    vector<ll> v(n);
    for(ll i=0; i<n; i++) cin >> v[i];

    vector<ll> pre(n);
    vector<ll> suff(n);
    pre[0] = v[0];
    suff[n-1] = v[n-1];
    for(ll i=1; i<n; i++){
        pre[i] = (v[i]*pre[i-1])%NUM;
    }
    for(ll i=n-2; i>=0; i--){
        suff[i] = (suff[i+1]*v[i])%NUM;
    }

    for(ll i=0; i<n-1; i++){
        if(pre[i] == suff[i+1]){
            cout << i+1 << endl;
            return;
        }
    }
    cout << -1 << endl;

    // 2 2 1 2 1 2
    // -> 2 4 4 8 8 16
    // -> 16 8 4 4 2 2
}
// clear all data structures between test cases
// handle all corner cases
// confusing between n and m , i and j?
// uninitialized variables?
// Read the question again
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // sieveOfEratosthenes()
    // memset(dp, -1, sizeof(dp));
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*     The code finishes, I hope it gets Accepted      */