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
#define ll long long
#define vll vector<ll>
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end());
#define rep(i, n) for (ll i = 0; i < n; i++)
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

bool isValid(ll r, ll c, ll rows, ll cols){
    if(r >= 0 && r < rows && c >= 0 && c < cols){
        return true;
    }
    return false;
}

void solve(){
    ll n, m; cin >> n >> m;

    vector<vector<char>> grid(n+1, vector<char> (m+1, '*'));

    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            char ch; cin >> ch;
            grid[i][j] = ch;
        }
    }

    ll vis[n][m];

    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            vis[i][j] = 0;
        }
    }

    char path[n][m];

    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            path[i][j] = '*';
        }
    }

    ll startRow = -1;
    ll startCol = -1;

    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            if(grid[i][j] == 'A'){
                startRow = i;
                startCol = j;
                break;
            }
        }
        if((startRow != -1) && (startCol != -1)) break;
    }

    ll delRow[] = {1, 0, -1, 0};
    ll delCol[] = {0, 1, 0, -1};

    queue<pair<ll, ll>> q;
    q.push({startRow, startCol});

    while(!q.empty()){
        auto cell = q.front();
        q.pop();

        ll row = cell.first;
        ll col = cell.second;

        for(ll i=0; i<4; i++){
            ll newRow = row + delRow[i];
            ll newCol = col + delCol[i];

            if(isValid(newRow, newCol, n, m) && grid[newRow][newCol] == 'B'){
                // found
                if(i == 0) path[newRow][newCol] = 'D';
                if(i == 1) path[newRow][newCol] = 'R';
                if(i == 2) path[newRow][newCol] = 'U';
                if(i == 3) path[newRow][newCol] = 'L';

                string res = "";
                ll s = newRow;
                ll e = newCol;

                while(grid[s][e] != 'A'){
                    // cout << "CHECK" << endl;
                    // cout << path[s][e] << endl;
                    res.push_back(path[s][e]);
                    if(path[s][e] == 'U') s++;
                    else if(path[s][e] == 'D') s--;
                    else if(path[s][e] == 'L') e++;
                    else if(path[s][e] == 'R') e--;
                }
                
                rev(res);

                cout << "YES" << endl;
                cout << res.length() << endl;
                cout << res << endl;
                return;
            }

            if(isValid(newRow, newCol, n, m) && !vis[newRow][newCol] && grid[newRow][newCol] == '.'){
                if(i == 0) path[newRow][newCol] = 'D';
                if(i == 1) path[newRow][newCol] = 'R';
                if(i == 2) path[newRow][newCol] = 'U';
                if(i == 3) path[newRow][newCol] = 'L';
                vis[newRow][newCol] = 1;
                q.push({newRow, newCol});
            } 
        }
    }

    cout << "NO" << endl;
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
/*     The code finishes, I hope it gets Accepted      */