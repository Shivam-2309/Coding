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
    ll n, m, k; cin >> n >> m >> k;
    string s; cin >> s;

    if(m >= n+1){
        cout << "YES" << endl;
        return;
    }

    vll logPositions;
    logPositions.push_back(0);
    for(ll i=0; i<n; i++){
        if(s[i] == 'L') logPositions.push_back(i+1);
    }
    logPositions.push_back(n+1);

    set<ll> st;
    for(ll i=0; i<n; i++){
        if(s[i] == 'C') st.insert(i);
    }

    print(logPositions);
    // for(auto it : st) cout << it << " ";
    // cout << endl;

    for(int i=1; i<logPositions.size(); i++){
        ll diff = logPositions[i] - logPositions[i-1];

        if(diff > m){
            debug(i);
            ll start = logPositions[i-1]-1;
            debug(start);
            ll end = logPositions[i]-1;
            debug(end);
            ll last_pos_croc = -1;
            for(ll idx = start+1; idx < end; idx++){
                if(st.find(idx) != st.end()){
                    last_pos_croc = idx;
                }
            }
            debug(last_pos_croc);
            if(last_pos_croc == -1){
                k -= (diff - m);
                if(k < 0){
                    cout << "NO" << endl;
                    return;
                }
            }
            else{
                ll to_jump = last_pos_croc+1;
                if(to_jump - start > m){
                    cout << "NO" << endl;
                    return;
                }
                k -= (end - (m + start));
                if(k < 0){
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }

    cout << "YES" << endl;
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