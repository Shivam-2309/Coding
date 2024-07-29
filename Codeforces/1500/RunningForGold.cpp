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
    vector<vector<ll>> v(n, vector<ll> (5));
    for(ll i=0; i<n; i++){
        for(ll j=0; j<5; j++){
            cin >> v[i][j];
        }
    }

    ll possWinner = 0;
    for(ll i = 1; i < n; i++){
        ll cnt = 0;
        for(ll j = 0; j < 5; j++){
            if(v[i][j] < v[possWinner][j]) cnt++;
        }
        if(cnt >= 3) possWinner = i;
    }
    map<ll, ll> mp;
    for(ll j = 0; j < 5; j++){
        for(ll i = 0; i < n; i++){
            if(v[i][j] > v[possWinner][j]) mp[i]++;
        }
    }

    for(auto &it : mp){
        if(it.second < 3){
            cout << -1 << endl;
            return;
        }
    }

    cout << possWinner + 1 << endl;
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