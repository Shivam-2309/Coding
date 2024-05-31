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
// ll dp[100001];

vector<ll> getBinaryFormat(ll number) {
    vector<ll> binary(32, 0);  // Initialize vector of size 32 with all 0s
    for (ll i = 31; i >= 0; --i) {
        binary[i] = (number & 1);    // Get the last bit of the number
        number >>= 1;                // Shift the number to the right by 1 bit
    }
    return binary;
}

bool isValid(vector<ll> &v){
    for(ll i=1; i<v.size(); i++){
        if(v[i]!=0 && v[i-1]!=0){
            return true;
        }
    }
    return false;
}

void solve(){
    ll n;
    cin >> n;

    vll v = getBinaryFormat(n);
    rev(v);

    while(isValid(v)){
        for(ll i=31; i>=1; i--){
            if(v[i] == 1 && v[i-1] == 1){
                v[i+1] = 1;
                v[i]   = 0;
                v[i-1] = -1;
            }
            else if(v[i] == -1 && v[i-1] == 1){
                v[i] = 0;
                v[i-1] = -1;
            }
        }
    }

    ll idx = 0;
    for(ll i=0; i<32; i++){
        if(v[i] == 1 || v[i] == -1){
            idx = i;
        }
    }
    cout << idx+1 << endl;
    for(ll i=0; i<=idx; i++){
        cout << v[i] << " ";
    }cout << endl;
}
// Read the question again
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // sieveOfEratosthenes()
    // memset(dp, -1, sizeof(dp));
    // cout.precision(15);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*     The code finishes, I hope it gets Accepted      */