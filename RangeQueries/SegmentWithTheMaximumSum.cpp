#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define max3(a, b, c) max(max(a, b), c)
#define NUM 200007

class node {
public:
    ll pref, suf, seg, sum;
    node() : pref(0), suf(0), seg(0), sum(0) {}
    node(ll p, ll s, ll se, ll su) : pref(p), suf(s), seg(se), sum(su) {}
};

node t[4 * NUM];

node merge(node a, node b) {
    return node(
        max(a.pref, a.sum + b.pref),
        max(b.suf, b.sum + a.suf),
        max3(a.seg, b.seg, a.suf + b.pref),
        a.sum + b.sum
    );
}

void build(ll id, ll l, ll r, vector<ll> &a) {
    if (l == r) {
        if (a[l] > 0) {
            t[id] = node(a[l], a[l], a[l], a[l]);
        } else {
            t[id] = node(0, 0, 0, a[l]);
        }
        return;
    }

    ll mid = (l + r) / 2;

    build(2 * id, l, mid, a);
    build(2 * id + 1, mid + 1, r, a);

    t[id] = merge(t[2 * id], t[2 * id + 1]);
}

void update(ll id, ll l, ll r, ll pos, ll value) {
    if (pos < l || pos > r) {
        return;
    }

    if (l == r) {
        // position is found
        if (value > 0) {
            t[id] = node(value, value, value, value);
        } else {
            t[id] = node(0, 0, 0, value);
        }
        return;
    }

    ll mid = (l + r) / 2;

    update(2 * id, l, mid, pos, value);
    update(2 * id + 1, mid + 1, r, pos, value);

    t[id] = merge(t[2 * id], t[2 * id + 1]);
}

int main() {
    ll n, m;
    cin >> n >> m;

    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) cin >> arr[i];

    build(1, 0, n - 1, arr);

    cout << t[1].seg << endl;

    while (m--) {
        ll pos, val;
        cin >> pos >> val;

        update(1, 0, n - 1, pos, val);
        cout << t[1].seg << endl;
    }

    return 0;
}
