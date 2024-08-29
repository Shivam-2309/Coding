// Author : Shivam Kapoor
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x) cerr << #x << " = " << x << endl
#define print(v) cerr << #v << " = [ "; for (auto &el : v) cerr << el << " "; cerr << "]\n";
#define print2d(v) cerr << #v << ":\n"; for (auto &row : v) { cerr << "[ "; for (auto &el : row) cerr << el << " "; cerr << "]\n"; }
#define printmap(m) cerr << #m << ":\n"; for (auto &[key, value] : m) cerr << key << " -> " << value << "\n";
#define printpp(v) cerr << #v << " = [ "; for (auto &[first, second] : v) cerr << "(" << first << ", " << second << ") "; cerr << "]\n";

#define vll vector<ll>
#define rev(v) reverse(all(v))
#define srt(v) sort(all(v))
#define all(v) (v).begin(), (v).end()
#define rep(i, n) for (ll i = 0; i < (n); ++i)

const ll mod7 = 1e9 + 7;

void solve(){
    ll n; cin >> n;
    vll v(n + 1);
    for(ll i = 1; i <= n; i++) cin >> v[i];

    vector<ll> indegree(n + 1, 0);
    for(ll i = 0; i < n - 1; i++){
        ll u, v;
        cin >> u >> v;

        indegree[u]++;
        indegree[v]++;
    }

    vector<pair<ll, ll>> a;
    for(ll i = 1; i <= n; i++){
        a.push_back({v[i], indegree[i]});
    }

    // print(indegree);

    vector<ll> ans;
    priority_queue<pair<ll ,ll>> pq;
    for(auto &it : a){
        if(it.second > 1) pq.push(it);
    }
    ll currAns = 0;
    for(auto &it : v) currAns += it;
    ans.push_back(currAns);
    for(ll i = 2; i < n; i++){
        ll t = pq.top().first;
        ll times = pq.top().second;
        pq.pop();

        times--;
        currAns += t;
        ans.push_back(currAns);
        if(times != 1) pq.push({t, times});
        if(pq.size() == 0) break;
    }

    while(ans.size() < n - 1) ans.push_back(ans.back());

    for(auto &it : ans) cout << it << " ";
    cout << endl;
}

int main(){
    fast_io
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
