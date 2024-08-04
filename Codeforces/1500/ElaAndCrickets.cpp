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
#define vll vector<ll>
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end());
#define rep(i, n) for (ll i = 0; i < n; i++)
const ll mod7 = 1e9 + 7;

// a^2 + b^2 = c^2
// c = a^2 - b

// a^2 = c + b
// 1e9 + 1e9
// a^2 -> 2e9
// a -> 1e5

// 3x 4x 5x 

void solve(vll &ans){
    ll n; cin >> n;
    ll cnt = upper_bound(ans.begin(), ans.end(), n) - ans.begin();
    cout << cnt << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.precision(15);
    vll ans;
    for(ll i = 3; i <= 1e5; i += 2){
        // a^2 = 2*b + 1
        ll side1 = i;
        ll side2 = ((i * i) - 1)/2;
        ll side3 = sqrt(side1*side1 + side2*side2);
        ans.push_back(side3);
    }

    // print(ans);

    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve(ans);
    }
    return 0;
}