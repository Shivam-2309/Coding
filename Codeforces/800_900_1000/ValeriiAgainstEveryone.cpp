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
int64_t ceil_div(int64_t a, int64_t b) {
    return (a + b - 1) / b;
}
// ll dp[NUM];
 // **************************************Helpful functions************************************
void solve(){
    ll n;
    cin >> n;
    vll v(n);
    rep(i, n) cin >> v[i];

    unordered_set<ll> st;
    for(ll i=0; i<n; i++){
        if(st.find(v[i]) != st.end()){
            cout << "YES" << endl;
            return;
        }else{
            st.insert(v[i]);
        }
    }

    // vll a(n);
    // for(ll i=0; i<n; i++){
    //     a[i] = power(2, v[i]);
    // }

    // vll pre(n);
    // pre[0] = a[0];
    // for(ll i=1; i<n; i++){
    //     pre[i] = a[i] + pre[i-1];
    // }

    // for(ll i=1; i<=n/2; i++){
    //     unordered_set<ll> st;
    //     ll l = 0;
    //     ll r = i-1;

    //     while(r < n){
    //         ll sum = pre[r] - (l > 0 ? pre[l-1] : 0);
    //         cout << sum << endl;
    //         if(st.find(sum) != st.end()){
    //             // cout << sum << endl;
    //             cout << "YES" << endl;
    //             return;
    //         }
    //         else{
    //             st.insert(sum);
    //         }
    //         l = r+1;
    //         r = (l+i-1);
    //     }
    // }



    cout << "NO" << endl;
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