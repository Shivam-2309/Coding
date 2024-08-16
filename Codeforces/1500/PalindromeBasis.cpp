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
                    cout << " ]" << endl; \
                } while(0)
#define print2d(v) do { \
                    cout << "vect-- starts" << endl; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "[" << " "; \
                        for (int j = 0; j < v[i].size(); j++) { \
                            cout << v[i][j] << " "; \
                        } \
                        cout << "]" << endl; \
                    } \
                    cout << "vect-- ends" << endl; \
                } while(0)
#define printmap(m) do { \
                    cout << "map-- starts" << endl; \
                    for (auto it = m.begin(); it != m.end(); ++it) { \
                        cout << it->first << " -> " << it->second << endl; \
                    } \
                    cout << "map-- ends" << endl; \
                } while(0)
 
#define printpp(v) do { \
                    cout << "vect--" << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "(" << v[i].first << ", " << v[i].second << ") "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#define print2d(v)
#define printmap(m)
#define printpp(v)
#endif
#define vll vector<ll>
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end());
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < n; i++)
const ll mod7 = 1e9 + 7;

bool isPalindrome(ll num) {
    ll originalNum = num;
    ll reversedNum = 0;

    while (num > 0) {
        ll digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }

    return originalNum == reversedNum;
}

ll dp[50001];
void combinationSum4(vector<ll>& nums) {
    dp[0][50001] = 1; 
    // dp[i][sum] -> total number of ways to make sum = sum such that the coins from i -> n-1 are usable
}

void solve(vll &p){
    ll n; cin >> n;
    cout << dp[n]%mod7 << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp, 0, sizeof(dp));
    vll p;
    for(ll i = 1; i <= 50000; i++){
        if(isPalindrome(i)){
            p.push_back(i);
        }
    }
    // rev(p);
    combinationSum4(p);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve(p);
    }
    return 0;
}