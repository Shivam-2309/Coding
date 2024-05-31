 // Ek Ajnabi Hasina Se Yu Mulakat..... Ho Gayi
 // Phir Kya Hua... Ye Na Puchho... Kuch Aisi Baat Ho Gayi
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
template <typename T> using pbds = tree<T, null_type,
less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/* find_by_order(K): Returns an iterator to the Kth largest element (counting from zero) */
/* order_of_key (K): Returns the number of items that are strictly smaller than K */
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
    ll w, h;
    cin >> w >> h;

    vector<ll> v1;
    vector<ll> v2;

    ll s1;
    cin >> s1;
    v1.resize(s1);
    for(ll i=0; i<s1; i++){
        cin >> v1[i];
    }
    ll s2;
    cin >> s2;
    v2.resize(s2);
    for(ll i=0; i<s2; i++){
        cin >> v2[i];
    }

    srt(v1);
    srt(v2);

    ll mb1 = v1[v1.size()-1] - v1[0];
    ll mb2 = v2[v2.size()-1] - v2[0];

    ll max_a1 = h * max(mb1, mb2);

    vector<ll> v3;
    vector<ll> v4;
    
    ll s3;
    cin >> s3;
    v3.resize(s3);
    for(ll i=0; i<s3; i++){
        cin >> v3[i];
    }
    ll s4;
    cin >> s4;
    v4.resize(s4);
    for(ll i=0; i<s4; i++){
        cin >> v4[i];
    }

    srt(v3);
    srt(v4);

    ll mb3 = v3[v3.size()-1] - v3[0];
    ll mb4 = v4[v4.size()-1] - v4[0];

    ll max_a2 = w * max(mb3, mb4);

    cout << max(max_a1, max_a2) << endl;

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