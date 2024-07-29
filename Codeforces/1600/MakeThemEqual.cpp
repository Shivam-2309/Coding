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
#define vll vector<ll>
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end());
#define rep(i, n) for (ll i = 0; i < n; i++)
const ll mod7 = 1e9 + 7;

ll maxReward(ll k, vector<ll>& work, vector<ll>& reward, ll n) {
    k = min(k, 12 * n);
    vector<ll> dp(k + 1, 0);

    for (ll i = 0; i < n; i++) {
        for (ll w = k; w >= work[i]; w--) {
            dp[w] = max(dp[w], reward[i] + dp[w - work[i]]);
        }
    }

    return dp[k];
}

void solve(){
    ll n, k; cin >> n >> k;

    vll b(n);
    rep(i, n) cin >> b[i];
    vll coins(n);
    rep(i, n) cin >> coins[i];

    set<ll> st;
    ll sz = 0;
    queue<ll> q;
    q.push(1);
    vector<ll> dp(1001, 1);

    while(!q.empty()){
        ll size = q.size();
        for(ll i=0; i<size; i++){
            ll node = q.front();
            q.pop();

            if(st.find(node) != st.end()) continue;

            st.insert(node);
            dp[node] = sz;
            for(ll j = 1; j <= node; j++){
                if((node + node/j <= 1000) && (st.find(node + node/j) == st.end())) q.push(node + node/j);
            }
        }
        sz++;
    }

    vector<ll> work;
    for(ll i=0; i<n; i++){
        work.push_back(dp[b[i]]);
    }

    // print(coins);
    // print(work);

    cout << maxReward(k, work, coins, n) << endl;
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