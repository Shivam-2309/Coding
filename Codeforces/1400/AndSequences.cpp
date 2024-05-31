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

ll fact(ll n){
    ll ans = 1;
    for(ll i=1; i<=n; i++){
        ans *= i;
    }
    return ans;
}

void solve(){
    // I can definitely say that, the first and the last element must be equal
    // Also it is very easy to conclude that, the value of the first and last must be always equal to the minimum element only
    // Reason is by Mathematical Contradiction ->

    // let say the minmum element lies anywhere between the sequence.
    // This means that the value of and is always -> a1
    // but if say ai < a1, this would ensure that AND of a1 a2 ---- ai also becomes less than a1
    // This would contradict the statement for a good subsequence.
    // This ensures that, the first element must be the minimum element, and other must not be able to make it even smaller
    // Or I can say that the first and last elements must be the minimum element and the all others must be a super mask of the first and last element(both begin same).
    ll n; cin >> n;
    vll v(n);
    rep(i, n) cin >> v[i];

    ll mini = *min_element(all(v));

    ll cnt = 0;
    for(auto number : v){
        if(number == mini){
            cnt++;
        }
        if((number&mini) < (mini)){
            cout << 0 << endl;
            return;
        }
    }

    // Simply i have the two numbers at the first and at the last, 
    // Choose 2 out of the cnt
    if(cnt < 2){
        cout << 0 << endl;
        return;
    }

    ll ans = cnt*(cnt-1);
    for(ll prod = 1;  prod <= (n-2); prod++){
        ans = ((1ll%mod7)*(prod%mod7)*(ans%mod7))%mod7;
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