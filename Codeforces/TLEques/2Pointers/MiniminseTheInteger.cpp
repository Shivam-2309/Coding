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
    string s; cin >> s;
    ll len = s.length();

    vll v;
    for(ll i = 0; i < len; i++) v.push_back(s[i] - '0');

    // Deque + Greedy + 2 Pointer
    deque<ll> even;
    deque<ll> odd;

    for(ll i = 0; i < len; i++){
        if(v[i] % 2 == 0) even.push_back(v[i]);
        else odd.push_back(v[i]);
    }
    vll ans;
    while(!even.empty() && !odd.empty()){
        if(even.front() > odd.front()){
            ans.push_back(odd.front());
            odd.pop_front();
        }
        else{
            ans.push_back(even.front());
            even.pop_front();
        }
    }

    while(!even.empty()){
        ans.push_back(even.front());
        even.pop_front();
    }
    while(!odd.empty()){
        ans.push_back(odd.front());
        odd.pop_front();
    }

    for(auto it : ans) cout << it;
    cout << endl;
}

int main(){
    fast_io
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
