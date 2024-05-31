#include<bits/stdc++.h>
using namespace std;

#define NUM 2000000
#define ll long long

// Think about Node Structure
// Thing about Merge Logic
// Think about Leaf Value

struct node {
    ll val = 0;
    node(){
        val = 0;
    }
};

node merge(node a, node b){
    node ans;
    ans.val = a.val + b.val;
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
    // Build kro node number (1) jo range (0 -> n-1) ke liye responsible h
    build(1, 0, n-1, arr);

    while(q--){
        ll ch;
        cin >> ch;

        if(ch == 1){
            ll i, v;
            cin >> i >> v;
            // Converting to zeros based indexing

            update(1, 0, n-1, i, v);
        }
        else{
            ll l, r;
            cin >> l >> r;
            r--;

            node ans = query(1, 0, n-1, l, r);
            cout << ans.val << endl;
        }   
    }


    return 0;
}