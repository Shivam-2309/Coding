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
ll factorial(ll num){
    ll prod = 1;
    for(ll i=1; i<=num; i++){
        prod = ((prod%mod9)*(i%mod9))%mod9;
    }
    return prod%mod9;
}

void solve(){
    string s;
    cin >> s;

    ll n = s.length();

    vll ones;
    vll zeros;

    ll cnt = 0;
    for(ll i=0; i<n; i++){
        if(s[i] == '1'){
            cnt++;
        }
        else{
            if(cnt != 0) ones.push_back(cnt);
            cnt = 0;
        }
    }

    if(cnt != 0) ones.push_back(cnt);
    // print(ones);

    cnt = 0;
    for(ll i=0; i<n; i++){
        if(s[i] == '0'){
            cnt++;
        }
        else{
            if(cnt != 0) zeros.push_back(cnt);
            cnt = 0;
        }
    }

    if(cnt != 0) zeros.push_back(cnt);
    // print(zeros);

    ll minSize = ones.size() + zeros.size();

    ll prod = 1;
    for(int i=0; i<ones.size(); i++){
        if(ones[i] != 1) prod = ((prod%mod9)*(ones[i]%mod9))%mod9;
    }
    for(int i=0; i<zeros.size(); i++){
        if(zeros[i] != 1) prod = ((prod%mod9)*(zeros[i]%mod9))%mod9;
    }

    cout << n - minSize << " " << ((prod%mod9) * (factorial(n-minSize)%mod9))%mod9 << endl;
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