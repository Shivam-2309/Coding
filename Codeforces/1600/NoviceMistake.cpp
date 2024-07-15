#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#define print(v) do { \
                    cout << "vect--" << #v << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << v[i] << " "; \
                    } \
                    cout << "]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#endif
#define vll vector<ll>
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end());
#define rep(i, n) for (ll i = 0; i < n; i++)
const ll mod7 = 1e9 + 7;
void solve(){
    ll n; cin >> n;
    string n_string = to_string(n);

    ll n_copy1 = n;
    string len = n_string;

    while(n_string.length() < 6){
        n_string += n_string;
    }

    while(n_string.length() > 6){
        n_string.pop_back();
    }

    vector<string> possAns;
    for(ll i=0; i<n_string.length(); i++){
        possAns.push_back(n_string.substr(0, i+1));
    }

    vector<pair<ll, ll>> ans;

    for(ll i = 0; i < 6; i++){
        for(ll a = 1; a <= 10000; a++){
            ll right = (n_copy1 * a);
            ll num = stoi(possAns[i]);
            ll b = right - num;

            if(b > 0 && (len.length() * a - (i + 1) == b)){
                ans.push_back({a, b});
            }
        }
    }

    cout << ans.size() << endl;
    for(auto it : ans) cout << it.first << " " << it.second << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.precision(15);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}