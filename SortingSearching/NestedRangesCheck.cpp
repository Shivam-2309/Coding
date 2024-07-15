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
    ll n; cin >> n;

    vector<vector<ll>> ranges(n);

    for(ll i=0; i<n; i++){
        ll l, r; cin >> l >> r;
        ranges[i] = {l, r, i};
    }

    auto cmp = [&](vector<ll> &a, vector<ll> &b) {
        if (a[0] != b[0]) {
            return a[0] < b[0];
        } else {
            return a[1] > b[1];
        }
    };

    sort(ranges.begin(), ranges.end(), cmp);

    ll maxRightBoundary = 0;

    vector<ll> contained(n, 0);
    for(ll i=0; i<n; i++){
        if(ranges[i][1] <= maxRightBoundary){
            contained[ranges[i][2]] = 1;
        }
        maxRightBoundary = max(maxRightBoundary, ranges[i][1]);
    }

    ll minRightBoundary = 1e18;

    vector<ll> contains(n, 0);
    for(ll i=n-1; i>=0; i--){
        if(ranges[i][1] >= minRightBoundary){
            contains[ranges[i][2]] = 1;
        }
        minRightBoundary = min(minRightBoundary, ranges[i][1]);
    }


    for(auto &i : contains) cout << i << " ";
    cout << endl;
    for(auto &i : contained) cout << i << " ";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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