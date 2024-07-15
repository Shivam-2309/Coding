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
    string s; cin >> s;

    ll q; cin >> q;

    ll plus = 0;
    ll minus = 0;

    for(ll i=0; i<n; i++){
        if(s[i] == '+') plus++;
        else minus++;
    }

    if(plus == minus){
        for(ll i=0; i<q; i++){
            cout << "YES" << endl;
        }
        return;
    }

    while(q--){
        ll a, b;
        cin >> a >> b;

        if(a == b){
            if(minus == plus){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
            continue;
        }

        
        ll _lcm = lcm(a, b);

        // 3
        ll need1 = _lcm/a;
        // 5
        ll need2 = _lcm/b;

        // 2
        ll gap = abs(plus - minus);
        // 2
        ll gap1 = abs(need2 - need1);

        if((gap % gap1) != 0){
            cout << "NO" << endl;
            continue;
        }

        // debug(a);
        // debug(b);

        // 5
        ll maxi = max(plus, minus);
        // 3
        ll mini = min(plus, minus);

        // 1
        ll numPairs1 = (maxi / max(need1, need2));
        // 1
        ll numPairs2 = (mini / min(need1, need2));

        // debug(numPairs1);
        // debug(numPairs2);
        // debug(gap);

        // 2
        ll totalPairs = min(numPairs1, numPairs2);

        if((totalPairs*gap1) >= gap){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
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