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
    string s; cin >> s;

    ll N = 0;
    ll S = 0;
    ll E = 0;
    ll W = 0;

    for(ll i=0; i<n; i++){
        if(s[i] == 'N') N++;
        if(s[i] == 'S') S++;
        if(s[i] == 'E') E++;
        if(s[i] == 'W') W++;
    }

    ll poss1 = abs(N - S);
    ll poss2 = abs(E - W);

    if(poss1%2==1 || poss2%2==1){
        cout << "NO" << endl;
        return;
    }

    vector<char> ans(n, '*');
    map<char, vll> mp;

    for(ll i=0; i<n; i++){
        mp[s[i]].push_back(i);
    }

    vll south = mp['S'];
    vll north = mp['N'];

    ll sz1 = south.size();
    ll sz2 = north.size();

    ll i = 0;
    ll times1 = 0;
    ll times2 = 0;
    bool f1 = true;
    while(i < sz1 && i < sz2){
        times1++;

        if(f1){
            ans[south[i]] = 'R';
            ans[north[i]] = 'R';

            f1 = !f1;
        }
        else{
            ans[south[i]] = 'H';
            ans[north[i]] = 'H';

            f1 = !f1;
        }

        i++;
    }
    
    bool f = true;
    while(i < sz1){
        if(f){
            ans[south[i]] = 'R';
            f = !f;
        }
        else{
            ans[south[i]] = 'H';
            f = !f;
        }
        times2++;
        i++;
    }
    while(i < sz2){
        if(f){
            ans[north[i]] = 'R';
            f = !f;
        }
        else{
            ans[north[i]] = 'H';
            f = !f;
        }
        i++;
        times2++;
    }

    ll times3 = times1;
    ll times4 = times2;
    // print(ans);

    vll east = mp['E'];
    vll west = mp['W'];

    times1 = 0;
    times2 = 0;

    ll sz3 = east.size();
    ll sz4 = west.size();

    ll j = 0;
    f1 = true;
    while(j < sz3 && j < sz4){
        if(f1){
            ans[east[j]] = 'H';
            ans[west[j]] = 'H';

            f1 = !f1;
        }
        else{
            ans[east[j]] = 'R';
            ans[west[j]] = 'R';

            f1 = !f1;
        }
        times1++;
        j++;
    }
    f = true;
    while(j < sz3){
        if(f){
            ans[east[j]] = 'R';
            f = !f;
        }
        else{
            ans[east[j]] = 'H';
            f = !f;
        }
        times2++;
        j++;
    }
    while(j < sz4){
        if(f){
            ans[west[j]] = 'R';
            f = !f;
        }
        else{
            ans[west[j]] = 'H';
            f = !f;
        }
        times2++;
        j++;
    }

    if(times1 + times3 <= 1 && times2 == 0 && times4 == 0){
        cout << "NO" << endl;
        return;
    }

    for(auto &it : ans) cout << it;
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