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
    ll n, k; cin >> n >> k;
    vll a(n);
    rep(i, n) cin >> a[i];
    vll h(n);
    rep(i, n) cin >> h[i];

    // print(a);

    for(ll i = 1; i < n; i++) a[i] += a[i - 1];
    ll maxFruits = 0;
    ll i = 0, j = 0;
    for(; i < n - 1; i++){
        if(h[i] % h[i + 1] == 0){
            while(j <= i && a[i] - (j > 0 ? a[j - 1] : 0) > k){
                j++;
            }
            if(j <= i && a[i] - (j > 0 ? a[j - 1] : 0) <= k) maxFruits = max(maxFruits, i - j + 1);
        }
        else{
            if(j <= i && a[i] - (j > 0 ? a[j - 1] : 0) <= k) maxFruits = max(maxFruits, i - j + 1);
            j = i + 1;
        }
    }
    
    if(j <= i && a[i] - (j > 0 ? a[j - 1] : 0) <= k) maxFruits = max(maxFruits, i - j + 1);

    cout << maxFruits << endl;
}

int main(){
    fast_io
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
