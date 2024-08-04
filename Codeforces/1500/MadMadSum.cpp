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
    ll n; cin >> n;
    vll v(n);
    rep(i, n) cin >> v[i];

    ll sum = 0;
    rep(i, n) sum += v[i];
    priority_queue<ll> pq;
    pq.push(0);
    vector<ll> a;
    map<ll, ll> mp;
    for(ll i=0; i<n; i++){
        mp[v[i]]++;
        if(mp[v[i]] == 2) pq.push(v[i]);
        a.push_back(pq.top()); 
    }
    for(ll i=0; i<a.size(); i++) sum += a[i];
    ll last = 0;
    print(a);
    debug(sum);
    vll b;
    for(ll i=0; i<n-1; i++){
        if(a[i] != a[i+1]){
            b.push_back(last);
        }
        else{
            b.push_back(last);
            last = a[i];
        }
    }
    b.push_back(last);
    print(b);
    for(ll i=0; i<b.size(); i++){
        sum += (b.size() - i)*b[i];
    }

    cout << sum << endl;
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