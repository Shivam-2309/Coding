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
    vector<vector<ll>> v(2, vector<ll> (n, 0));

    for(ll i=0; i<n; i++){
        ll val; cin >> val;
        v[0][i] = val;
    }
    for(ll i=0; i<n; i++){
        ll val; cin >> val;
        v[1][i] = val;
    }

    ll score1 = 0;
    ll score2 = 0;

    ll minus = 0;
    ll plus = 0;

    for(ll i=0; i<n; i++){
        ll first = v[0][i];
        ll second = v[1][i];

        if(first == -1 && second == -1){
            minus++;
        }
        else if(first == 1 && second == 1){
            plus++;
        }
        else{
            if(first > second){
                score1 += first;
            }
            else {
                score2 += second;
            }
        }
    }

    while(plus){
        if(score1 > score2) score2++;
        else score1++;

        plus--;
    }

    while(minus){
        if(score1 > score2) score1--;
        else score2--;

        minus--;
    }

    cout << min(score1, score2) << endl;
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