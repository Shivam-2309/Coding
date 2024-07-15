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
void solve() {
    ll n, m; 
    cin >> n >> m;
    vector<string> grid1(n);
    vector<string> grid2(n);

    for (ll i = 0; i < n; i++) {
        cin >> grid1[i];
    }
    for (ll i = 0; i < n; i++) {
        cin >> grid2[i];
    }

    vector<vector<ll>> g1(n, vector<ll>(m));
    vector<vector<ll>> g2(n, vector<ll>(m));
    
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (grid1[i][j] == '1') {
                g1[i][j] = 1;
            } else if (grid1[i][j] == '0') {
                g1[i][j] = 0;
            } else {
                g1[i][j] = 2;
            }
        }
    }

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (grid2[i][j] == '1') {
                g2[i][j] = 1;
            } else if (grid2[i][j] == '0') {
                g2[i][j] = 0;
            } else {
                g2[i][j] = 2;
            }
        }
    }

    // for(ll i=0; i<n; i++){
    //     for(ll j=0; j<m; j++){
    //         cout << g1[i][j] << " ";
    //     }cout << endl;
    // }

    // for(ll i=0; i<n; i++){
    //     for(ll j=0; j<m; j++){
    //         cout << g2[i][j] << " ";
    //     }cout << endl;
    // }

    for (ll i = n - 1; i >= 1; i--) {
        for (ll j = m - 1; j >= 1; j--) {
            if (g1[i][j] != g2[i][j]) {
                ll times = -1;
                if(g1[i][j] > g2[i][j]) times = (g2[i][j] - g1[i][j] + 3)%3;
                else times = g2[i][j] - g1[i][j];


                g1[i][j] = g2[i][j];
                g1[i-1][j] = (g1[i - 1][j] + 2*times) % 3;
                g1[i][j-1] = (g1[i][j - 1] + 2*times) % 3;
                g1[i-1][j-1] = (g1[i - 1][j - 1] + times) % 3;
            }
        }
    }

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (g1[i][j] != g2[i][j]) {
                cout << "NO" << endl;
                return;
            }
        }
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