#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod7 1000000007

// void dfs(ll node, vector<pair<ll, ll>> adj[], stack<ll> &st, vector<ll> &vis, ll &minPathLength, ll &maxPathLength, ll n, ll &minCost, ll cost) {
//     st.push(node);
//     vis[node] = 1;


//     if (node == n && cost == minCost) {
//         minPathLength = min(minPathLength, (ll)st.size() - 1);
//         maxPathLength = max(maxPathLength, (ll)st.size() - 1);
//     } else {
//         for (auto &child : adj[node]) {
//             if (!vis[child.first]) {
//                 dfs(child.first, adj, st, vis, minPathLength, maxPathLength, n, minCost, cost + child.second);
//             }
//         }
//     }

//     vis[node] = 0;
//     st.pop();
// }


int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> edges;

    for (ll i = 0; i < m; i++) {
        ll u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }

    vector<pair<ll, ll>> adj[n + 1];
    for (ll i = 0; i < m; i++) {
        ll u = edges[i][0];
        ll v = edges[i][1];
        ll wt = edges[i][2];

        adj[u].push_back({v, wt});
    }

    // Dijkstra's
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll> dist(n + 1, 1e18); 
    vector<ll> ways(n + 1, 0);
    vector<ll> minPath(n + 1, 1e18);
    vector<ll> maxPath(n + 1, -1e18);
    dist[1] = 0;
    ways[1] = 1;
    minPath[1] = 0;
    maxPath[1] = 0;
    pq.push({0, 1}); 

    while (!pq.empty()) {
        auto frontNode = pq.top();
        pq.pop();

        ll currWt = frontNode.first;
        ll node = frontNode.second;

        if (dist[node] < currWt) continue;

        for (auto adjacentNode : adj[node]) {
            ll sideNode = adjacentNode.first;
            ll edgeWt = adjacentNode.second;

            if (dist[sideNode] > currWt + edgeWt) {
                minPath[sideNode] = 1 + minPath[node];
                maxPath[sideNode] = 1 + maxPath[node];
                dist[sideNode] = currWt + edgeWt;
                ways[sideNode] = ways[node];
                pq.push({dist[sideNode], sideNode});
            } else if (dist[sideNode] == currWt + edgeWt) {
                minPath[sideNode] = min(minPath[sideNode] , 1 + minPath[node]);
                maxPath[sideNode] = max(maxPath[sideNode], 1 + maxPath[node]);
                ways[sideNode] = (ways[sideNode]%mod7 + ways[node]%mod7)%mod7;
            }
        }
    }

    cout << dist[n] << " " << ways[n]%(mod7) << " " << minPath[n] << " " << maxPath[n] << endl;

    return 0;
}
