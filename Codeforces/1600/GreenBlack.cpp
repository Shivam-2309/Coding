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

void solve(){
    ll n, k, a, b; cin >> n >> k >> a >> b;
    if(b > a) swap(a, b);

    vll v;
    ll a_copy = a;
    ll b_copy = b;
    for(ll i = 0; i < min(k, a_copy); i++){
        v.push_back(0);
        a--;
    }
    ll used = 0;
    while(a > 0){
        v.push_back(1);
        b--;
        used++;
        ll k_copy = k;
        while(a > 0 && k_copy > 0){
            a--;
            k_copy--;
            v.push_back(0);
        }
        if(b == 0) break;
    }

    if(b == 0){
        if(a > k){
            cout << "NO" << endl;
            return;
        }
    }

    ll left = b_copy - used;
    if(left > 2*(k - 1)){
        cout << "NO" << endl;
        return;
    }

    print(v);
}

int main(){
    fast_io
    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
