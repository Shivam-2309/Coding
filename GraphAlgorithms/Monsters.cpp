#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isValid(ll newRow, ll newCol, ll n, ll m){
    return (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m);
}

void solve(){
    // This is a question of multisource BFS + simple BFS on a grid
    ll n, m; cin >> n >> m;

    vector<vector<char>> grid(n, vector<char> (m, '\0'));

    ll myRow = -1;
    ll myCol = -1;

    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            char ch; cin >> ch;
            grid[i][j] = ch;
        }
    }

    // now i need to perform a multisource BFS
    queue<pair<ll, ll>> q1;
    vector<vector<ll>> time(n, vector<ll> (m, -1));
    vector<vector<ll>> vis1(n, vector<ll> (m, 0));
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            if(grid[i][j] == 'M'){
                vis1[i][j] = 1;
                q1.push({i, j});
                time[i][j] = 0;
            }

            if(grid[i][j] == 'A'){
                myRow = i;
                myCol = j;
            }
        }
    }

    if(myRow == 0 || myRow == n-1 || myCol == 0 || myCol == m-1){
        cout << "YES" << endl;
        cout << 0 << endl;
        return;
    }

    ll delRow[] = {1, 0, -1, 0};
    ll delCol[] = {0, 1, 0, -1};

    ll currTime = 0;
    while(!q1.empty()){
        ll size = q1.size();
        for(ll i=0; i<size; i++){
            auto cell = q1.front();
            q1.pop();

            ll row = cell.first;
            ll col = cell.second;

            for(ll j=0; j<4; j++){
                ll newRow = row + delRow[j];
                ll newCol = col + delCol[j];
                
                if(isValid(newRow, newCol, n, m) && (!vis1[newRow][newCol]) && (grid[newRow][newCol] == '.' || grid[newRow][newCol] == 'A')){
                    vis1[newRow][newCol] = 1;
                    time[newRow][newCol] = currTime + 1;
                    q1.push({newRow, newCol});
                }
            }
        }
        currTime++;
    }

    ll myTime = 0;
    queue<pair<ll, ll>> q;
    q.push({myRow, myCol});
    vector<vector<ll>> vis(n, vector<ll> (m, 0));
    vis[myRow][myCol] = 1;
    vector<vector<char>> drcs(n, vector<char> (m, '*'));

    while(!q.empty()){
        ll size = q.size();

        for(ll i=0; i<size; i++){
            auto cell = q.front();
            q.pop();

            ll row = cell.first;
            ll col = cell.second;

            for(ll j=0; j<4; j++){
                ll newRow = row + delRow[j];
                ll newCol = col + delCol[j];

                if(isValid(newRow, newCol, n, m) && (time[newRow][newCol] > myTime + 1 || time[newRow][newCol] == -1) && (!vis[newRow][newCol]) && (grid[newRow][newCol] == '.')){
                    q.push({newRow, newCol});
                    vis[newRow][newCol] = 1;

                    if(j == 0) drcs[newRow][newCol] = 'D';
                    else if(j == 1) drcs[newRow][newCol] = 'R';
                    else if(j == 2) drcs[newRow][newCol] = 'U';
                    else if(j == 3) drcs[newRow][newCol] = 'L';
                }
            }
        }
        myTime++;
    }

    ll targetRow = -1;
    ll targetCol = -1;

    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            if(drcs[i][j] != '*' && (i == 0 || i == n-1 || j == 0 || j == m-1)){
                targetRow = i;
                targetCol = j;
                break;
            }
        }
        if(targetRow != -1 || targetCol != -1) break;
    }

    if(targetRow == -1 && targetCol == -1){
        cout << "NO" << endl;
        return;
    }

    vector<char> ans;

    ll currRow = targetRow;
    ll currCol = targetCol;

    while(!(currRow == myRow && currCol == myCol)){
        // debug(currRow);
        // debug(currCol);
        ans.push_back(drcs[currRow][currCol]);
        // print(ans);
        char dir = drcs[currRow][currCol];

        if(dir == 'U') currRow++;
        if(dir == 'D') currRow--;
        if(dir == 'L') currCol++;
        if(dir == 'R') currCol--;
    }

    reverse(ans.begin(), ans.end());
    cout << "YES" << endl;
    cout << ans.size() << endl;
    for(auto directionPoints : ans) cout << directionPoints;
    cout << endl;
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
