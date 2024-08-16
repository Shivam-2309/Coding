#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<string, string> dp;
map<string, ll> done;

string getMin(){
    string s = "z";
    for(ll i = 1; i <= 5001; i++) s.push_back('z');
    return s;
}

string f(string s, ll k) {
    ll len = s.length();
    if (len >= k) return s.substr(0, k);
    if (dp.find(s) != dp.end()) return dp[s];

    string s_copy = s;
    string mini = getMin();  
    string doubled = s + s;
    done[doubled] = 1;
    mini = min(mini, f(doubled, k));
    if(done[s] != 1 && len > 1){  
        done[s] = 1;
        s.pop_back();
        mini = min(mini, f(s, k));
    }

    return dp[s_copy] = mini;
}


void solve() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    string minString = "~";
    for(ll i = 1; i <= min(n, k); i++){
        string str = s.substr(0, i);
        while(str.size() < k){
            str += str;
        }
        while(str.size() > k) str.pop_back();
        minString = min(minString, str);
    }

    cout << minString << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
