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

int findNthDigit(int n) {
    // CSES Digit Queries
    long long num_of_digits = 1;
    long long digit_power = 9;

    long long digits_add = 0;

    while(digits_add + (digit_power*num_of_digits) <= n){
        digits_add += (digit_power*num_of_digits);
        num_of_digits++;
        digit_power *= 10;
    }

    long long digits_left = n - digits_add;
    long long base = pow(10, num_of_digits-1) - 1;
    long long num_of_complete = digits_left/num_of_digits;
    base += num_of_complete;
    long long place = digits_left%num_of_digits;
    if(place == 0){
        return base % 10;
    }
    place = num_of_digits - place;
    base++;
    while(place--){
        base /= 10;
    }

    return base%10;
}

void solve(){
    ll n;
    cin >> n;

    cout << findNthDigit(n) << endl;
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