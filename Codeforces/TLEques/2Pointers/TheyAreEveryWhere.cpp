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
    string s;
    cin >> s;
    map<char, ll> mp1;
    for(auto &poke : s) mp1[poke]++;

    ll numPokemons = mp1.size();
    // debug(numPokemons);
    map<char, ll> mp;
    ll ans = LLONG_MAX;

    for(ll i = 0, j = 0; i < n; i++){
        mp[s[i]]++;
        bool f = false;
        while(j <= i && mp.size() == numPokemons){
            mp[s[j]]--;
            if(mp[s[j]] == 0) mp.erase(s[j]);
            j++;
            f = true;
        }
        if(f){
            j--;
            mp[s[j]]++;
        }
        if(mp.size() == numPokemons) ans = min(ans, i - j + 1);
    }

    cout << (ans == LLONG_MAX ? -1 : ans) << endl;
}

int main(){
    fast_io
    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
