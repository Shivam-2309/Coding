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
void solve(){
    ll n; cin >> n;

    vector<vector<char>> grid(n, vector<char> (n, '.'));

    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            char ch; cin >> ch;
            grid[i][j] = ch;
        }
    }

    // Let us define the DP state like -> 
    // dp[i][j] = number of ways to come to i, j, from {0, 0}

    // DP Transition -> dp[i][j] = dp[i-1][j] + dp[i][j-1]
    // Id obstacle -> then dp[i][j] = 0

    if(grid[0][0] == '*'){
        cout << 0 << endl;
        return;
    }

    vector<vector<ll>> dp(n+1, vector<ll> (n+1, 0));
    dp[0][0] = 1;

    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            if(i == 0 && j == 0) continue;
            if(grid[i][j] == '*'){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = 0;
                if(i-1 >= 0) dp[i][j] = (dp[i][j]%mod7 + dp[i-1][j]%mod7)%mod7;
                if(j-1 >= 0) dp[i][j] = (dp[i][j]%mod7 + dp[i][j-1]%mod7)%mod7;
            }
        }
    }

    cout << dp[n-1][n-1] << endl;
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
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*     The code finishes, I hope it gets Accepted      */