#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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

ll dfs(ll node, vector<ll> adj[], ll curr, ll par, vector<pair<ll, ll>> &range, map<pair<ll, ll>, ll> &mp) {
    if(mp.find({node, curr}) != mp.end()) return mp[{node, curr}];
    ll ans = 0; 

    // cout << "INSIDE -> " << node << endl;
    
    for(auto &child : adj[node]) {
        // debug(child);
        if(child == par) continue;
        ll rangeLeft = range[child].first;
        ll rangeRight = range[child].second;

        ll val1 = abs(rangeLeft - (curr == 0 ? range[node].first : range[node].second)) + dfs(child, adj, 0, node, range, mp);
        ll val2 = abs(rangeRight - (curr == 0 ? range[node].first : range[node].second)) + dfs(child, adj, 1, node, range, mp);

        ans += max(val1, val2);
    }

    // cout << "EXITING -> " << node << endl;

    return mp[{node, curr}] = ans;
}

void solve() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> range(n + 1);
    for(ll i = 1; i <= n; i++) {
        ll l, r;
        cin >> l >> r;
        range[i] = {l, r};
    }

    vector<ll> adj[n + 1];
    ll edges = n - 1;
    for(ll i = 1; i <= edges; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

        // cout << "EDGE BETWEEN -> " << u << " " << v << endl;
    }

    // for(auto it : adj){
        // print(it);
    // }

    ll start1 = range[1].first;
    ll start2 = range[1].second;

    // debug(start1);
    // debug(start2);

    map<pair<ll, ll>, ll> mp;

    ll ans1 = dfs(1, adj, 0, -1, range, mp);
    ll ans2 = dfs(1, adj, 1, -1, range, mp);

    cout << max(ans1, ans2) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
