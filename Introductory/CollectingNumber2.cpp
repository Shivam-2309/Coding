// Author : Shivam Kapoor

// सम्मानपूर्वकं मरणं श्रेयः, अपमानपूर्वकं जीवनं न कदाचित्।
// अहं क्षत्रियः, यो युद्धभूमौ साहसं कुर्वन् अपमानेन जीवितुं न इच्छामि।

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x) cerr << #x << " = " << x << endl
#define print(v) cerr << #v << " = [ "; for (auto &el : v) cerr << el << " "; cerr << "]\n";

#define vll vector<ll>
#define rev(v) reverse(all(v))
#define srt(v) sort(all(v))
#define all(v) (v).begin(), (v).end()
#define rep(i, n) for (ll i = 0; i < (n); ++i)

const ll mod7 = 1e9 + 7;
const ll mod9 = 998244353;

void solve(){
    ll n, q; cin >> n >> q;
    vector<ll> v(n);
    for(ll i = 0; i < n; i++) cin >> v[i];
    v.insert(v.begin(), 0);

    vector<ll> pos(n + 1, 0);
    for(ll i = 1; i <= n; i++) pos[v[i]] = i;

    ll curr_ans = 0;
    set<ll> seen;
    for(ll i = 1; i <= n; i++){
        if(seen.find(v[i] - 1) == seen.end()){
            curr_ans++;
        }
        seen.insert(v[i]);
    }

    for(ll i = 1; i <= q; i++){
        ll idx1, idx2; cin >> idx1 >> idx2;
        if(idx1 > idx2) swap(idx1, idx2);

        ll nums1 = v[idx1];
        ll nums2 = v[idx2];

        ll pos_next1 = pos[nums1 + 1];
        ll pos_next1_1 = pos[nums1 - 1];
        ll pos_next2 = pos[nums2 - 1];
        ll pos_next2_2 = pos[nums2 + 1];

        if(v[idx2] + 1 == v[idx1]) curr_ans--;
        if(v[idx1] + 1 == v[idx2]) curr_ans++;

        if(pos_next1 > idx1 && pos_next1 < idx2) curr_ans++;
        if(pos_next2 > idx1 && pos_next2 < idx2) curr_ans++;
        if(pos_next1_1 > idx1 && pos_next1_1 < idx2) curr_ans--;
        if(pos_next2_2 > idx1 && pos_next2_2 < idx2) curr_ans--;

        swap(pos[v[idx1]], pos[v[idx2]]);
        swap(v[idx1], v[idx2]);;

        cout << curr_ans << endl;
    }
}

int main(){
    fast_io
    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
