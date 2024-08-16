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
                    cout << " ]" << endl; \
                } while(0)
#define print2d(v) do { \
                    cout << "vect-- starts" << endl; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "[" << " "; \
                        for (int j = 0; j < v[i].size(); j++) { \
                            cout << v[i][j] << " "; \
                        } \
                        cout << "]" << endl; \
                    } \
                    cout << "vect-- ends" << endl; \
                } while(0)
#define printmap(m) do { \
                    cout << "map-- starts" << endl; \
                    for (auto it = m.begin(); it != m.end(); ++it) { \
                        cout << it->first << " -> " << it->second << endl; \
                    } \
                    cout << "map-- ends" << endl; \
                } while(0)
 
#define printpp(v) do { \
                    cout << "vect--" << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "(" << v[i].first << ", " << v[i].second << ") "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#define print2d(v)
#define printmap(m)
#define printpp(v)
#endif

#define vll vector<ll>
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end());
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < n; i++)
const ll mod7 = 1e9 + 7;
void solve() {
    ll l, r;
    cin >> l >> r;

    vll v(r - l + 1);
    rep(i, r - l + 1) cin >> v[i];
    
    ll tot = (r - l + 1);
    ll l_copy = l - 1;
    ll sumNeeded = (r * (r + 1)) / 2;
    // debug(sumNeeded);
    vll sum1(32, 0);
    vll sum0(32, 0);

    for (ll i = 0; i < (r - l + 1); i++) {
        ll num = v[i];
        for (ll j = 0; j < 32; j++) {
            if (num & (1 << j)) {
                sum1[j]++;
            }
            else{
                sum0[j]++;
            }
        }
    }

    // print(sum1);
    // print(sum0);

    for(ll i = 0; i < (r - l + 1); i++){
        ll possAns = v[i];
        ll totSum = 0;

        for(ll j = 0; j < 32; j++){
            if(possAns & (1 << j)){
                totSum += (sum0[j] * (1 << j));
            }
            else{
                totSum += (sum1[j] * (1 << j));
            }
        }

        // debug(totSum);

        if(totSum == sumNeeded) {
            cout << possAns << endl;
            return;
        }
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