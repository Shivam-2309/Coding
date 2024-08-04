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
    string s; cin >> s;
    string t; cin >> t;

    ll i = s.length() - 1;
    ll j = t.length() - 1;
    stack<char> st;
    while(i >= 0 && j >= 0){
        if(s[i] == t[j]){
            i--;
            j--;
        }
        else{
            i -= 2;
        }
    }

    // debug(i);
    // debug(j);

    // if((j < 0) && (i%2 == 0)){
    //     cout << "NO" << endl;
    //     return;
    // }
    // if((j < 0) && (i%2 == 1)){
    //     cout << "YES" << endl;
    //     return;
    // }
    if(j < 0){
        cout << "YES" << endl;
        return;
    }

    if(i < 0){
        cout << "NO" << endl;
        return;
    }
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