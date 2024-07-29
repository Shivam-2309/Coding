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
void solve(){
    // 0 1 2 3
    // -> 1 2
    // 0 1 2 3
    // -> 1 2

    // 0 1
    // -> 0 1
    // 0 1
    // -> 0 1
    ll q;
    cin >> q;
    vll X;
    vll Y;
    while(q--){
        ll x, y; cin >> x >> y;

        X.push_back(x);
        Y.push_back(y);
    }

    srt(X);
    srt(Y);
    vll possX;
    vll possY;
    ll sz1 = X.size();
    if(sz1%2 == 0){
        possX.push_back(X[sz1/2]);
        possX.push_back(X[sz1/2 - 1]);
        possY.push_back(Y[sz1/2]);
        possY.push_back(Y[sz1/2 - 1]);
    }
    else{
        cout << 1 << endl;
        return;
    }

    set<pair<ll, ll>> st;
    // print(possX);
    // print(possY);
    if(possX[0] == possX[1]){
        cout << abs(possY[0] - possY[1] + 1) << endl;
        return;
    }
    if(possY[0] == possY[1]){
        cout << abs(possX[0] - possX[1] + 1) << endl;
        return;
    }
    st.insert({possX[0], possY[0]});
    st.insert({possX[0], possY[1]});
    st.insert({possX[1], possY[0]});
    st.insert({possX[1], possY[1]});

    cout << st.size() << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.precision(15);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}