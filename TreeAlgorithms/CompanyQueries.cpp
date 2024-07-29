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

class TreeAncestor {
private:
    vector<vector<ll>> up;
    ll log;
public:
    TreeAncestor(ll n, vector<ll>& parent) {
        log = ceil(log2(1e9));
        up.resize(n, vector<ll> (log+1, -1));
        // Binary lifting
        // The 2^0th ancestor is the parent itself
        for(ll i=0; i<n; i++){
            up[i][0] = parent[i];
        }

        // updating the up vector for each ancestor
        for(ll j = 1; j < log; j++){
            for(ll i = 0; i < n; i++){
                if(up[i][j-1] != -1){
                    up[i][j] = up[up[i][j-1]][j-1];
                }
                else{
                    up[i][j] = -1;
                }
            }
        }
    }
    
    ll getKthAncestor(ll node, ll k) {
        if(k == 1) return up[node][0];

		ll ans = node;
		for(ll j = 0; j <= log; j++) 
		{
			if(k & (1 << j))
			{
				ans = up[ans][j];
				if(ans==-1) break;
			}
		}
		return ans;
    }
};

void solve(){
    ll n; cin >> n;
    ll q; cin >> q;

    vector<ll> parent(n+1, -1);
    parent[1] = -1;
    vll v(n-1);
    rep(i, n-1) cin >> v[i];
    for(ll i=0; i<n-1; i++){
        parent[i+2] = v[i];
    }
    TreeAncestor obj(n+1, parent);

    while(q--){
        ll u, k; cin >> u >> k;
        cout << obj.getKthAncestor(u, k) << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.precision(15);
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}