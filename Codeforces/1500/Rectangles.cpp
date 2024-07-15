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
vector<pair<ll, ll>> factorPairs(ll n) {
    vector<pair<ll, ll>> facts;

    for (ll d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            facts.push_back({d, n / d});
            if (d != n / d) {
                facts.push_back({n / d, d});
            }
        }
    }

    return facts;
}

void solve(){
    ll n, m, k; cin >> n >> m >> k;

    vector<ll> rows;
    ll cnt = 0;
    for(ll i=0; i<n; i++){
        ll num; cin >> num;

        if(num == 1) cnt++;
        else{
            rows.push_back(cnt);
            cnt = 0;
        }
    }

    if(cnt != 0){
        rows.push_back(cnt);
    }

    cnt = 0;

    vector<ll> cols;
    for(ll i=0; i<m; i++){
        ll num; cin >> num;

        if(num == 1) cnt++;
        else{
            cols.push_back(cnt);
            cnt = 0;
        }
    }

    if(cnt != 0){
        cols.push_back(cnt);
    }

    vector<pair<ll, ll>> v = factorPairs(k);

    set<ll> mt;

    for(ll i=0; i<v.size(); i++){
        mt.insert(v[i].first);
        mt.insert(v[i].second);
    }

    map<ll, ll> mp1;

    for(auto divs : mt){
        for(ll i=0; i<rows.size(); i++){
            ll len = rows[i];

            if(rows[i] - divs + 1 > 0) mp1[divs] += (rows[i] - divs + 1);
        }
    }

    map<ll, ll> mp2;

    for(auto divs : mt){
        for(ll i=0; i<cols.size(); i++){
            ll len = cols[i];

            if(cols[i] - divs + 1 > 0) mp2[divs] += (cols[i] - divs + 1);
        }
    }

    ll ans = 0;

    for(ll i=0; i<v.size(); i++){
        ll rowNum = v[i].first;
        ll colNum = v[i].second;

        ans += mp1[rowNum] * mp2[colNum];
    } 

    cout << ans << endl;
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