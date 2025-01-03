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
const ll mod9 = 998244353;

void solve() {
    ll n;
    cin >> n;
    n++; 
    cout << "THE REQUIRED PATTERN -> " << endl;
    for (ll i = 0; i < n - 1; i++) {
        for (ll j = 0; j < n - i - 2; j++) {
            cout << ' ';
        }
        for (ll j = 1; j <= i + 1; j++) {
            cout << char(j + 'a' - 1);
        }
        ll s = i;
        for (ll j = 0; j < i; j++) {
            cout << char(s + 'a' - 1);
            s--;
        }
        cout << endl;
    }
}


int main(){
    fast_io
    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
