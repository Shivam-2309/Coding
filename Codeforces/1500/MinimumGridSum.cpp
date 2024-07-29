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

vector<pair<ll, ll>> f(vector<ll> &v){
    ll n = v.size();
    ll curr = v[0];
    vector<pair<ll, ll>> ans;
    ans.push_back({curr, 0});

    for(ll i=1; i<n; i++){
        if(v[i] < curr){
            ans.push_back({v[i], i});
            curr = v[i];
        }
    }
    return ans;
}

void solve(){
    ll n; cin >> n;
    vll v(n);
    rep(i, n) cin >> v[i];

    vll a;
    vll b;
    for(ll i=0; i<n; i++){
        if(i%2==0) a.push_back(v[i]);
        else b.push_back(v[i]);
    }

    ll ans = 0;
    vector<pair<ll, ll>> a1 = f(a);
    vector<pair<ll, ll>> a2 = f(b);

    // for(auto it : a1) cout << it.first << " " << it.second << endl;
    // cout << endl;
    // for(auto it : a2) cout << it.first << " " << it.second << endl;
    // cout << endl;

    if(a1.size() >= a2.size()){
        ll cost = 0;
        ll curr = a1[0].first;
        ll last = 0;
        for(ll i=1; i<a2.size(); i++){
            cost += (a1[i].second - last)*curr;
            last = a1[i].second;
            curr = a1[i].first;
        }
        cost += (n - last)*curr;
        curr = a2[0].first;
        last = 0;
        for(ll i=1; i<a2.size(); i++){
            cost += (a2[i].second - last)*curr;
            last = a2[i].second;
            curr = a2[i].first;
        }
        cost += (n - last)*curr;
        cout << cost << endl;
    }
    else{
        vector<pair<ll, ll>> a;
        vector<pair<ll, ll>> b;
        for(ll i=0; i<a1.size(); i++){
            a.push_back(a1[i]);
        }
        for(ll i=0; i<a1.size(); i++){
            b.push_back(a2[i]);
        }

        a1.clear();
        a2.clear();
        a1 = a;
        a2 = b;

        for(auto it : a1) cout << it.first << " " << it.second << endl;
        cout << endl;
        for(auto it : a2) cout << it.first << " " << it.second << endl;
        cout << endl;

        ll cost = 0;
        ll curr = a1[0].first;
        ll last = 0;
        for(ll i=1; i<a1.size(); i++){
            cost += (a1[i].second - last)*curr;
            last = a1[i].second;
            curr = a1[i].first;
        }
        cost += (n - last)*curr;
        curr = a2[0].first;
        last = 0;
        for(ll i=1; i<a2.size(); i++){
            cost += (a2[i].second - last)*curr;
            last = a2[i].second;
            curr = a2[i].first;
        }
        cost += (n - last)*curr;
        cout << cost << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}