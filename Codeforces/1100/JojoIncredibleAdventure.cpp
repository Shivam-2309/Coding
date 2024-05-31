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
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#define print(v) do { \
                    cout << "vect--" << #v << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << v[i] << " "; \
                    } \
                    cout << " ]" << endl; \
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
ll computeXOR(ll n) { return n % 4 == 0 ? n : (n % 4 == 1 ? 1 : (n % 4 == 2 ? n + 1 : 0)); }
// ll dp[NUM];
 // **************************************Helpful functions************************************
void solve(){
    string s;
    cin >> s;
    // Conctenation for cyclic analysis
    s += s;
 
    ll maxLen = 0;
    ll len = 0;

    // Finding the longest substring having a particular character
    // Simple O(N) operation
    for(ll i=0; i<s.length(); i++){
        if(s[i] == '1') len++;
        else len=0;
        maxLen = max(maxLen, len);
    }
    
    ll n = s.size()/2;
    
    if(maxLen == 2*n){
        cout << (ll)(n*n) << endl;
        return;
    }

    // Mathematical Aspect of the question
    ll side_1 = (maxLen+1)/2;
    ll side_2 = (maxLen+2)/2;
 
    cout << side_1 * side_2 << endl;
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