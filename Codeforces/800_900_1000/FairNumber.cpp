/*      Jai Shree Ram      */
/*      Code Snippet of Shivam Kapoor      */
/*
Ek Ajnabi Hasina Se Yu Mulakat..... Ho Gayi
Phir Kya Hua... Ye Na Puchho... Kuch Aisi Baat Ho Gayi
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end());
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
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
// returns sorted prime factorisation in sqrt(N)
vector<ll> primefactorisation1(int n)
{
    vector<ll> factorisation;
    for (ll d = 2; d * d <= n; d++)
    {
        while (n % d == 0)
        {
            factorisation.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
    {
        factorisation.push_back(n);
    }
    return factorisation;
}
// O(r) Time Complexity
ll nCr(int n, int r)
{
    ll p = 1, k = 1;
    if (n - r < r)
        r = n - r;
    if (r != 0)
    {
        while (r)
        {
            p *= n;
            k *= r;
            ll m = __gcd(p, k);
            p /= m;
            k /= m;
            n--;
            r--;
        }
    }
    else
        p = 1;
    return p;
}
// ll dp[NUM];
 // **************************************Helpful functions************************************
bool isValid(ll &n){
    vector<ll> v;
    ll t = n;
    while(t){
        ll last_digit = t%10;
        t /= 10;
        if(last_digit != 0) v.push_back(last_digit);
    }

    for(auto &it: v){
        if(n%it != 0) return false;
    }
    return true;
}

void solve(){
    ll n; cin >> n;

    while(true){
        if(isValid(n)){
            cout << n << endl;
            return;
        }
        n++;
    }
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