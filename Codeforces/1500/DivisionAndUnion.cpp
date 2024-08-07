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

    vector<pair<pair<ll, ll>, ll>> v;
    for(ll i=0; i<n; i++){
        ll l, r;
        cin >> l >> r;

        v.push_back({{l, r}, i});
    }

    auto cmp = [&](pair<pair<ll, ll>, ll> a, pair<pair<ll, ll>, ll> b) {
        return a.first.second < b.first.second;
    };

    sort(v.begin(), v.end(), cmp);

    map<ll, ll> mp;

    for(ll i=0; i<n; i++){
        mp[v[i].first.first]++;
    }

    vll ones;

    // for(auto i : mp){
    //     cout << i.first << endl;
    // }

    for(ll i=0; i<n; i++){
        mp[v[i].first.first]--;

        if(mp[v[i].first.first] == 0) mp.erase(v[i].first.first);

        auto it = mp.begin();
        if(it -> first > v[i].first.second){
            ones.push_back(v[i].second);
            break;
        }
        else{
            ones.push_back(v[i].second);
        }
    }

    if(ones.size() == n){
        cout << -1 << endl;
        return;
    }


    set<ll> st(ones.begin(), ones.end());

    for(ll i=0; i<n; i++){
        if(st.find(i) == st.end()){
            cout << 2 << " ";
        }else{
            cout << 1 << " ";
        }
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