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
bool isPossible(vector<vector<ll>> &want, ll k){
    ll lo = 0;
    ll hi = k - 1;

    ll cnt = 0;
    for (ll i = 0; i < want.size(); i++){
        if (want[i][0] >= hi && want[i][1] >= lo){
            cnt++;
            lo++;
            hi--;
        }
    }

    return cnt >= k;
}

void solve(){
    ll n; 
    cin >> n;
    vector<vector<ll>> want(n, vector<ll>(2));
    for (ll i = 0; i < n; i++){
        cin >> want[i][0] >> want[i][1];
    }

    ll lo = 0;
    ll hi = n;
    ll ans = -1;

    while (lo <= hi){
        ll mid = (lo + hi) / 2;
        if (isPossible(want, mid)){
            ans = mid;
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }

    cout << ans << endl;
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