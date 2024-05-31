#include "bits/stdc++.h"
using namespace std;
#define int long long
#define endl "\n"
#define INF 1e18
#define all(x) (x).begin(), (x).end()
#define srt(v) sort(v.begin(), v.end())
#define rep(i, n) for (long long i = 0; i < n; i++)

const int mod7 = 1e9 + 7;
const int mod9 = 998244353;

int power(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return res;
}

void bfs(int r, int c, vector<vector<int>> &vis, vector<vector<char>> &mat){
    queue<pair<int, int>> q;
    int tot_rows = mat.size();
    int tot_cols = mat[0].size();
    q.push({r, c});
    vis[r][c] == 1;

    int delRow[] = {1, 0, -1, 0};
    int delCol[] = {0, 1, 0, -1};


    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;

        q.pop();

        for(int i=0; i<4; i++){
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            if(newCol >= 0 && newCol < tot_cols && newRow < tot_rows && newRow >= 0 && mat[newRow][newCol] == '.' && vis[newRow][newCol] == 0){
                vis[newRow][newCol] = 1;
                q.push({newRow, newCol});
            }
        }
    }
}
 
void solve(){
    // Basic Question of BFS
    // BFS on a 2D matrix

    int rows, cols;
    cin >> rows >> cols;

    vector<vector<char>> mat(rows, vector<char> (cols));

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cin >> mat[i][j];
        }
    }

    int cnt = 0;

    vector<vector<int>> vis(rows, vector<int> (cols, 0));

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(!vis[i][j] && mat[i][j] == '.'){
                cnt++;
                bfs(i, j, vis, mat);
            }
        }
    }
    cout << cnt << endl;
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    // cin >> tc;

    tc = 1;
    while(tc--){
        solve();
    }
   return 0;
}