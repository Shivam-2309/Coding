#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define NUM 200007

struct node {
    ll val = 1e18;
    ll cnt = 0;
    node (){
        val = 1e18;
        cnt = 0;
    }
};

node t[4*NUM];

node merge(node a, node b){
    node ans;
    ll v1 = a.val;
    ll v2 = b.val;

    if(v1 < v2){
        ans.val = v1;
        ans.cnt = a.cnt;
    }
    else if(v1 > v2){
        ans.val = v2;
        ans.cnt = b.cnt;
    }
    else{
        ans.val = v1;
        ans.cnt = a.cnt + b.cnt;
    }
    return ans;
}

void build(ll id, ll l, ll r, vector<ll> &arr){
    if(l == r){
        t[id].val = arr[l];
        t[id].cnt = 1;
        return;
    }

    ll mid = (l + r)/2;

    build(2*id, l, mid, arr);
    build(2*id+1, mid+1, r, arr);

    t[id] = merge(t[2*id], t[2*id+1]);
}

void update(ll id, ll l, ll r, ll pos, ll value){
    if(l> pos || r<pos){
        return;
    }
    if(l == r){
        t[id].val = value;
        t[id].cnt = 1;
        return;
    }

    ll mid = (l+r)/2;

    update(2*id, l, mid, pos, value);
    update(2*id+1, mid+1, r, pos, value);

    t[id] = merge(t[2*id], t[2*id + 1]);
}

node query(ll id, ll l, ll r, ll lq, ll rq){
    if(lq > r || l > rq){
        return node();
    }

    if((lq<=l) && (r<=rq)){
        return t[id];
    }
    ll mid = (l+r)/2;
    return merge(query(2*id, l, mid, lq, rq), query(2*id+1, mid+1, r, lq, rq));
}

int main(){
    ll n, q;
    cin >> n >> q;

    vector<ll> arr(n);
    for(ll i=0; i<n; i++) cin >> arr[i];

    build(1, 0, n-1, arr);

    while(q--){
        ll ch; cin >> ch;

        if(ch == 1){
            ll pos, value;
            cin >> pos >> value;

            update(1, 0, n-1, pos, value);
        }
        else{
            ll l, r;
            cin >> l >> r;
            r--;

            node ans = query(1, 0, n-1, l, r);
            cout << ans.val << " " << ans.cnt << endl;
        }
    }
}



