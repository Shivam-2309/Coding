#include<bits/stdc++.h>
using namespace std;

#define NUM 2000000
#define ll long long

// Think about Node Structure
// Thing about Merge Logic
// Think about Leaf Value

struct node {
    ll sum = 0;
    node(){
        sum = 0;
    }
};

node merge(node a, node b){
    node ans;
    ans.sum = a.sum + b.sum;
    return ans;
}

node t[4*NUM];

void build(ll id, ll l, ll r){
    if(l == r){
        // leaf node
        t[id].sum = 0;
        return;
    }

    ll mid = (l+r)/2;

    // node array is one based indexing
    build(2*id, l, mid);
    build(2*id+1, mid+1, r);

    t[id] = merge(t[2*id], t[2*id+1]);
}

void update(ll id, ll l, ll r, ll pos, ll val){
    if(pos < l || pos > r) return;
    if(l == r){
        t[id].sum += val;
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
    ll arr[n];
    for(ll i=0; i<n; i++){
        cin >> arr[i];
    }
    // Build kro node number (1) jo range (0 -> n-1) ke liye responsible h
    build(1, 0, n-1);

    while(q--){
        ll ch;
        cin >> ch;

        if(ch == 1){
            ll a, b, u;
            cin >> a >> b >> u;
            // Converting to zeros based indexing
            a--;
            b--;

            update(1, 0, n-1, a, u);
            update(1, 0, n-1, b+1, -u);
        }
        else{
            ll k;
            cin >> k;

            k--;

            node ans = query(1, 0, n-1, 0, k);
            cout << ans.sum + arr[k] << endl;
        }   
    }


    return 0;
}