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
    vll v(n);
    rep(i, n) cin >> v[i];

    map<tuple<ll, ll, ll>, map<ll, ll>> mp1;
    map<tuple<ll, ll, ll>, ll> mp2;
    ll cnt = 0;
    
    for(ll j=0; j<n-2; j++){
        ll num1 = v[j];
        ll num2 = v[j+1];
        ll num3 = v[j+2];

        tuple<ll, ll, ll> p1 = {num1, num2, 3};
        tuple<ll, ll, ll> p2 = {num2, num3, 1};
        tuple<ll, ll, ll> p3 = {num1, num3, 2};

        if(mp1.find(p1) != mp1.end()){
            cnt += mp2[p1];
            ll timesSame = mp1[p1][num3];
            cnt -= timesSame;
        }
        
        if(mp1.find(p2) != mp1.end()){
            cnt += mp2[p2];
            ll timesSame = mp1[p2][num1];
            cnt -= timesSame;
        }
        
        if(mp1.find(p3) != mp1.end()){
            cnt += mp2[p3];
            ll timesSame = mp1[p3][num2];
            cnt -= timesSame;
        }

        // updation
        mp1[p1][num3]++;
        mp1[p2][num1]++;
        mp1[p3][num2]++;

        mp2[p1]++;
        mp2[p2]++;
        mp2[p3]++;
    }

    cout << cnt << endl;
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