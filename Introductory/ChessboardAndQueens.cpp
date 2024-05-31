/*      Jai Shree Ram      */
/*      Code Snippet of Shivam Kapoor      */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end());
#define endl '\n'
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
const int NUM = 2e5 + 7;
const ll INF = 1e18 + 5;
bool sieve[NUM];
void sieveOfEratosthenes() {
    memset(sieve, true, sizeof(sieve));
    sieve[1] = false;
    sieve[0] = false; 
    for (ll p = 2; p * p <= NUM; p++) {
        if (sieve[p]) {
            for (ll i = p * p; i <= NUM; i += p)
                sieve[i] = false;
        }
    }
}
// ll dp[NUM];
bool isSafe(int row, int col, const vector<vector<char>>& board) {
    // Check for any other queens in the same row or column
    for (int i = 0; i < 8; ++i) {
        if (board[row][i] == 'a' || board[i][col] == 'a')
            return false;
    }

    // Check for any other queens in diagonals
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 'a')
            return false;
    }

    for (int i = row, j = col; i < 8 && j < 8; ++i, ++j) {
        if (board[i][j] == 'a')
            return false;
    }

    for (int i = row, j = col; i >= 0 && j < 8; --i, ++j) {
        if (board[i][j] == 'a')
            return false;
    }

    for (int i = row, j = col; i < 8 && j >= 0; ++i, --j) {
        if (board[i][j] == 'a')
            return false;
    }
    // If no queens are attacking the given position, it's safe to place a queen
    return true;
}

void f(ll col, vector<vector<char>> &grid, ll &cnt){
    if(col == 8){
        cnt++;
        return;
    }

    for(ll r = 0; r < 8; r++){
        if(grid[r][col] == '*') continue;

        if(isSafe(r, col, grid)){
            grid[r][col] = 'a';
            f(col+1, grid, cnt);
            grid[r][col] = '.';
        }
    }
}

void solve(){
    // N Queens Problem
    // The question boils down to 8 Queens instead of N queens

    vector<vector<char>> grid(8, vector<char> (8));
    for(ll i=0; i<8; i++){
        for(ll j=0; j<8; j++){
            cin >> grid[i][j];
        }
    }

    ll cnt = 0;
    ll col = 0;
    f(col, grid, cnt);
    cout << cnt << endl;
}
// clear all data structures between test cases
// handle all corner cases
// confusing between n and m , i and j?
// uninitialized variables?
// Read the question again
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // sieveOfEratosthenes()
    // memset(dp, -1, sizeof(dp));
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*     The code finishes, I hope it gets Accepted      */