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

class DSU{
    public:
    vector<int> size, vector<int> par;
    DSU(ll n){
        size.resize(n + 1);
        par.resize(n + 1);
        for(ll i = 0; i < n; i++) par[i] = i;
        for(ll i = 0; i < n; i++) size[i] = 1;
    }
    ll findUPar(ll node){
        if(par[node] == node) return node;
        return par[node] = findUPar(node);
    }

    void unionBySize(ll u, ll v){
        ll par1 = findUPar(u);
        ll par2 = findUPar(v);

        if(par1 == par2) return;
        if(size[par1] > size[par2]){
            size[par1] += size[par2];
        }
        else{
            size[par2] += size[par1];
        }
    }
};

ll totalUnreachablePairs(ll n, vector<vector<ll>> &edges){
    DSU ds(n);
    for(auto edge : edges){
        ll u = edge[0];
        ll v = edge[1];

        ds.unionBySize(u, v);
    }

    vector<ll> sizes;
    for(ll i = 0; i < n; i++){
        if(ds.findUPar(i) == i){
            sizes.push_back(size[i]);
        }
    }

    ll totalUnreachableDoulets = 0;
    for(auto &size : sizes){
        totalUnreachableDoulets += ((n - size) * size) % mod7;
    }

    ans = ans / 2;
    
    return ans;
}


int main(){
    fast_io
    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
