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
void solve(){
    // Store all the elements based on the increasing value
    // Because it is a power of 2, thus every number if it can be fit can be replaced by some smaller powers of 2
    // This makes it always optimal to use the bigger number first as the smaller ones can be used in some in between later
    // then simply look through, because we need to push in n elements, so make a while look till cnt != n
    // if we find a bigger number which can be fit, increase the count, and reduce the fre of that number
    // if not found this means, that it was not able to fit in the available space, thus needs to have a higher spaceLeft = k space
    // thus increase the height
    // Worst case TC -> O(2*n) when when all the elements have the same size and the vaalue of k is also equal to k

    ll n, k;
    cin >> n >> k;

    vll v(n);
    rep(i, n) cin >> v[i];

    vll freq(20, 0);
    for(ll i=0; i<n; i++){
        freq[log2(v[i])]++;
    }

    ll height = 1;
    ll spaceLeft = k;
    ll cnt = 0;
    while(true){
        bool f = false;
        for(ll sz=19; sz >= 0; sz--){
            if(freq[sz] && ((spaceLeft - (1 << sz)) >= 0)){
                spaceLeft -= (1 << sz);
                freq[sz]--;
                f = true;
                cnt++;
                break;
            }
        }

        if(!f){
            spaceLeft = k;
            height++;
        }

        if(cnt == n) break;
    }

    cout << height << endl;
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