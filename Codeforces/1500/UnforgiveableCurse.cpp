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
    ll n, k; cin >> n >> k;
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;

    string s1_copy = s1;
    string s2_copy = s2;
    
    srt(s1_copy);
    srt(s2_copy);

    if(s1_copy != s2_copy){
        cout << "NO" << endl;
        return;
    }

    if(n >= 2*k){
        cout << "YES" << endl;
        return;
    }

    // 1 1+k k+2 2 k+3 3 k+4 4 k+5 5 k+6 6 k+7 7
    vll v;
    map<ll, ll> mp;
    v.push_back(0);
    mp[0]++;
    if(k < n){
        v.push_back(k);
        mp[k]++;
    }
    for(ll i = 1; i <= k; i++){
        if(i + k >= n) break;
        v.push_back(i+k);
        v.push_back(i);
        mp[i]++;
        mp[i+k]++;
    }
    for(ll i=0; i<n; i++){
        if(mp.find(i) == mp.end()){
            if(s1[i] != s2[i]){
                cout << "NO" << endl;
                return;
            }
        }
    }

    string str1 = "";
    string str2 = "";
    for(ll i=0; i<v.size(); i++){
        str1.push_back(s1[v[i]]);
        str2.push_back(s2[v[i]]);
    }

    srt(str1);
    srt(str2);

    if(str1 == str2){
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;
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