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
    int n, m;
    cin >> n >> m; 
    string s;
    cin >> s; 

    string s1 = "abc";
    string s2 = "acb";
    string s3 = "bac";
    string s4 = "bca";
    string s5 = "cab";
    string s6 = "cba";

    while(s1.size() < n){
        s1 += "abc";
    }
    s1.resize(n); 

    // cout << s1 << endl;

    while(s2.size() < n){
        s2 += "acb";
    }
    s2.resize(n);

    while(s3.size() < n){
        s3 += "bac";
    }
    s3.resize(n);

    while(s4.size() < n){
        s4 += "bca";
    }
    s4.resize(n);

    while(s5.size() < n){
        s5 += "cab";
    }
    s5.resize(n);

    while(s6.size() < n){
        s6 += "cba";
    }
    s6.resize(n);

    // cout << s1 << endl;
    // cout << s2 << endl;
    // cout << s3 << endl;
    // cout << s4 << endl;
    // cout << s5 << endl;
    // cout << s6 << endl;

    vll p1(n, 0);
    vll p2(n, 0);
    vll p3(n, 0);
    vll p4(n, 0);
    vll p5(n, 0);
    vll p6(n, 0);

    for(ll i=0; i<n; i++){
        if(s1[i] == s[i]) p1[i] = 1;
        if(s2[i] == s[i]) p2[i] = 1;
        if(s3[i] == s[i]) p3[i] = 1;
        if(s4[i] == s[i]) p4[i] = 1;
        if(s5[i] == s[i]) p5[i] = 1;
        if(s6[i] == s[i]) p6[i] = 1;
    }

    for(ll i=1; i<n; i++){
        p1[i] += p1[i-1];
        p2[i] += p2[i-1];
        p3[i] += p3[i-1];
        p4[i] += p4[i-1];
        p5[i] += p5[i-1];
        p6[i] += p6[i-1];
    }

    while(m--){
        ll l, r; cin >> l >> r;
        l--;
        r--;

        ll v1 = p1[r] - (l > 0 ? p1[l-1] : 0);
        ll v2 = p2[r] - (l > 0 ? p2[l-1] : 0);
        ll v3 = p3[r] - (l > 0 ? p3[l-1] : 0);
        ll v4 = p4[r] - (l > 0 ? p4[l-1] : 0);
        ll v5 = p5[r] - (l > 0 ? p5[l-1] : 0);
        ll v6 = p6[r] - (l > 0 ? p6[l-1] : 0);

        ll maxi = max({v1, v2, v3, v4, v5, v6});

        cout << r - l + 1 - maxi << endl;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.precision(15);
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}