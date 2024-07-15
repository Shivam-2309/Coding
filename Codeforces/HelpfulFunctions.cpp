#include <bits/stdc++.h>
using namespace std;

#define ll long long

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;
/* find_by_order(K): Returns an iterator to the Kth largest element (counting from zero) */
/* order_of_key (K): Returns the number of items that are strictly smaller than K */

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

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distTo(V, INT_MAX);

    distTo[S] = 0;
    pq.push({0, S});

    while (!pq.empty()) {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();

        for (auto it : adj[node]) {
            int v = it[0];
            int w = it[1];
            if (dis + w < distTo[v]) {
                distTo[v] = dis + w;
                pq.push({dis + w, v});
            }
        }
    }
    return distTo;
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
