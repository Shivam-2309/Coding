#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
/* find_by_order(K): Returns an iterator to the Kth largest element (counting from zero) */
/* order_of_key (K): Returns the number of items that are strictly smaller than K */
#define ll long long

void myerase(ordered_set &t, int v)
{
    int rank = t.order_of_key(v);                     // Number of elements that are less than v in t
    ordered_set::iterator it = t.find_by_order(rank); // Iterator that points to the (rank+1)th element in t
    if (it != t.end() && *it == v) {
        t.erase(it);
    }
}

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

void solve() {
    ll n, m, k; 
    cin >> n >> m >> k;
    
    vector<vector<ll>> v(n, vector<ll>(m));
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    vll position(k);
    for(ll i = 0; i < k; i++) 
        cin >> position[i];
    
    map<ll, ordered_set> mp;
    
    for(ll j = 0; j < m; j++) {
        for(ll i = 0; i < n; i++) {
            if(v[i][j] != 2) 
                mp[j].insert(i);
        }
    }

    for(ll i = 0; i < k; i++) {
        ll pos = position[i];
        pos--;
        ll currRow = 0;
        while(true) {
            ordered_set& st = mp[pos];
            // debug(pos);
            ll skip = st.order_of_key(currRow);
            if(skip == st.size()) {
                cout << pos + 1 << " ";
                break;
            }
            auto it = st.find_by_order(skip);
            currRow = *it;
            myerase(st, *it);
            if(v[currRow][pos] == 1) 
                pos++;
            else 
                pos--;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
