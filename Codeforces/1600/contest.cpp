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
                    cout << " ]" << endl; \
                } while(0)
#define print2d(v) do { \
                    cout << "vect-- starts" << endl; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "[" << " "; \
                        for (int j = 0; j < v[i].size(); j++) { \
                            cout << v[i][j] << " "; \
                        } \
                        cout << "]" << endl; \
                    } \
                    cout << "vect-- ends" << endl; \
                } while(0)
#define printmap(m) do { \
                    cout << "map-- starts" << endl; \
                    for (auto it = m.begin(); it != m.end(); ++it) { \
                        cout << it->first << " -> " << it->second << endl; \
                    } \
                    cout << "map-- ends" << endl; \
                } while(0)
 
#define printpp(v) do { \
                    cout << "vect--" << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "(" << v[i].first << ", " << v[i].second << ") "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#define print2d(v)
#define printmap(m)
#define printpp(v)
#endif

#define vll vector<ll>
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end());
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < n; i++)
const ll mod7 = 1e9 + 7;
void solve(ll &cnt, ll &t_copy) {
    ll n, q;
    cin >> n >> q;
    vector<string> v(n);

    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<ll> prefixBR(n, 0), suffixBR(n, 0);
    vector<ll> prefixBG(n, 0), suffixBG(n, 0);
    vector<ll> prefixBY(n, 0), suffixBY(n, 0);
    vector<ll> prefixGR(n, 0), suffixGR(n, 0);
    vector<ll> prefixGY(n, 0), suffixGY(n, 0);
    vector<ll> prefixRY(n, 0), suffixRY(n, 0);
 
    if (v[0] == "BR") prefixBR[0] = 1;
    if (v[0] == "BG") prefixBG[0] = 1;
    if (v[0] == "BY") prefixBY[0] = 1;
    if (v[0] == "GR") prefixGR[0] = 1;
    if (v[0] == "GY") prefixGY[0] = 1;
    if (v[0] == "RY") prefixRY[0] = 1;
 
    for (ll i = 1; i < n; i++) {
        prefixBR[i] = prefixBR[i - 1] + (v[i] == "BR" ? 1 : 0);
        prefixBG[i] = prefixBG[i - 1] + (v[i] == "BG" ? 1 : 0);
        prefixBY[i] = prefixBY[i - 1] + (v[i] == "BY" ? 1 : 0);
        prefixGR[i] = prefixGR[i - 1] + (v[i] == "GR" ? 1 : 0);
        prefixGY[i] = prefixGY[i - 1] + (v[i] == "GY" ? 1 : 0);
        prefixRY[i] = prefixRY[i - 1] + (v[i] == "RY" ? 1 : 0);
    }
 
     
    map<string, vector<ll>> mpPrefix;
 
    mpPrefix["BR"] = prefixBR;
    mpPrefix["BG"] = prefixBG;
    mpPrefix["BY"] = prefixBY;
    mpPrefix["GR"] = prefixGR;
    mpPrefix["GY"] = prefixGY;
    mpPrefix["RY"] = prefixRY;
    map<string, vector<ll>> index;

    for (ll i = 0; i < n; i++) {
        index[v[i]].push_back(i);
    }

    while (q--) {
        ll l, r;
        cin >> l >> r;
        ll l_c = l;
        ll r_c = r;
        l = min(l_c, r_c);
        r = max(l_c, r_c);
        l--; r--;

        string start = v[l];
        string end = v[r];

        // debug(start);
        // debug(end);

        bool areAllDifferent = ((start[0] != end[0]) && (start[0] != end[1]) && (start[1] != end[0]) && (start[1] != end[1]));

        if (areAllDifferent) {
            ll add1 = mpPrefix[start][r] - (l > 0 ? mpPrefix[start][l - 1] : 0);
            ll add2 = mpPrefix[end][r] - (l > 0 ? mpPrefix[end][l - 1] : 0);
 
            ll sum = add1 + add2;
            if (sum != (r - l + 1)) {
                cout << r - l << endl;
                continue;
            }
            ll minDist = 1e18;
            vector<string> candidates;

            for (const auto& kv : index) {
                if (kv.first != start && kv.first != end) {
                    candidates.push_back(kv.first);
                }
            }

            for (const string& s : candidates) {
                const vector<ll>& positions = index[s];

                auto itBefore = lower_bound(positions.begin(), positions.end(), l);
                if (itBefore != positions.begin()) {
                    ll pos = *(--itBefore);
                    minDist = min(minDist, (r - l) + 2 * (l - pos));
                }

                auto itAfter = upper_bound(positions.begin(), positions.end(), r);
                if (itAfter != positions.end()) {
                    ll pos = *itAfter;
                    minDist = min(minDist, (r - l) + 2 * (pos - r));
                }
            }

            cout << (minDist != 1e18 ? minDist : -1) << endl;
        } else {
            // cout << "CHECK" << endl;
            cout << r - l << endl;
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.precision(15);
    ll t = 1;
    cin >> t;
    ll cnt = 0;
    ll t_copy = t;
    while (t--)
    {
        cnt++;
        solve(cnt, t_copy);
    }
    return 0;
}