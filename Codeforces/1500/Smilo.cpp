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

bool isValid(vector<ll> v, ll T){
    ll t = T;
    ll x = 0;

    ll i = 0;
    ll j = v.size()-1;

    while(t > 0){
        if(i == j){
            double need = (v[i] - x);
            if(v[i] == 1){
                if(t == 1){
                    j--;
                    break;
                }
            }
            t -= (ceil(need/2) + 1);
            if(t >= 0){
                j--;
                break;
            }
            else{
                break;
            }
        }

        bool f = false;

        if(i < v.size() && v[i] >= (v[j]-x)){
            ll tt = v[j] - x;
            v[i] -= tt;
            x = v[j];
            t -= tt;
            if(v[i] == 0) i++;
        }
        else if(i < v.size() && v[i] <= t){
            t -= v[i];
            x += v[i];
            i++;
            f = true;
        }
        
        if(i <= j && j >= 0 && t > 0 && v[j] <= x){
            t--;
            x = 0;
            v[j] = 0;
            j--;
            f = true;
        }

        if(!f){
            break;
        }
        if(i > j){
            break;
        }
    }
    
    return j < i;
}

void solve(){

    ll n; cin >> n;

    vll v(n);
    rep(i, n) cin >> v[i];

    ll lo = 1;
    ll sum = 0;

    srt(v);

    for(ll i=0; i<n; i++) sum += v[i];

    ll hi = sum;
    ll ans = -1;

    while(lo <= hi){
        ll mid = (lo + hi)/2;

        if(isValid(v, mid)){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
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
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*     The code finishes, I hope it gets Accepted      */