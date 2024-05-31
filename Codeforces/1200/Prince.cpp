#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;
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
#define vp vector<pair<long long, long long>>
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end());
#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
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
// ll dp[NUM];

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
    int strStr(string haystack, string needle) {
        // This is a straightaway application of KMP Algorithm

        // Haystack -> txt
        // needle -> pattern

        // Now i need to find the first appearance of pattern in the text, this is done using the KMP Algorithm

        // Using the standard Code Snippet

        int N = haystack.length();
        int M = needle.length();
        vector<int> result;
        
        // Create an LPS array to store the longest proper prefix which is also a suffix
        //lps[i] = the longest proper prefix of pat[0..i] which is also a suffix of pat[0..i]. 
        vector<int> lps(M, 0);
        computeLPS(needle, lps);
    
        int i = 0; // Index for text
        int j = 0; // Index for pattern
    
        while (i < N) {
            if (needle[j] == haystack[i]) {
                i++;
                j++;
            }
    
            if (j == M) {
                return i-j; //Pattern found at index i-j+1 (If you have to return 1 Based indexing, that's why added + 1)
                j = lps[j - 1];
            } else if (i < N && needle[j] != haystack[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return -1;
    }

void solve(){
    ll n;
    cin >> n;

    string s;
    cin >> s;

    string t = "";
    ll sz = 0;
    string str = "a";
    for(ll i=0; i<26; i++){
        if(strStr(s, str) == -1){
            cout << str << endl;
            return;
        }
        str[0]++;
    }

    str = "aa";
    for(ll i=0; i<26; i++){
        for(ll j=0; j<26; j++){
            if(strStr(s, str) == -1){
                cout << str << endl;
                return;
            }
            if(str[1] == 'z'){
                str[1] = 'a';
                break;
            }
            str[1]++;
        }
        str[0]++;
    }

    str = "aaa";
    for(ll i=0; i<26; i++){
        for(ll j=0; j<26; j++){
            for(ll k=0; k<26; k++){
                if(strStr(s, str) == -1){
                    cout << str << endl;
                    return;
                }
                if(str[2] == 'z'){
                    str[2] = 'a';
                    break;
                }
                str[2]++;
            }
            if(str[1] == 'z'){
                str[1] = 'a';
                break;
            }
            str[1]++;
        }
        str[0]++;
    }
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