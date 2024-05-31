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
// ll dp[1000001];
void solve(){
    string s;
    cin >> s;
    ll n = s.length();
    ll cnt = 0;
    vll v;
    for(ll i=0; i<n; i++){
        if(s[i] == 'o'){
            if(cnt > 0) v.push_back(cnt-1);
            cnt = 0;
        }
        else{
            cnt++;
        }
    }
    if(cnt > 0) v.push_back(cnt-1);
    // print(v);

    if(v.size() == 0) {
        cout << 0 << endl;
        return;
    }

    vector<char> t;
    ll i = 0;

    while(i < n){
        if(s[i] == 'v'){
            t.push_back('w');
            while(s[i] == 'v'){
                i++;
            }
            while(s[i] == 'o'){
                t.push_back('o');
                i++;
            }
        }
        else{
            i++;
        }
    }

    vll pref(v.size(), 0);
    vll suff(v.size(), 0);
    
    pref[0] = v[0];
    suff[v.size()-1] = v[v.size()-1];
    for(ll i=1; i<v.size(); i++){
        pref[i] = pref[i-1] + v[i];
        suff[v.size()-i-1] = suff[v.size()-i] + v[v.size()-i-1];
    }

    // print(t);
    // print(pref);
    // print(suff);
    ll sum = 0;
    cnt = 0;

    for(ll i=0; i<n; i++){
        if(t[i] == 'w') cnt++;
        else{
            // debug(sum);
            sum += (pref[cnt-1]*suff[cnt]);
        }

        if(cnt == pref.size()) break;
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
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*     The code finishes, I hope it gets Accepted      */