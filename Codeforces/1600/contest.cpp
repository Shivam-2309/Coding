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

void solve(){
    ll n; cin >> n;

    if(n % 2 == 0){
        cout << -1 << endl;
        return;
    }
    else{
        ll curr = 1;
        ll times = n / 2;
        vector<ll> ans1;
        for(ll i = 0; i < times; i++){
            ans1.push_back(curr);
            curr += 2;
        }
        ans1.push_back(n);
        curr = n - 1;
        while(curr > 0){
            ans1.push_back(curr);
            curr -= 2;
        }

        for(ll i = 0; i < n; i++){
            cout << ans1[i] << " ";
        }cout << endl;
    }
}

int main(){
    fast_io
    ll t = 1;
    cin >> t;
    debug(t);
    while (t--) {
        solve();
    }
    return 0;
}
