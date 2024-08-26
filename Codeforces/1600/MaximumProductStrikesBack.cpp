// Author : Shivam Kapoor
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x) cerr << #x << " = " << x << endl
#define print(v) cerr << #v << " = [ "; for (auto &el : v) cerr << el << " "; cerr << "]\n";
#define print2d(v) cerr << #v << ":\n"; for (auto &row : v) { cerr << "[ "; for (auto &el : row) cerr << el << " "; cerr << "]\n"; }
#define printmap(m) cerr << #m << ":\n"; for (auto &[key, value] : m) cerr << key << " -> " << value << "\n";
#define printpp(v) cerr << #v << " = [ "; for (auto &[first, second] : v) cerr << "(" << first << ", " << second << ") "; cerr << "]\n";

#define vll vector<ll>
#define rev(v) reverse(all(v))
#define srt(v) sort(all(v))
#define all(v) (v).begin(), (v).end()
#define rep(i, n) for (ll i = 0; i < (n); ++i)

const ll mod7 = 1e9 + 7;

void solve(){
    ll n; cin >> n;
    vll v(n);
    rep(i, n) cin >> v[i];

    ll l = 0;
    ll r = 0;
    
    vector<pair<ll, pair<ll, ll>>> res;
    res.push_back({0, {0, n}});

    while(r < n){
        vector<ll> a;
        while(r < n && v[r] != 0){
            a.push_back(v[r]);
            r++;
        }
        r = max({l, r - 1});
        // l -> r
        ll numTwos = 0;
        ll neg = 0;
        for(ll i = 0; i < a.size(); i++){
            if(a[i] < 0) neg++;
            if(a[i] == 2 || a[i] == -2) numTwos++;
        }
        print(a);
        debug(neg);
        if(a.size() > 0 && neg % 2 == 0){
            // cout << "CHECK" << endl;
            debug(l);
            debug(r);
            debug(numTwos);
            res.push_back({numTwos, {l, n - r - 1}});
        }
        else if(neg == 1 && a.size() == 1){
            // continue;
        }
        else if(a.size() > 0){
            // cout << "CHECK" << endl;
            ll e = a.size() - 1;
            ll ee = r;
            ll s = 0;
            ll ss = l;
            ll numTwos1 = numTwos;
            ll numTwos2 = numTwos;
            while(e >= 0){
                // cout << "CHECK" << endl;
                if (e < a.size()){
                    if(a[e] == -1){
                        e--;
                        ee--;
                        break;
                    }
                    if(a[e] == -2){
                        e--;
                        ee--;
                        numTwos1--;
                        break;
                    }
                    if(a[e] == 2){
                        // e--;
                        // ee--;
                        numTwos1--;
                    }
                }
                ee--;
                e--;
            }
            debug(e);
            debug(ee);
            res.push_back({numTwos1, {l, n - ee - 1}});
            while(s < a.size()){
                if (s >= 0){
                    if(a[s] == -1){
                        s++;
                        ss++;
                        break;
                    }
                    if(a[s] == -2){
                        s++;
                        ss++;
                        numTwos2--;
                        break;
                    }
                    if(a[s] == 2){
                        numTwos2--;
                    }
                }
                s++;
                ss++;
            }
            debug(s);
            debug(ss);
            res.push_back({numTwos2, {ss, n - r - 1}});
        }
        if(l == r){
            l++;
            r++;
        }
        else{
            r += 2;
            l = r;
        }
    }

    sort(res.rbegin(), res.rend());
    if(res[0].second.first == 0 && res[0].second.second == n){
        for(ll i = 0; i < n; i++){
            if(v[i] == 1) {
                cout << i << " " << n - i - 1 << endl;
                return;
            }
        }
    }
    cout << res[0].second.first << " " << res[0].second.second << endl;
}

int main(){
    fast_io
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
