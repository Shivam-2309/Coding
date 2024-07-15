#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
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
ll lcm(ll a, ll b)
{
    return a * b / __gcd(a, b);
}
// ll dp[100001];
void solve(){
    ll n, k; cin >> n >> k;
    string s; cin >> s;

    ll ones = 0;
    ll zeros = 0;

    for(ll i = 0; i < k; i++){
        ll numZeros = 0;
        ll numOnes = 0;
        ll numMarks = 0;

        for(ll j = i; j < n; j+=k){
            if(s[j] == '1') numOnes++;
            if(s[j] == '0') numZeros++;
            if(s[j] == '?') numMarks++;
        }

        if(numZeros > 0 && numOnes > 0){
            cout << "NO" << endl;
            return;
        }

        if(numZeros > 0) zeros++;
        if(numOnes > 0) ones++;
        
    }

    if(zeros > k/2 || ones > k/2){
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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