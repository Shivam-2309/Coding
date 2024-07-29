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
    ll n, m; cin >> n >> m;
    vector<vector<ll>> v(2, vector<ll> (n+m+1, -1));
    for(ll i=0; i<n+m+1; i++){
        ll a; cin >> a;
        v[0][i] = a;
    }
    for(ll i=0; i<n+m+1; i++){
        ll b; cin >> b;
        v[1][i] = b;
    }

    ll cntP = 0;
    ll cntT = 0;

    ll skillP = 0;
    ll skillT = 0;

    for(ll i=0; i<n+m+1; i++){
        if(v[0][i] > v[1][i]){
            cntP++;
            skillP += v[0][i];
        }
        else{
            cntT++;
            skillT += v[1][i];
        }
    }

    if(cntP <= n){
        // debug(cntP);
        // debug(cntT);
        ll more = n - cntP;
        ll more_copy1 = more;
        ll more_copy2 = more+1;
        set<ll> check;
        ll more1 = 0;
        ll more2 = 0;

        for(ll i=n+m; i>=0 && more_copy1>0; i--){
            if(v[0][i] < v[1][i]){
                more1 += (v[0][i] - v[1][i]);
                check.insert(i);
                more_copy1--;
            }
        }

        for(ll i=n+m; i>=0 && more_copy2>0; i--){
            if(v[0][i] < v[1][i]){
                more2 += (v[0][i] - v[1][i]);
                more_copy2--;
            }
        }

        // debug(more1);
        // debug(more2);
        // for(auto &it : check) cout << it << " ";
        // cout << endl;

        vector<ll> ans;
        ll scoreP = 0;
        ll scoreT = 0;
        for(ll i=0; i<n+m+1; i++){
            if(v[0][i] > v[1][i]) scoreP += v[0][i];
            else scoreT += v[1][i];
        }

        // debug(scoreP);
        // debug(scoreT);

        for(ll i=0; i<n+m+1; i++){
            if((v[1][i] > v[0][i]) && (check.find(i)==check.end())){
                ans.push_back(scoreP + scoreT + more1);
            }
            else{
                ans.push_back(scoreP + scoreT + more2);
                if(check.find(i) != check.end()){
                    ans[i] += abs(v[1][i] - v[0][i]);
                }
            }

            if(v[0][i] > v[1][i]) ans[i] -= v[0][i];
            else ans[i] -= v[1][i];
        }
        for(auto &it : ans) cout << it << " ";
        cout << endl;
    }
    else{
        ll more = m - cntT;
        ll more_copy1 = more;
        ll more_copy2 = more+1;
        set<ll> check;
        ll more1 = 0;
        ll more2 = 0;

        for(ll i=n+m; i>=0 && more_copy1>0; i--){
            if(v[0][i] > v[1][i]){
                more1 += (v[1][i] - v[0][i]);
                check.insert(i);
                more_copy1--;
            }
        }

        for(ll i=n+m; i>=0 && more_copy2>0; i--){
            if(v[0][i] > v[1][i]){
                more2 += (v[1][i] - v[0][i]);
                more_copy2--;
            }
        }

        vector<ll> ans;
        ll scoreP = 0;
        ll scoreT = 0;
        for(ll i=0; i<n+m+1; i++){
            if(v[0][i] > v[1][i]) scoreP += v[0][i];
            else scoreT += v[1][i];
        }

        for(ll i=0; i<n+m+1; i++){
            if((v[1][i] < v[0][i]) && (check.find(i)==check.end())){
                ans.push_back(scoreP + scoreT + more1);
            }
            else{
                ans.push_back(scoreP + scoreT + more2);
                if(check.find(i) != check.end()){
                    ans[i] += abs(v[1][i] - v[0][i]);
                }
            }

            if(v[0][i] > v[1][i]) ans[i] -= v[0][i];
            else ans[i] -= v[1][i];
        }
        for(auto &it : ans) cout << it << " ";
        cout << endl;
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