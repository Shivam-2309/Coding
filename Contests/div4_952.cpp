#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;
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
#define ll long long
#define vll vector<ll>
#define vp vector<pair<long long, long long>>
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end());
#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
const ll mod7 = 1e9 + 7;
const ll mod9 = 998244353;
ll power(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return res;
}
ll lcm(ll a, ll b)
{
    return a * b / __gcd(a, b);
}
// ll dp[100001];

void dfs1(ll row, ll col, vector<vector<char>> &grid, vector<vector<ll>> &vis, map<pair<ll, ll>, ll> &mp, ll r, ll c, ll &cnt){
    vis[row][col] = 1;
    cnt++;
    mp[{row, col}] = r*grid[0].size() + c + 1;

    ll delRow[] = {1, 0, -1, 0};
    ll delCol[] = {0, 1, 0, -1};

    for(ll i = 0; i < 4; i++){
        ll newRow = row + delRow[i];
        ll newCol = col + delCol[i];

        if((newRow >= 0) && (newRow < grid.size()) && (newCol >= 0) && (newCol < grid[0].size()) && (!vis[newRow][newCol]) && (grid[newRow][newCol] == '#')){
            dfs1(newRow, newCol, grid, vis, mp, r, c, cnt);
        }
    }
}

void solve(){
    ll n, m; cin >> n >> m;

    vector<vector<char>> grid(n, vector<char> (m, '\0'));

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            char ch; cin >> ch;

            grid[i][j] = ch;
        }
    }
    vector<vector<ll>> vis1(n, vector<ll> (m, 0));
    map<pair<ll, ll>, ll> mp1;
    map<ll, ll> mp2;
    // finding the parent for each

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            if((grid[i][j] == '#') && (!vis1[i][j])){
                ll row = i;
                ll col = j;
                ll cnt = 0;
                dfs1(i, j, grid, vis1, mp1, row, col, cnt);    
                mp2[row*grid[0].size() + col + 1] = cnt;   
            }
        }
    }

    ll ans = 0;

    // for rows
    for(ll i = 0; i < n; i++){
        ll cnt = 0;
        set<ll> st;
        for(ll j = 0; j < m; j++){
            if(grid[i][j] == '.'){
                cnt++;
                ll belowRow = i + 1;
                ll aboveRow = i - 1;

                if(belowRow < n && grid[belowRow][j] == '#'){
                    ll parent = mp1[{belowRow, j}];
                    if(st.find(parent) == st.end()) cnt += (mp2[parent]);
                    st.insert(parent);
                }
                if(aboveRow >= 0 && grid[aboveRow][j] == '#'){
                    ll parent = mp1[{aboveRow, j}];
                    if(st.find(parent) == st.end()) cnt += (mp2[parent]);
                    st.insert(parent);
                }
            }
            else{
                ll parent = mp1[{i, j}];
                if(st.find(parent) == st.end()){
                    st.insert(parent);
                    cnt += (mp2[parent]);
                }
            }
        }
        ans = max(ans, cnt);
    }

    // for cols
    for(ll j = 0; j < m; j++){
        ll cnt = 0;
        set<ll> st;
        for(ll i = 0; i < n; i++){
            if(grid[i][j] == '.'){
                cnt++;
                ll left  = j - 1;
                ll right = j + 1;

                if(left >= 0){
                    ll parent = mp1[{i, left}];
                    if(st.find(parent) == st.end() && grid[i][left] == '#') cnt += (mp2[parent]);
                    st.insert(parent);
                }
                if(right < m){
                    ll parent = mp1[{i, right}];
                    if(st.find(parent) == st.end() && grid[i][right] == '#') cnt += (mp2[parent]);
                    st.insert(parent);
                }
            }
            else{
                ll parent = mp1[{i, j}];
                if(st.find(parent) == st.end()){
                    st.insert(parent);
                    cnt += (mp2[parent]);
                }
            }
        }
        ans = max(ans, cnt);
    }

    cout << ans << endl;
}
// Read the question again
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // sieveOfEratosthenes()
    // memset(dp, -1, sizeof(dp));
    // cout.precision(15);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*     The code finishes, I hope it gets Accepted      */