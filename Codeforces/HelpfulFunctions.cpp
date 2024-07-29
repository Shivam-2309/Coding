#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define ll long long
void myerase(ordered_set &t, int v)
{
    int rank = t.order_of_key(v);                     // Number of elements that are less than v in t
    ordered_set::iterator it = t.find_by_order(rank); // Iterator that points to the (rank+1)th element in t
    t.erase(it);
}
/* find_by_order(K): Returns an iterator to the Kth largest element (counting from zero) */
/* order_of_key (K): Returns the number of items that are strictly smaller than K */

const ll INF = 1e17;
const ll NINF = INF*(-1);

// Function to calculate the least common multiple (LCM)
ll lcm(ll a, ll b) {
    return a * b / __gcd(a, b);
}

// Binary modular exponentiation
ll binpow(ll a, ll b) {
    if (b == 0) return 1;
    ll res = binpow(a, b / 2);
    if (b & 1) return res * res * a;
    else return res * res;
}

ll binpowmod(ll a, ll b, ll m = 1000000007) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll mminvprime(ll a, ll b) {
    return binpowmod(a, b - 2, b);
}

ll mod_add(ll a, ll b, ll m = 1000000007) {
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}

ll mod_mul(ll a, ll b, ll m = 1000000007) {
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}

ll mod_sub(ll a, ll b, ll m = 1000000007) {
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}

ll mod_div(ll a, ll b, ll m = 1000000007) {
    a = a % m;
    b = b % m;
    return (mod_mul(a, mminvprime(b, m), m) + m) % m;
}

// Precomputation for combinations in O(n) time
vector<ll> fact;
vector<ll> ifact;

void combination(int n) {
    fact.resize(n + 1);
    ifact.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = mod_mul(fact[i - 1], i, 1000000007);
    }
    ifact[n] = mminvprime(fact[n], 1000000007);
    for (int i = n - 1; i >= 0; i--) {
        ifact[i] = mod_mul(ifact[i + 1], i + 1, 1000000007);
    }
}

ll ncr1(ll n, ll r, ll m = 1000000007) {
    return mod_mul(fact[n], mod_mul(ifact[r], ifact[n - r], m), m);
}

// For individual nCr in O(r) time
int ncr2(int n, int r) {
    long long p = 1, k = 1;
    if (n - r < r) r = n - r;
    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
            long long m = __gcd(p, k);
            p /= m;
            k /= m;
            n--;
            r--;
        }
    } else {
        p = 1;
    }
    return p;
}

// Sieve of Eratosthenes for precomputation of primes in Nlog(log(N))
vector<bool> isprime;
vector<ll> spf;

void sieve(ll n = 1e6) {
    isprime.resize(n + 1, true);
    // spf -> smallest prime factor
    spf.resize(n + 1, 1000000);
    isprime[0] = isprime[1] = false;

    for (ll i = 2; i <= n; i++) {
        if (isprime[i]) {
            spf[i] = i;
            for (ll j = i * i; j <= n; j += i) {
                isprime[j] = false;
                spf[j] = min(spf[j], i);
            }
        }
    }
}

vector<pair<int, int>> primefactorisation(int x) {
    vector<pair<int, int>> ans;
    while (x != 1) {
        int prime = spf[x];
        int cnt = 0;
        while (x % prime == 0) {
            cnt++;
            x /= prime;
        }
        ans.push_back({prime, cnt});
    }
    return ans;
}

// for making the union

class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

// for finding the single source shortest path
// Assumption is made that the graph must not have any negative weights or negative cycle
// Works for both the Directed and undirected edge

// TC -> O(ElogV)

vector<ll> dijkstra(ll V, vector<vector<ll>> adj[], ll S) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll> distTo(V+1, LLONG_MAX);

    distTo[S] = 0;
    pq.push({0ll, S});
    vector<ll> vis(V+1, 0);

    while (!pq.empty()) {
        ll node = pq.top().second;
        ll dis = pq.top().first;
        pq.pop();

        if(vis[node]) continue;
        vis[node] = 1;

        for (auto &it : adj[node]) {
            ll v = it[0];
            ll w = it[1];
            if (dis + w < distTo[v]) {
                distTo[v] = dis + w;
                pq.push({dis + w, v});
            }
        }
    }
    return distTo;
}

// For finding the minimum distance between any two nodes 
// Floyd Warshal Algorithm -> O(N^3)
// SC -> O(N^2)

vector<vector<ll>> floydWarshal(ll n, vector<vector<ll>> &edges){
    vector<vector<ll>> mat(n+1 ,vector<ll> (n+1, 1e18));
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=n; j++){
            if(i == j) mat[i][j] = 0;
        }
    }

    for(auto edge : edges){
        ll u = edge[0];
        ll v = edge[1];
        ll wt = edge[2];

        mat[u][v] = min(mat[u][v], wt);
        mat[v][u] = min(mat[u][v], wt);
    }

    for(ll k=1; k<=n; k++){
        for(ll i=1; i<=n; i++){
            for(ll j=1; j<=n; j++){
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }

    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=n; j++){
            if(mat[i][j] == 1e18) mat[i][j] = -1;
        }
    }
}

// For finding the bridges of the graph
// use an object to access this piece of code
class Bridges {
private:
    int timer = 1;

    void dfsForBridges(ll node, ll parent, vector<ll> adj[], vector<ll> &vis, vector<vector<ll>> &bridges, ll dfsInsertionTime[], ll lowestInsertionTime[]) {
        vis[node] = 1;
        dfsInsertionTime[node] = lowestInsertionTime[node] = timer++;
        
        for (auto child : adj[node]) {
            if (child == parent) continue;

            if (!vis[child]) {
                dfsForBridges(child, node, adj, vis, bridges, dfsInsertionTime, lowestInsertionTime);

                if (lowestInsertionTime[child] > dfsInsertionTime[node]) {
                    bridges.push_back({node, child});
                }
                lowestInsertionTime[node] = min(lowestInsertionTime[node], lowestInsertionTime[child]);
            } else {
                lowestInsertionTime[node] = min(lowestInsertionTime[node], dfsInsertionTime[child]);
            }
        }
    }

public:
    vector<vector<ll>> getAllBridges(ll n, vector<ll> adj[]) {
        vector<vector<ll>> bridges;
        vector<ll> vis(n + 1, 0);
        ll dfsInsertionTime[n + 1];
        ll lowestInsertionTime[n + 1];
        memset(dfsInsertionTime, 0, sizeof(dfsInsertionTime));
        memset(lowestInsertionTime, 0, sizeof(lowestInsertionTime));

        for (ll i = 1; i <= n; i++) {
            if (!vis[i]) {
                dfsForBridges(i, -1, adj, vis, bridges, dfsInsertionTime, lowestInsertionTime);
            }
        }

        return bridges;
    }
};
ll getSubtrees(ll node, vector<ll> adj[], vector<ll> &vis, vector<ll> &subtree) {
    vis[node] = 1;
    ll currSize = 1;

    for (auto &child : adj[node]) {
        if (!vis[child]) {
            currSize += getSubtrees(child, adj, vis, subtree);
        }
    }
    return subtree[node] = currSize;
}

// Single Source Shortest Path in the presence of negative weights and negative cycle
// TC -> O(V*E)

struct triplet{
	int first;
	int second;
	int third;
};

void bellman_ford(ll n, vector<triplet> &edges, vector<ll> &dist)
{
	for(int i = 1; i < n; ++i)
	{
		for(auto e: edges)
		{
			int u = e.first;
			int v = e.second;
			int d = e.third;
			if(dist[u] == INF) continue;
			dist[v] = min(dist[v], d+dist[u]);
			dist[v] = max(dist[v], NINF);
		}
	} // n relaxations
 
	for(int i = 1; i < n; ++i)
	{
		for(auto e: edges)
		{
			int u = e.first;
			int v = e.second;
			int d = e.third;
			if(dist[u] == INF) continue;
			dist[v] = max(dist[v], NINF);
			if(dist[u]+d < dist[v])
			{
				dist[v] = NINF;
			}
		}
	}
}

// get the farthest node from each node in O(N) time complexity
vector<ll> getNodeLevels(vector<vector<ll>>& adj, ll n, ll source) {
    vector<ll> levels(n, 0);
    queue<ll> q;
    q.push(source);
    vector<ll> vis(n, 0);
    vis[source] = 1;
    ll currLevel = 0;

    while (!q.empty()) {
        ll sz = q.size();
        for (ll i = 0; i < sz; i++) {
            ll node = q.front();
            q.pop();

            levels[node] = currLevel;

            for (auto &child : adj[node]) {
                if (!vis[child]) {
                    vis[child] = 1;
                    q.push(child);
                }
            }
        }
        currLevel++;
    }

    return levels;
}

vector<ll> findDiameter(vector<vector<ll>>& adj, ll n) {
    vector<ll> farthestNodes = getNodeLevels(adj, n, 0);
    ll farthestNode = -1;
    ll maxi = *max_element(farthestNodes.begin(), farthestNodes.end());

    for (ll i = 0; i < n; i++) {
        if (farthestNodes[i] == maxi) {
            farthestNode = i;
            break;
        }
    }

    vector<ll> farthestNodes1 = getNodeLevels(adj, n, farthestNode);
    ll maxi1 = *max_element(farthestNodes1.begin(), farthestNodes1.end());
    ll secondFarthestNode = -1;

    for (ll i = 0; i < n; i++) {
        if (farthestNodes1[i] == maxi1) {
            secondFarthestNode = i;
            break;
        }
    }

    ll endOne = farthestNode;
    ll endTwo = secondFarthestNode;

    vector<ll> fromOne = getNodeLevels(adj, n, endOne);
    vector<ll> fromTwo = getNodeLevels(adj, n, endTwo);

    vector<ll> distanceOfFarthestNodeFromEachNode(n, 0);

    for (ll i = 0; i < n; i++) {
        distanceOfFarthestNodeFromEachNode[i] = max(fromOne[i], fromTwo[i]);
    }

    return distanceOfFarthestNodeFromEachNode;
}

// Code Snippet for segment trees
#define NUM 2000000

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
        t[id].val += val;
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

// This is a Trie Implementation 

struct Node {
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie {
    private:
        Node* root;
    public: 

    Trie() {
        root = new Node();
    }

    void insert(string word){
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            if(!node -> containsKey(word[i])){
                node -> put(word[i], new Node());
            }
            node = node -> get(word[i]);
        }
        node -> setEnd();      
    }

    bool search(string word){
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            if(!(node -> containsKey(word[i]))){
                return false;
            }
            node = node -> get(word[i]);
        }
        return node -> isEnd();
    }

    bool startWith(string prefix){
        Node* node = root;
        for(int i=0; i<prefix.length(); i++){
            if(!(node -> containsKey(prefix[i]))){
                return false;
            }
            node = node -> get(prefix[i]);
        }
        return true;
    }
};

// Binary Lifting to find the Kth Ancestor in O(logN) time
class TreeAncestor {
private:
    vector<vector<int>> up;
    int log;
public:
    TreeAncestor(int n, vector<int>& parent) {
        log = ceil(log2(1e9));
        up.resize(n, vector<int> (log+1, -1));
        // Binary lifting
        // The 2^0th ancestor is the parent itself
        for(int i=0; i<n; i++){
            up[i][0] = parent[i];
        }

        // updating the up vector for each ancestor
        for(int j = 1; j < log; j++){
            for(int i = 0; i < n; i++){
                if(up[i][j-1] != -1){
                    up[i][j] = up[up[i][j-1]][j-1];
                }
                else{
                    up[i][j] = -1;
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        if(k == 1) return up[node][0];

		int ans = node;
		for(int j = 0; j <= log; j++) 
		{
			if(k & (1 << j))
			{
				ans = up[ans][j];
				if(ans==-1) break;
			}
		}
		return ans;
    }
};

void solve() {
    cout << "THESE ARE ALL THE REQUIRED FUNCTIONS" << endl;
}

int main() {
    ll t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
