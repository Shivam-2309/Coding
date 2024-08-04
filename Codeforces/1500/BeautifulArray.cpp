#include <bits/stdc++.h>
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
#define rep(i, n) for (ll i = 0; i < n; ++i)


void solve() {
    ll n, k;
    cin >> n >> k;
    vll v(n);
    rep(i, n) cin >> v[i];

    map<ll, multiset<ll>> mp1;
    for (ll i = 0; i < n; ++i) {
        mp1[v[i] % k].insert(v[i]);
    }

    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    map<ll, vll> mp2;
    for (auto& it : mp1) {
        multiset<ll>& a = it.second;
        vll b;
        auto it1 = a.begin();
        auto it2 = next(it1);
        while (it2 != a.end()) {
            b.push_back((*it2 - *it1) / k);
            ++it1;
            ++it2;
        }
        mp2[it.first] = b;
    }

    ll cnt = 0;
    for (auto& it : mp2) {
        if (it.second.size() % 2 == 0) cnt++;
    }

    if (cnt >= 2) {
        cout << -1 << endl;
        return;
    }

    ll ans = 0;
    for (auto& it : mp2) {
        const vll& a = it.second;
        if (a.empty()) continue;

        if (a.size() % 2 == 1) {
            for (ll i = 0; i < a.size(); i += 2) ans += a[i];
        } else {
            vll v1(a.size(), 0);
            vll v2(a.size(), 0);

            for (ll i = 0; i < a.size(); i += 2) v1[i] = a[i];
            for (ll i = 1; i < a.size(); i += 2) v2[i] = a[i];

            for (ll i = 1; i < v1.size(); i++) v1[i] += v1[i - 1];
            for (ll i = v2.size() - 2; i >= 0; i--) v2[i] += v2[i + 1];

            ll minSum = LLONG_MAX;
            for (ll i = 1; i < a.size() - 1; i++) {
                ll sum = 0;
                if (i % 2 == 1) {
                    if (i > 0) sum += v1[i - 1];
                    if (i + 2 < v1.size()) sum += v2[i + 2];
                } else {
                    if (i > 1) sum += v1[i - 2];
                    if (i + 3 < v2.size()) sum += v2[i + 3];
                    if (i + 1 < a.size()) sum += a[i + 1];
                    sum += a[i];
                }
                minSum = min(minSum, sum);
            }
            if (!v2.empty()) minSum = min(minSum, v2[0]);
            if (!v1.empty()) minSum = min(minSum, v1.back());
            ans += minSum;
        }
    }

    cout << ans << endl;
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