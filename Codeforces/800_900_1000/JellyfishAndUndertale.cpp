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
    // Computation of String Matching in O(M+N) time
void computeLPS(string pattern, vector<int>& lps) {
    int M = pattern.length();
    int len = 0; // Length of the previous longest prefix & suffix
    
    lps[0] = 0; // Because there is no proper suffix and prefix of pattern[0..0]
    
    int i = 1;
    while (i < M) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1]; //You can also write, len = len-1;
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int KMP(string txt, string pattern) {
    // KMP Algorithm

    // Now i need to find the first appearance of pattern in the text, this is done using the KMP Algorithm

    // Using the standard Code Snippet

    int N = txt.length();
    int M = pattern.length();
    vector<int> result;
    
    // Create an LPS array to store the longest proper prefix which is also a suffix
    //lps[i] = the longest proper prefix of pat[0..i] which is also a suffix of pat[0..i]. 
    vector<int> lps(M, 0);
    computeLPS(pattern, lps);
    int i = 0; // Index for text
    int j = 0; // Index for pattern

    while (i < N) {
        if (txt[j] == pattern[i]) {
            i++;
            j++;
        }

       if (j == M) {
           return i-j; //Pattern found at index i-j+1 (If you have to return 1 Based indexing, that's why added + 1)
           j = lps[j - 1];
       } else if (i < N && txt[j] != pattern[i]) {
           if (j != 0) {
               j = lps[j - 1];
           } else {
               i++;
           }
       }
     }
    return -1;
    }
// ll dp[NUM];
void solve(){
    ll a, b, n;
    cin >> a >> b >> n;

    vector<ll> v(n);
    for(ll i=0; i<n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    ll time = b;
    ll second = 0;

    for(ll i=0; i<n; i++){
        second += (time-1);
        time = min(a, 1 + v[i]);
    }

    cout << second+time << endl;
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