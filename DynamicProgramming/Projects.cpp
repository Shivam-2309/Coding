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

ll f(ll idx, vector<vector<ll>> &jobs, vector<ll> &first, vector<ll> &dp){
    // cout << "CHECK" << endl;
    if(idx == jobs.size()) return 0;

    if(dp[idx] != -1) return dp[idx];

    ll next_index = upper_bound(first.begin(), first.end(), jobs[idx][1]) - first.begin();
    ll take = jobs[idx][2] + f(next_index, jobs, first, dp);
    ll notTake = 0 + f(idx+1, jobs, first, dp);

    return dp[idx] = max(take, notTake);
}

void solve(){
    // This is exactly similar to maximum profit in job scheduling
    ll n; cin >> n;
    vector<vector<ll>> jobs;
    for(ll i=0; i<n; i++){
        ll s, e, profit;
        cin >> s >> e >> profit;
        jobs.push_back({s, e, profit});
    }
    vector<ll> dp(n, -1);

    // sort
    srt(jobs);
    vector<ll> first;
    for(ll i=0; i<n; i++){
        first.push_back(jobs[i][0]);
    }

    cout << f(0, jobs, first, dp) << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.precision(15);
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