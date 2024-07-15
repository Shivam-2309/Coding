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
#define ll long long
#define vll vector<ll>
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end());
#define rep(i, n) for (ll i = 0; i < n; i++)
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
ll lcm(ll a, ll b)
{
    return a * b / __gcd(a, b);
}
// ll dp[100001];
void solve(){
    ll n; cin >> n;
    string s; cin >> s;

    vll v;
    for(ll i=0; i<n; i++){
        v.push_back(s[i] - 'a');
    }

    if(is_sorted(v.begin(), v.end())){
        cout << 0 << endl;
        return;
    }

    stack<pair<ll, ll>> st1;
    for(ll i=0; i<n; i++){
        while(!st1.empty() && st1.top().first < v[i]){
            st1.pop();
        }
        st1.push({v[i], i});
    }

    set<ll> st;
    stack<pair<ll, ll>> st2 = st1;
    vll values;
    while(!st2.empty()){
        st.insert(st2.top().second);
        values.push_back(st2.top().first);
        st2.pop();
    }

    
    vll final(n, -1);
    for(ll i=0; i<n; i++){
        if(st.find(i) == st.end()){
            final[i] = v[i];
        }
    }

    // print(final);

    ll i = 0;
    ll j = 0;
    while(i < n){
        if(final[i] == -1){
            final[i] = values[j];
            j++;
        }
        i++;
    }

    ll times = 0;
    ll k = values.size() - 1;
    ll val = values[k];
    k--;
    while(k >= 0){
        if(values[k] == val) times++;
        k--;
    }

    // print(final);

    if(is_sorted(final.begin(), final.end())){
        cout << values.size() - 1 - times << endl;
    }
    else{
        cout << -1 << endl;
    }
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
/*     The code finishes, I hope it gets Accepted      */