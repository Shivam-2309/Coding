#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// using namespace std;
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
template <typename T> using pbds = tree<T, null_type,
less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/* find_by_order(K): Returns an iterator to the Kth largest element (counting from zero) */
/* order_of_key (K): Returns the number of items that are strictly smaller than K */
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
#define MOD 1000000007
ll lcm(ll a, ll b)
{
    return a * b / __gcd(a, b);
}
// binary modular exponentiation
ll binpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    if (b & 1)
        return res * res * a;
    else
        return res * res;
}
ll binpowmod(ll a, ll b, ll m=MOD)
{
    a %= m;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
ll mminvprime(ll a, ll b)
{ // gives modulo inverse of a wrt b where b is prime
    return binpowmod(a, b - 2, b);
}
ll mod_add(ll a, ll b, ll m=MOD)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m=MOD)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m=MOD)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
ll mod_div(ll a, ll b, ll m=MOD)
{
    a = a % m;
    b = b % m;
    return (mod_mul(a, mminvprime(b, m), m) + m) % m;
} // only for prime m
// ll dp[NUM];
void solve(){
    ll n, k;
    cin >> n >> k;

    vll v(n);
    rep(i, n) cin >> v[i];

    if(k == 1){
        for(ll i=1; i<=n; i++){
            cout << 0 << " ";
        }
        return;
    }

    if(k == 2){
        for(ll i=0; i<n-1; i++){
            ll mini = min(v[i], v[i+1]);
            ll cost = abs(v[i] - mini) + abs(v[i+1] - mini);

            cout << cost << " ";
        }cout << endl;
        return;
    }

    // My left set always contains the answer
    set<pair<ll, ll>> leftSet;
    set<pair<ll, ll>> rightSet;

    vector<pair<ll, ll>> arr;
    for(ll i=0; i<k; i++){
        arr.push_back({v[i], i});
    }

    sort(arr.begin(), arr.end());

    ll leftSum = 0;
    ll rightSum = 0;

    for(ll i=0; i<(k/2 + k%2); i++){
        pair<ll, ll> p = arr[i];
        leftSum += (p.first);
        leftSet.insert(arr[i]);
    }
    for(ll i=(k/2 + k%2); i<k; i++){
        pair<ll, ll> p = arr[i];
        rightSum += (p.first);
        rightSet.insert(arr[i]);
    }

    ll i = 0;
    ll j = k-1;

    vll ans;

    while(j < n){
        ll median = leftSet.rbegin() -> first;
        ll cost = median;
        cost = cost*(leftSet.size() - rightSet.size());
        cost += (rightSum - leftSum);
        
        ans.push_back(cost);
        // Remove the ith element
        if(leftSet.count({v[i], i})){
            leftSet.erase({v[i], i});
            leftSum -= v[i];
        }
        else{
            rightSet.erase({v[i], i});
            rightSum -= v[i];
        }
        // Add the jth element
        if(j+1 < n && leftSet.rbegin()->first > v[j+1]){
            leftSet.insert({v[j+1], j+1});
            leftSum += v[j+1];
        }
        else if(j+1 < n){
            rightSet.insert({v[j+1], j+1});
            rightSum += v[j+1];
        }
        // balance the set again
        while(leftSet.size() < (k/2 + k%2)){
            pair<ll, ll> p = *rightSet.begin();
            leftSum += p.first;
            rightSum -= p.first;
            rightSet.erase(p);
            leftSet.insert(p);
        }
        while(leftSet.size() > (k/2 + k%2)){
            pair<ll, ll> p = *leftSet.rbegin();
            leftSum -= p.first;
            rightSum += p.first;
            rightSet.insert(p);
            leftSet.erase(p);
        }

        i++;
        j++;
    }

    for(auto &it: ans){
        cout << it << " ";
    }cout << endl;
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