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

void solve() {
    string s; 
    cin >> s;
    ll n = s.length();

    for(ll i = 1; i <= n; i++) {
        string t_copy = s.substr(0, i);  
        string t = s.substr(0, i);
        string str = t_copy;
        // print(t);
        while(!str.empty() && t_copy.back() == str.front()) {
            t_copy.pop_back();
            str.erase(str.begin());

            string tt = t_copy + str;
            if (s.find(tt) == string::npos) {
                cout << "YES" << endl;
                cout << t << endl;
                return;
            }
        }
    }

    cout << "NO" << endl;
}


int main() {
    fast_io
    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
