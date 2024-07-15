
#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n,t,u,v;
    cin >> n >> t;
 
    vector<int> adj[n+1];
    for( int i = 0 ; i < n-1 ; i++ ){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> t;
 
    int c = 0, parent = -1;
    while( adj[t].size() != 1 ){
        if( adj[t][0] != parent ){
            parent = t;
            t = adj[t][0];
        }else{
            parent = t;
            t = adj[t][1];
        }
        c++;
    }
    if( c % 2 || (n - c - 1) % 2) cout << "Ron" << endl;
    else cout << "Hermione" << endl;
 
    return 0;
}