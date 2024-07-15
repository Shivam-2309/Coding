#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;
/* find_by_order(K): Returns an iterator to the Kth largest element (counting from zero) */
/* order_of_key (K): Returns the number of items that are strictly smaller than K */
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

    vector<vector<ll>> ranges(n);

    for(ll i=0; i<n; i++){
        ll l, r; cin >> l >> r;
        ranges[i] = {l, r, i};
    }

    auto cmp = [&](vector<ll> &a, vector<ll> &b) {
        if (a[0] != b[0]) {
            return a[0] < b[0];
        } else {
            return a[1] > b[1];
        }
    };

    // cout << "CHECK" << endl;

    sort(ranges.begin(), ranges.end(), cmp);
    indexed_set st1;
    for (ll i = 0; i < n; i++) {
        st1.insert({ranges[i][1], i});
    }
    
    vector<ll> contains(n, 0);
    for (ll i = 0; i < n; i++) {
        st1.erase({ranges[i][1], i});
        ll numContained = st1.order_of_key({ranges[i][1] + 1, -1});
        contains[ranges[i][2]] = numContained;
    }

    // print(contains);

    vector<ll> contained(n, 0);
    indexed_multiset st;

    for(ll i=0; i<n; i++){
        ll end = ranges[i][1];
        ll num_of_less_elements = st.order_of_key(end);
        if(num_of_less_elements == st.size()){
            st.insert(end);
        }
        else{
            contained[ranges[i][2]] = st.size() - num_of_less_elements;
            st.insert(end);
        }
    }

    for(auto it : contains){
        cout << it << " ";
    }
    cout << endl;
    for(auto it : contained){
        cout << it << " ";
    }cout << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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