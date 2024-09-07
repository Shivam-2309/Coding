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

bool inValid(vll &curr, vll &freq){
    for(ll i = 0; i < 26; i++){
        if(curr[i] > freq[i]) return false;
    }
    return true;
}

void solve(){
    ll n, m; cin >> n >> m;
    string s1; cin >> s1;
    string s2; cin >> s2;

    vector<ll> freq(26, 0);
    for(ll i = 0; i < m; i++){
        freq[s2[i] - 'a']++;
    }

    vector<ll> curr(26, 0);
    ll cnt = 0;
    
    for(ll i = 0, j = 0; i < n; i++){
        curr[s1[i] - 'a']++;

        while(j <= i && !inValid(curr, freq)){
            curr[s1[j] - 'a']--;
            j++;
        }

        cnt += (i - j + 1);
    }

    cout << cnt << endl;
}

int main(){
    fast_io
    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
