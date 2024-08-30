// Author : Shivam Kapoor
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x) cerr << #x << " = " << x << endl
#define print(v) cerr << #v << " = [ "; for (auto &el : v) cerr << el << " "; cerr << "]\n";
#define print2d(v) cerr << #v << ":\n"; for (auto &row : v) { cerr << "[ "; for (auto &el : row) cerr << el << " "; cerr << "]\n"; }
#define printmap(m) cerr << #m << ":\n"; for (auto &[key, value] : m) cerr << key << " -> " << value << "\n";
#define printpp(v) cerr << #v << " = [ "; for (auto &[first, second] : v) cerr << "(" << first << ", " << second << ") "; cerr << "]\n";

#define vll vector<ll>
#define rev(v) reverse(all(v))
#define srt(v) sort(all(v))
#define all(v) (v).begin(), (v).end()
#define rep(i, n) for (ll i = 0; i < (n); ++i)

const ll mod7 = 1e9 + 7;
ll isprime[2000000];

void sieve() {
    for(ll i = 0; i < 1e6; i++){
        isprime[i] = 1;
    } 
    isprime[0] = isprime[1] = 0;  

    for (int i = 2; i * i <= 1e6; ++i) {
        if (isprime[i]) {
            for (int j = i * i; j <= 1e6; j += i) {
                isprime[j] = 0;  
            }
        }
    }
}

void solve() {
    ll a, b, k;
    cin >> a >> b >> k;
    ll lo = 1;
    ll hi = b - a + 1;

    ll ans = -1;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        bool f = true;
        ll left = a;
        ll right = a + mid - 1;

        while(right <= b){
            if(isprime[right] - isprime[left - 1] < k){
                f = false;
                break;
            } 
            right++;
            left++;
        }
        if(f){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }

    cout << ans << endl;
}

int main() {
    fast_io
    ll t = 1;
    sieve();
    for(ll i = 1; i <= 1e6; i++){
        isprime[i] += isprime[i - 1];
    }
    while (t--) solve();
    return 0;
}
