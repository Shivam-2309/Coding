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
    ll n = s.length();
    ll ans = 0;

    if((s[0] != s[n-1]) || (s[0] == s[n-1] && s[0] == 'B')){
        // number of A's
        ll numA = 0;
        for(ll i=0; i<n; i++){
            if(s[i] == 'A') numA++;
        }

        cout << numA << endl;
        return;
    }
    else{
        bool f = false;
        for(ll i=1; i<n; i++){
            if(s[i] == s[i-1] && s[i] == 'B'){
                f = true;
                break;
            }
        }

        ll numA = 0;
        for(ll i=0; i<n; i++){
            if(s[i] == 'A') numA++;
        }

        if(f){
            cout << numA << endl;
            return;
        }

        // cout << "CHECK" << endl;

        ll minACnt = n;
        ll cnt = 0;
        for(ll i=0; i<n; i++){
            if(s[i] == 'A'){
                cnt++;
            }
            else{
                minACnt = min(minACnt, cnt);
                cnt = 0;
            }
        }
        minACnt = min(cnt, minACnt);

        cout << numA - minACnt << endl;
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