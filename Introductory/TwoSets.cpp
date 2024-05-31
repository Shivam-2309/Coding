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
void solve(){
    ll n;
    cin >> n;

    ll sum = ((n+1)*(n))/2;
    if(sum % 2 == 1){
        cout << "NO" << endl;
        return;
    }
    ll target = sum/2;

    set<ll> st1;
    set<ll> st2;

    ll num = n;
    while(target > 0){
        if(target >= num){
            target -= num;
            st1.insert(num);
            num--;
        }
        else{
            st1.insert(target);
            break;
        }
    }

    for(ll i=1; i<=n; i++){
        if(st1.find(i) == st1.end()){
            st2.insert(i);
        }
    }

    cout << "YES" << endl;
    cout << st1.size() << endl;
    for(auto &it: st1) cout << it << " ";
    cout << endl;
    cout << st2.size() << endl;
    for(auto &it: st2) cout << it << " ";

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