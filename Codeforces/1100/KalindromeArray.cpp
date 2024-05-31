#include<bits/stdc++.h>
using namespace std;
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
    ll n; cin >> n;
    vll v(n);
    rep(i, n) cin >> v[i];

    vll temp;
    for(ll i=0; i<n; i++){
        temp.push_back(v[i]);
    }
    rev(temp);

    if(temp == v){
        cout << "YES" << endl;
        return;
    }
    
    // Else there are only two possible cases

    ll i = 0;
    ll j = n-1;

    while(i < j){
        if(v[i] == v[j]){
            i++;
            j--;
            continue;
        }
        break;
    }

    ll val1 = v[i];
    ll val2 = v[j];

    ll ptr1 = i+1;
    ll ptr2 = j;

    bool f1 = true;

    while(ptr1 < ptr2){
        if(v[ptr1] == v[ptr2]){
            ptr1++;
            ptr2--;
        }
        else if(v[ptr1] == val1){
            ptr1++;
        }
        else if(v[ptr2] == val1){
            ptr2--;
        }
        else{
            f1 = false;
            break;
        }
    }

    if(f1){
        cout << "YES" << endl;
        return;
    }

    bool f2 = true;
    ptr2 = j-1;
    ptr1 = i; 

    while(ptr1 < ptr2){
        if(v[ptr1] == v[ptr2]){
            ptr1++;
            ptr2--;
        }
        else if(v[ptr1] == val2){
            ptr1++;
        }
        else if(v[ptr2] == val2){
            ptr2--;
        }
        else{
            f2 = false;
            break;
        }
    }

    if(f2){
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;
}
// Read the question again
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // sieveOfEratosthenes()
    // memset(dp, -1, sizeof(dp));
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*     The code finishes, I hope it gets Accepted      */