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

void dfs(int row_start, int col_start, int row_end, int col_end, vector<vector<int>> &vis, vector<vector<int>> &mat, string &s, string &ans){
    if(row_start == row_end && col_start == col_end){
        ans = s;
        return;
    }

    int delRow[] = {1, 0, -1, 0};
    int delCol[] = {0, -1, 0, 1};

    for(int i=0; i<4; i++){
        int newRow = 
    }
}
 
void solve(){
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int> mat(rows, vector<int> (cols));

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cin >> mat[i][j];
        }
    }

    vector<vector<int>> vis(rows, vector<int> (cols, 0));

    int row_start = -1;
    int col_start = -1;
    int row_end = -1;
    int col _end = -1;

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(mat[i][j] == 'A'){
                row_start = i;
                col_start = j;
            }
            if(mat[i][j] == 'B'){
                row_end = i;
                col_end = j;
            }
        }
    }
    string s = "";
    string ans = "";
    dfs(row_start, col_start, row_end, col_end, vis, mat, s, ans);
    if(s.length() == 0){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        cout << ans.length() << endl;
        cout << ans << endl;
    }
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