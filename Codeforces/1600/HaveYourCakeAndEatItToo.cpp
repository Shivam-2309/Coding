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

ll dfs(ll idx, vll &a, vll &b, vll &c, ll total, ll times, vector<ll> &done) {
    if(times > 3) return LLONG_MAX;
    if (idx == a.size()) {
        return 0;
    }

    ll idx1 = lower_bound(a.begin(), a.end(), total + (idx > 0 ? a[idx-1] : 0)) - a.begin();
    ll idx2 = lower_bound(b.begin(), b.end(), total + (idx > 0 ? b[idx-1] : 0)) - b.begin();
    ll idx3 = lower_bound(c.begin(), c.end(), total + (idx > 0 ? c[idx-1] : 0)) - c.begin();

    ll ans1 = LLONG_MAX;
    if (find(done.begin(), done.end(), 1) == done.end()) {
        done.push_back(1);
        ans1 = dfs(idx1 + 1, a, b, c, total, times + 1, done);
        done.pop_back();
    }

    ll ans2 = LLONG_MAX;
    if (find(done.begin(), done.end(), 2) == done.end()) {
        done.push_back(2);
        ans2 = dfs(idx2 + 1, a, b, c, total, times + 1, done);
        done.pop_back();
    }

    ll ans3 = LLONG_MAX;
    if (find(done.begin(), done.end(), 3) == done.end()) {
        done.push_back(3);
        ans3 = dfs(idx3 + 1, a, b, c, total, times + 1, done);
        done.pop_back();
    }

    return min({ ans1, ans2, ans3 });
}
void solve(){
    ll n; cin >> n;
    vll a(n);
    rep(i, n) cin >> a[i];
    vll b(n);
    rep(i, n) cin >> b[i];
    vll c(n);
    rep(i, n) cin >> c[i];

    ll total = 0;
    rep(i, n) total += a[i];
    total = ceil(total/3.0);

    for(ll i=1; i<n; i++){
        a[i] = a[i-1] + a[i];
        b[i] = b[i-1] + b[i];
        c[i] = c[i-1] + c[i];
    }

    // a b c
    // a c b
    // b a c
    // b c a
    // c a b
    // c b a

    // a b c
    bool f1 = true;
    ll t1 = total;
    ll idx1 = lower_bound(a.begin(), a.end(), t1) - a.begin();
    if(idx1 == n) f1 = false;
    if(f1){
        t1 = b[idx1] + total;
        ll idx2 = lower_bound(b.begin(), b.end(), t1) - b.begin();
        if(idx2 == n) f1 = false;
        if(f1){
            t1 = c[idx2] + total;
            ll idx3 = lower_bound(c.begin(), c.end(), t1) - c.begin();
            if(idx3 < n){
                cout << 1 << " " << idx1+1 << " ";
                cout << idx1+2 << " " << idx2 + 1 << " ";
                cout << idx2+2 << " " << n << endl;
                return;
            }
        }
    }

    // a c b
    f1 = true;
    t1 = total;
    idx1 = lower_bound(a.begin(), a.end(), t1) - a.begin();
    if(idx1 == n) f1 = false;
    if(f1){
        t1 = c[idx1] + total;
        ll idx2 = lower_bound(c.begin(), c.end(), t1) - c.begin();
        if(idx2 == n) f1 = false;
        if(f1){
            t1 = b[idx2] + total;
            ll idx3 = lower_bound(b.begin(), b.end(), t1) - b.begin();
            if(idx3 < n){
                cout << 1 << " " << idx1+1 << " ";  // a
                cout << idx2 + 2 << " " << n << " "; // b
                cout << idx1 + 2 << " " << idx2+1 << endl; // c
                return;
            }
        }
    }

    // b c a
    f1 = true;
    t1 = total;
    idx1 = lower_bound(b.begin(), b.end(), t1) - b.begin();
    if(idx1 == n) f1 = false;
    if(f1){
        t1 = c[idx1] + total;
        ll idx2 = lower_bound(c.begin(), c.end(), t1) - c.begin();
        if(idx2 == n) f1 = false;
        if(f1){
            t1 = a[idx2] + total;
            ll idx3 = lower_bound(a.begin(), a.end(), t1) - a.begin();
            if(idx3 < n){
                cout << idx2+2 << " " << n << " "; // a
                cout << 1 << " " << idx1+1 << " "; // b
                cout << idx1+2 << " " << idx2 + 1 << endl; // c
                return;
            }
        }
    }

    // b a c
    f1 = true;
    t1 = total;
    idx1 = lower_bound(b.begin(), b.end(), t1) - b.begin();
    if(idx1 == n) f1 = false;
    if(f1){
        t1 = a[idx1] + total;
        ll idx2 = lower_bound(a.begin(), a.end(), t1) - a.begin();
        if(idx2 == n) f1 = false;
        if(f1){
            t1 = c[idx2] + total;
            ll idx3 = lower_bound(c.begin(), c.end(), t1) - c.begin();
            if(idx3 < n){
                cout << idx1+2 << " " << idx2 + 1 << " "; // a
                cout << 1 << " " << idx1+1 << " "; // b
                cout << idx2+2 << " " << n << endl; // c
                return;
            }
        }
    }

    // c a b
    f1 = true;
    t1 = total;
    idx1 = lower_bound(c.begin(), c.end(), t1) - c.begin();
    if(idx1 == n) f1 = false;
    if(f1){
        t1 = a[idx1] + total;
        ll idx2 = lower_bound(a.begin(), a.end(), t1) - a.begin();
        if(idx2 == n) f1 = false;
        if(f1){
            t1 = b[idx2] + total;
            ll idx3 = lower_bound(b.begin(), b.end(), t1) - b.begin();
            if(idx3 < n){
                cout << idx1+2 << " " << idx2 + 1 << " "; // a
                cout << idx2+2 << " " << n << " "; // b
                cout << 1 << " " << idx1+1 << endl; // c
                return;
            }
        }
    }

    // c b a
    f1 = true;
    t1 = total;
    idx1 = lower_bound(c.begin(), c.end(), t1) - c.begin();
    if(idx1 == n) f1 = false;
    if(f1){
        t1 = b[idx1] + total;
        ll idx2 = lower_bound(b.begin(), b.end(), t1) - b.begin();
        if(idx2 == n) f1 = false;
        if(f1){
            t1 = a[idx2] + total;
            ll idx3 = lower_bound(a.begin(), a.end(), t1) - a.begin();
            if(idx3 < n){
                cout << idx2+2 << " " << n << " "; // a
                cout << idx1+2 << " " << idx2 + 1 << " "; // b
                cout << 1 << " " << idx1+1 << endl; // c
                return;
            }
        }
    }


    cout << -1 << endl;
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