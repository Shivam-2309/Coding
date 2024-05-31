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

    vll v(n);
    rep(i, n) cin >> v[i];

    // print(v);

    vector<ll> v1;
    vector<ll> v2;

    ll cnt = 0;
    v1.push_back(v[0]);
    
    for(ll i=1; i<n; i++){
        ll last1 = (v1.size()>0?v1[v1.size() - 1]:0);
        ll last2 = (v2.size()>0?v2[v2.size() - 1]:0);

        if(last1 <= last2){
            if(v[i] <= last1){
                v1.push_back(v[i]);
            }
            else if(v[i] > last2){
                if(v1.size() != 0) cnt++;
                v1.push_back(v[i]);
            }
            else{
                // cnt++;
                v2.push_back(v[i]);
            }
        }
        else{
            if(v[i] <= last2){
                v2.push_back(v[i]);
            }
            else if(v[i] > last1){
                if(v2.size() != 0) cnt++;
                v2.push_back(v[i]);
            }
            else{
                // cnt++;
                v1.push_back(v[i]);
            }
        }
    }

    cout << cnt << endl;

    // 5 4 3   -> now came 8, so one of them is bound to have a penalty, and the new highest last number would become the new number   
    // 9 7 6 

    // 3 8 -> 5 came -> 3 5 -> 4 comes -> 3 4 -> 5 comes -> guarantee a penalty
    // 6 8 -> 5 came -> 5 8 or 6 -> 5 -> 4 8 -> 5 comes -> no penalty
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