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
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> v(n, vector<ll> (m, 0));

    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            ll a; cin >> a;
            v[i][j] = a;
        }
    }

    map<ll, vector<pair<ll, ll>>> mp1;
    map<ll, tuple<ll, ll, ll>> mp2;

    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            mp1[v[i][j]].push_back({i, j});
        }
    }

    for(auto i : mp1){
        vector<pair<ll, ll>> vv = i.second;
        ll X = 0;
        ll Y = 0;

        for(auto it : vv){
            X += it.first;
            Y += it.second;
        }

        mp2[i.first] = {X, Y, vv.size()};
    }

    ll sum = 0;

    for (auto i : mp1) {
        vector<pair<ll, ll>> vv = i.second;
        tuple<ll, ll, ll> tup = mp2[i.first];
        ll total_x = get<0>(tup);
        ll total_y = get<1>(tup);
        ll count = get<2>(tup);

        vll Ys;
        vll Xs;

        for(ll i=0; i<vv.size(); i++){
            Xs.push_back(vv[i].first);
            Ys.push_back(vv[i].second);
        }

        srt(Xs);
        srt(Ys);    

        ll temp = 0;

        for (ll i=0; i<vv.size(); i++) {
            ll X = Xs[i];
            ll Y = Ys[i];
            temp += (abs(total_x - (count)*X) + abs(total_y - (count)*Y));
            count--;
            total_x -= X;
            total_y -= Y;
        }

        sum += temp;
    }

    cout << sum << endl;
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