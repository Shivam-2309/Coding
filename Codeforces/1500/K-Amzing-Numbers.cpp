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
    vector<ll> v(n);
    rep(i, n) cin >> v[i];

    map<ll, vll> mp;
    for(ll i=0; i<n; i++){
        mp[v[i]].push_back(i);
    }

    map<ll, ll> mp1;
    map<ll, set<ll>> mp2;

    // reverse map
    for(auto &posVec : mp){
        ll num = posVec.first;
        vll aa = posVec.second;
        ll maxi = 0;

        for(ll i=0; i<aa.size(); i++){
            ll gap = aa[i] - (i > 0 ? aa[i-1] : -1);
            // debug(gap);
            maxi = max(maxi, gap);
        }
        maxi = max(maxi, n - aa[aa.size() - 1]);
        mp1[num] = maxi;
    }

    for(auto it : mp1){
        mp2[it.second].insert(it.first); 
    }

    map<ll, ll> mp3;
    for(auto it : mp2){
        set<ll> t = it.second;
        ll mini = *(t.begin());
        mp3[it.first] = mini;
    }

    for(auto &it : mp3){
        ll val = it.second;
        ll mini = it.first;
    }

    vector<ll> a;
    for(auto it : mp3) a.push_back(it.first);
    srt(a);

    vll ans;

    ll infront = a[0]-1;
    for(ll i=0; i<infront; i++){
        ans.push_back(-1);
    }

    for (ll i = 0; i < a.size(); ++i) {
        ll num = a[i];
        ll times = (i + 1 < a.size() ? a[i + 1] : n + 1) - a[i];

        for (ll j = 0; j < times; ++j) {
            ans.push_back(num);
        }
    }

    ll tillNowMini = 1e9;

    // print(ans);

    for(ll i=0; i<n; i++){
        if(ans[i] == -1) continue;
        ans[i] = min(tillNowMini, mp3[ans[i]]);
        tillNowMini = min(tillNowMini, ans[i]);
        // debug(tillNowMini);
    }

    for(auto xx: ans) cout << xx << " ";
    cout << endl;
    
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