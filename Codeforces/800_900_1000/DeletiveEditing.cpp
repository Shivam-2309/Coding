/*      Jai Shree Ram      */
/*      Code Snippet of Shivam Kapoor      */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
void solve(){
    string s1, s2;
    cin >> s1 >> s2;

    
    vector<ll> freq1(26, 0);
    vector<ll> freq2(26, 0);

    for(ll i=0; i<s1.length(); i++) freq1[s1[i]-'A']++;
    for(ll i=0; i<s2.length(); i++) freq2[s2[i]-'A']++;

    for(ll i=0; i<26; i++){
        if(freq1[i] - freq2[i] < 0){
            cout << "NO" << endl;
            return;
        }
    }

    // Simply Simulate the game
    unordered_set<char> st;
    for(ll i=0; i<s2.length(); i++){
        char ch = s2[i];
        if(st.find(ch) == st.end()){
            // Remove the first freq1[ch] - freq2[ch] characters from s1
            ll to_remove = freq1[ch - 'A'] - freq2[ch - 'A'];
            // cout << to_remove << endl;
            for(ll j=0; j<s1.length(); j++){
                if(to_remove == 0) break;
                if(s1[j] == ch){
                    s1[j] = '#';
                    to_remove--;
                }
            }
            st.insert(ch);
        }   
    }

    // Now check whether is it possible or not
    ll i = 0;
    ll j = 0;
    ll cnt = 0;
    while(i < s1.length()){
        char ch = s2[j];
        while(i < s1.length() && s1[i] != s2[j]){
            i++;
        }
        if(s1[i] == s2[j]){
            i++;
            j++;
        }

        if(j == s2.length()){
            cout << "YES" << endl;
            return;
        }
    }
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