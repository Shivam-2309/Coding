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
                    cout << "]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#endif
#define ll long long
#define vll vector<ll>
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end());
#define rep(i, n) for (ll i = 0; i < n; i++)
const ll mod7 = 1e9 + 7;
const ll mod9 = 998244353;
ll power(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return res;
}
ll lcm(ll a, ll b)
{
    return a * b / __gcd(a, b);
}
// ll dp[100001];

bool dfs(ll node, vector<ll> &vis, vector<ll> &recStack, stack<ll> &st, vector<ll> adj[]){
    vis[node] = 1;
    recStack[node] = 1;
    st.push(node);

    for(auto child : adj[node]){
        if(!vis[child]){
            if(dfs(child, vis, recStack, st, adj)){
                return true;
            }
        }
        else if(recStack[child] == 1){
            // found the cycle
            st.push(child);
            return true;
        }
    }

    recStack[node] = 0;
    st.pop();

    return false;
}

vector<ll> findCycle(stack<ll>&st){

	   ll node = st.top();

	   vector<ll>cycle;

	   cycle.push_back(node);

	   st.pop();

	   while(!st.empty()){
	   	   cycle.push_back(st.top());
           if(st.top() == node){
           	  break;
           }
           st.pop();
	   }

	   return cycle;
}
void solve(){
    // This question is all about Topo Sort based algorithm
    // Here i will detect a cycle using a stack
    // This is used in Kahn's Aglorithm

    ll n, m; cin >> n >> m;
    vector<ll> adj[n+1];
    for(ll i=0; i<m; i++){
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<ll> vis(n+1, 0);
    vector<ll> recStack(n+1, 0);
    stack<ll> st;

    for(ll i=1; i<=n; i++){
        if(!vis[i]){
            if(dfs(i, vis, recStack, st, adj)){
                // extract the cycle from stack
                // cout << "YES" << endl;
                vector<ll> cycle = findCycle(st);
                cout << cycle.size() << endl;
                rev(cycle);
                for(auto it : cycle) cout << it << " ";
                cout << endl;
                return;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.precision(15);
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*     The code finishes, I hope it gets Accepted      */