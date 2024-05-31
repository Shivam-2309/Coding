#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
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
    vector<ll> ans(7, 0);
    set<ll> used;

    vector<ll> v;
    v.pb(4);
    v.pb(8);
    v.pb(15);
    v.pb(16);
    v.pb(23);
    v.pb(42);

    map<ll, pair<ll, ll>> mp;

    for(ll i=0; i<6; i++){
        for(ll j=i+1; j<6;j++){
            mp[v[i]*v[j]] = {v[i], v[j]};
        }
    }

    // for(auto i : mp){
    //     ll num = i.first;
    //     pair<ll,ll> p = i.second;

    //     cout << num << " -> " << p.first << " " << p.second << endl;
    // }

    // cout << mp.size() << endl;

    // query 1
    cout << "? " << 1 << " " << 1 << endl;
    cout << flush;
    ll num; cin >> num;

    for(ll i=0; i<6; i++){
        if(v[i]*v[i] == num){
            ans[1] = v[i];
            break;
        }
    }

    // query 2
    cout << "? " << 2 << " " << 3 << endl;
    cout << flush;
    ll num1; cin >> num1;
    cout << "? " << 3 << " " << 4 << endl;
    ll num2; cin >> num2;
    cout << flush;
    cout << "? " << 4 << " " << 5 << endl;
    cout << flush;
    ll num3; cin >> num3;

    pair<ll, ll> p1 = mp[num1];
    pair<ll, ll> p2 = mp[num2];
    pair<ll, ll> p3 = mp[num3];

    // for p1 and p2
    if(p1.first == p2.first){
        ans[2] = p1.second;
        ans[3] = p1.first;
        ans[4] = p2.second;
    }
    else if(p1.first == p2.second){
        ans[2] = p1.second;
        ans[3] = p1.first;
        ans[4] = p2.first;
    }
    else if(p1.second == p2.first){
        ans[2] = p1.first;
        ans[3] = p1.second;
        ans[4] = p2.second;
    }
    else{
        ans[2] = p1.first;
        ans[3] = p1.second;
        ans[4] = p2.first;
    }

    if(p2.first == p3.first){
        ans[3] = p2.second;
        ans[4] = p2.first;
        ans[5] = p3.second;
    }
    else if(p2.first == p3.second){
        ans[3] = p2.second;
        ans[4] = p2.first;
        ans[5] = p3.first;
    }
    else if(p2.second == p3.first){
        ans[3] = p2.first;
        ans[4] = p2.second;
        ans[5] = p3.second;
    }
    else{
        ans[3] = p2.first;
        ans[4] = p2.second;
        ans[5] = p3.first;
    }

    set<ll> st;
    for(ll i=1; i<=5; i++){
        st.insert(ans[i]);
    }

    for(ll i=0; i<6; i++){
        if(st.find(v[i]) == st.end()){
            ans[6] = v[i];
            break;
        }
    }

    cout << "! ";
    for(ll i=1; i<=6; i++){
        cout << ans[i] << " ";
    }cout << flush;

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