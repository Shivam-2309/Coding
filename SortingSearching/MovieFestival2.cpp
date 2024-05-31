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
bool cmp(const pair<ll, ll> &a, const pair<ll, ll> &b) {
    return a.second < b.second;
}

void solve() {
    ll n, k;
    cin >> n >> k;

    vector<pair<ll, ll>> v(n);
    for (ll i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;

        v[i] = {a, b};
    }

    sort(v.begin(), v.end(), cmp);

    // cnt is basically the number of movies which i cannot see
    // Sort the movies on the basis of their end timings
    ll cnt = 0;
    // Use a set to keep track of current movies and their availabilty
    set<pair<ll, ll>> available;

    for(ll i=0; i<n; i++){
        // If the size of the set currently is 0, then i can comfortably say that, i can insert current ending index
        // We have multiplied by -1 because ->
        // say i have 2 3 4 as the current ending time
        // if i get now 5 as the starting time of new movie then it would not be possible for me to determine if there is any element just smaller than 
        // 5 in the set, to do this, i have multiplied the number by -1 coz now, the set would have -4 -3 -2 and if -5 comes it would now have -4 as the lower_bound
        // In this wat i can find whther a new element can be added or not
        if(available.size() == 0){
            available.insert({(v[i].second)*(-1), i});
        } // If it is not zero sized then try to find the possible position for that new element
        else{
            auto newPos = available.lower_bound({v[i].first*-1, -1});
            if(newPos != available.end()){ // If you find an element which has already finsished before the starting of the current movie, replace it with that element
                available.erase(newPos);
                available.insert({(v[i].second)*(-1), i});
            } // If all the movies are curretnly running only but you have more people to see the movie, then simply add
            else if(newPos == available.end() && available.size() < k){
                available.insert({(v[i].second)*(-1), i});
            } // Else there is no way to see that movie
            else{
                cnt++;
            }
        }
    }

    cout << n - cnt << endl;
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