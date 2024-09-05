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
    vll v(n);
    rep(i, n) cin >> v[i];

    vector<ll> pre(n, 0);
    for(ll i = 1; i < n-1; i++){
        if(v[i] > v[i - 1] && v[i] > v[i + 1]) pre[i] = 1;
    }

    for(ll i = 1; i < n; i++) pre[i] += pre[i - 1];
    // print(pre);

    ll l = 0;
    ll r = k - 1;
    ll maxi = 1;
    ll left = 1;
    bool f = false;
    while(r < n){
        ll sum = pre[r - 1] - pre[l];
        if(sum == 0){

        }
        else{
            if(maxi < sum + 1){
                f = true;
                maxi = sum + 1;
                left = l;
            }
        }
        l++;
        r++;
    }

    if(!f){
        cout << 1 << " " << 1 << endl;
        return;
    }

    cout << maxi << " " << left + 1 << endl;
}

int main(){
    fast_io
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
