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

ll rangeBitwiseAnd(ll left, ll right) {
    if(left == right) return left;
    for(ll i = 63; i >= 0; i--){
        if(((left & (1LL << i)) == 0) && (right & (1LL << i))){
            right = right & (~((1LL << (i + 1)) - 1));
            return right;
        }
    }
    return right;
}

void solve() {
    ll n, x;
    cin >> n >> x;

    // debug(n);
    // debug(x);

    ll lo = n;
    ll hi = (1LL << 61);
    ll ans = (1LL << 61);

    // debug(lo);
    // debug(hi);

    while(lo <= hi){
        // cout << "CHECK" << endl;
        ll mid = ((lo + hi) / 2);
        ll midAns = rangeBitwiseAnd(n, mid);
        // debug(midAns);
        if(midAns <= x){
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
        if(midAns == x) ans = min(ans, mid);
    }

    if(ans != (1LL << 61)) cout << ans << endl;
    else cout << -1 << endl;
}


int main(){
    fast_io
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
