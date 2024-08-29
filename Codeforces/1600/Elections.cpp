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

    ll num_max_elements = 0;
    v[0] += k;
    ll maxi = *max_element(all(v));
    for(ll i = 0; i < n; i++){
        if(v[i] == maxi) num_max_elements++;
    }

    vll pos;
    for(ll i = 0; i < n; i++){
        if(v[i] == maxi) pos.push_back(i);
    }

    vll ans;
    vll pre = v;
    for(ll i = 1; i < n; i++) pre[i] += pre[i - 1];
    for(ll i = 0; i < n; i++){
        if(v[i] == maxi){
            if(pos[0] == i) ans.push_back(0);
            else ans.push_back(i); 
        }
        else{
            if(pre[i] >= maxi){
                ans.push_back(i);
            }
            else{
                ans.push_back(i + 1);
            }
        }
    }
    for(auto it : ans) cout << it << " ";
    cout << endl;
}

int main(){
    fast_io
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
