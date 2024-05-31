#include<bits/stdc++.h>
using namespace std;
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
// ll dp[NUM];
void solve(){
    ll n, k;
    cin >> n >> k;

    vll v(n);
    rep(i, n) cin >> v[i];

    vll prefix1(n);
    prefix1[0] = v[0];
    for(ll i=1; i<n; i++){
        prefix1[i] = prefix1[i-1] + v[i];
    } 
    vll prefix2(n);
    prefix2[n-1] = v[n-1];
    for(ll i=n-2; i>=0; i--){
        prefix2[i] = prefix2[i+1] + v[i];
    }

    rev(prefix2);

    if(prefix1[n-1] <= k){
        cout << n << endl;
        return;
    }
    
    ll timesFirst = k/2 + k%2;
    ll timesSecond = k/2;

    ll cnt = 0;

    for(ll i=0; i<n; i++){
        if(prefix1[i] <= timesFirst){
            cnt++;
            cnt = min(cnt, n);
        }
        else{
            break;
        }
    }

    for(ll i=0; i<n; i++){
        if(prefix2[i] <= timesSecond){
            cnt++;
            cnt = min(cnt, n);
        }
        else{
            break;
        }
    }

    cout << cnt << endl;

}
// Read the question again
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // sieveOfEratosthenes()
    // memset(dp, -1, sizeof(dp));
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*     The code finishes, I hope it gets Accepted      */