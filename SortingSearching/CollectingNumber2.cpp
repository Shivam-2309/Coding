/*      Jai Shree Ram      */
/*      Code Snippet of Shivam Kapoor      */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end());
#define endl '\n'
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
const int NUM = 2e5 + 7;
const ll INF = 1e18 + 5;
bool sieve[NUM];
void sieveOfEratosthenes() {
    memset(sieve, true, sizeof(sieve));
    sieve[1] = false;
    sieve[0] = false; 
    for (ll p = 2; p * p <= NUM; p++) {
        if (sieve[p]) {
            for (ll i = p * p; i <= NUM; i += p)
                sieve[i] = false;
        }
    }
}
// ll dp[NUM];
ll collectingNumbers1(ll n, vector<ll> &v){
    ll cnt = 0;
    unordered_set<ll> st;
    
    for(ll i=0; i<n; i++){
        if(st.find(v[i] - 1) != st.end()){
            st.insert(v[i]);
        }
        else{
            cnt++;
            st.insert(v[i]);
        }
    }
    return cnt;
}
void solve(){
    ll n, q;
    cin >> n >> q;

    vector<ll> v(n);
    for(ll i=0; i<n; i++) cin >> v[i];

    ll ans = collectingNumbers1(n, v);

    while(q--){
        ll a, b;
        cin >> a >> b;

        if(v[a-1] == v[b-1] + 1){
            cnt--;
            swap(v[a-1], v[b-1]);
            cout << cnt << endl;
        }
        else if(v[a-1] + 1 == v[b-1]){
            cnt++;
            swap(v[a-1], v[b-1]);
            cout << cnt << endl;
        }
    }
}
// clear all data structures between test cases
// handle all corner cases
// confusing between n and m , i and j?
// uninitialized variables?
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