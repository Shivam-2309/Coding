#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define NUM 2000007

struct node {
    ll val = 0;
    node(){
        val = 0;
    }
};

node merge(node a, node b){
    node ans;
    ans.val = (a.val ^ b.val);
    return ans;
}

node t[4*NUM];

void build(ll id, ll l, ll r, vector<ll> &nums){
    if(l == r){
        // leaf node
        t[id].val = nums[l];
        return;
    }

    ll mid = (l+r)/2;

    // node array is one based indexing
    build(2*id, l, mid, nums);
    build(2*id+1, mid+1, r, nums);

    t[id] = merge(t[2*id], t[2*id+1]);
}

void update(ll id, ll l, ll r, ll pos, ll val){
    if(pos < l || pos > r) return;
    if(l == r){
        t[id].val = val;
        return;
    }

    ll mid = (l+r)/2;
    update(2*id, l, mid, pos, val);
    update(2*id+1, mid+1, r, pos, val);

    t[id] = merge(t[2*id], t[2*id + 1]);
}

node query(ll id, ll l, ll r, ll leftQ, ll rightQ){
    if((leftQ>r) || (l>rightQ)){
        return node();
    }
    if((leftQ<=l) && (r<=rightQ)){
        return t[id];
    }
    ll mid = (l+r)/2;
    return merge(query(2*id, l, mid, leftQ, rightQ), query(2*id+1, mid+1, r, leftQ, rightQ));
}


int main(){
    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++){
        cin >> arr[i];
    }

    build(1, 0, n-1, arr);

    while(q--){
        ll a, b;
        cin >> a >> b;
        a--;
        b--;

        node res = query(1, 0, n-1, a, b);
        cout << res.val << endl;
    }

    return 0;
}