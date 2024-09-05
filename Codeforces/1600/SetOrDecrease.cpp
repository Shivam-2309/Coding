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

bool ok(ll times, vll &v, ll k){
    vll pre = v;
    ll n = v.size();
    
    for(ll i = 1; i < n; i++){
        pre[i] += pre[i - 1];
    }

    // print(pre);
    ll t = times;

    ll minSum = 1e18;
    ll curr = 0;
    while(times >= 0 && curr <= (n - 1)){
        ll sum = pre[n - curr - 1] - pre[0];
        sum += (v[0] - times);
        sum += (v[0] - times) * curr;
        times--;
        // if(t == 2) debug(sum);
        curr++;
        minSum = min(minSum, sum);
    }

    return minSum <= k;
}

void solve(){
    ll n, k; cin >> n >> k;
    vll v(n);
    rep(i, n) cin >> v[i];

    ll lo = 0;
    ll ans = -1;
    srt(v);
    ll hi = v[0] + 1000000;

    while(lo <= hi){
        // cout << "CHECK" << endl;
        ll mid = (lo + hi) / 2;
        if(ok(mid, v, k)){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }

    cout << ans << endl;
}

int main(){
    fast_io
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
