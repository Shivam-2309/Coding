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

vector<ll> bitRep(ll num) {
    vector<ll> bits(64, 0); 
    for (int i = 0; i < 64; i++) {
        bits[63 - i] = (num >> i) & 1; 
    }
    return bits;
}

void solve(){
    ll b, c, d; cin >> b >> c >> d;
    vector<ll> bitB = bitRep(b);
    vector<ll> bitC = bitRep(c);
    vector<ll> bitD = bitRep(d);

    // print(bitB);
    // print(bitC);
    // print(bitD);

    vector<ll> ans(64, 0);
    for(ll i = 0; i < 64; i++){
        if(bitD[63 - i] == 0){
            if(bitB[63 - i] == 0 && bitC[63 - i] == 0){
                ans[63 - i] = 0;
            }
            else if(bitB[63 - i] == 0 && bitC[63 - i] == 1){
                ans[63 - i] = 0;
            }
            else if(bitB[63 - i] == 1 && bitC[63 - i] == 0){
                cout << -1 << endl;
                return;
            }
            else{
                ans[63 - i] = 1;
            }
        }
        else{
            if(bitB[63 - i] == 0 && bitC[63 - i] == 0){
                ans[63 - i] = 1;
            }
            else if(bitB[63 - i] == 0 && bitC[63 - i] == 1){
                cout << -1 << endl;
                return;
            }
            else if(bitB[63 - i] == 1 && bitC[63 - i] == 0){
                ans[63 - i] = 1;
            }
            else{
                ans[63 - i] = 0;
            }
        }
    }

    rev(ans);

    ll res = 0;
    for(ll i = 0; i < 64; i++){
        if(ans[i]){
            res += (1LL << i);
        }
    }

    cout << res << endl;
}

int main(){
    fast_io
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
