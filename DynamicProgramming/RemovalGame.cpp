#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

const int MAXN = 5001;
ll dp[MAXN][MAXN][2];

ll f(int i, int j, int turn, vll &v) {
    if (j < i) return 0;
    if (dp[i][j][turn] != -1) return dp[i][j][turn];

    if (turn == 0) {
        ll pick_i = v[i] + f(i + 1, j, 1, v); 
        ll pick_j = v[j] + f(i, j - 1, 1, v); 

        return dp[i][j][turn] = max(pick_i, pick_j);
    } else {
        ll pick_i = f(i + 1, j, 0, v); 
        ll pick_j = f(i, j - 1, 0, v); 

        return dp[i][j][turn] = min(pick_i, pick_j);
    }
}

void solve() {
    int n;
    cin >> n;
    vll v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < MAXN; ++j) {
            dp[i][j][0] = dp[i][j][1] = -1;
        }
    }
    
    ll max_score = f(0, n - 1, 0, v);
    cout << max_score << endl;
}

int main() {
    solve();
    return 0;
}
