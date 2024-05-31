#include<bits/stdc++.h>
using namespace std;
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
#define MOD 1000000007
ll lcm(ll a, ll b)
{
    return a * b / __gcd(a, b);
}
// binary modular exponentiation
ll binpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    if (b & 1)
        return res * res * a;
    else
        return res * res;
}
ll binpowmod(ll a, ll b, ll m=MOD)
{
    a %= m;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
ll mminvprime(ll a, ll b)
{ // gives modulo inverse of a wrt b where b is prime
    return binpowmod(a, b - 2, b);
}
ll mod_add(ll a, ll b, ll m=MOD)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m=MOD)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m=MOD)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
ll mod_div(ll a, ll b, ll m=MOD)
{
    a = a % m;
    b = b % m;
    return (mod_mul(a, mminvprime(b, m), m) + m) % m;
} // only for prime m
// ll dp[NUM];
void solve(){
    ll n; cin >> n;
    vll sp(n);
    rep(i, n) cin >> sp[i];
    vll hs(n);
    rep(i, n) cin >> hs[i];

    vll diff;
    for(ll i=0; i<n; i++){
        diff.push_back(hs[i] - sp[i]);
    }
    srt(diff);
    // print(diff);

    ll l = 0;
    ll r = n-1;
    ll cnt = 0;

    while(l < r){
        if(diff[l] + diff[r] < 0){
            l++;
        }
        else{
            cnt++;
            l++;
            r--;
        }
    }

    cout << cnt << endl;
}
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