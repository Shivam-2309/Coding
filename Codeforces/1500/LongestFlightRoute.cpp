// [Author:   Jivtesh Srivastava]
#include <iostream>
#include <fstream>
// #include<bits/stdc++.h>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cstdlib>
#include <stdlib.h>
#include <deque>
#include <list>
#include <iterator>
#include <random>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <math.h>
#include <set>
#include <map>
#include <string>
#include <tuple>
#include <numeric>
#include <climits>
#include <bitset>
#include <iomanip>
#include <random>
#include <ctime>
#include <string.h>
#include <utility>
using namespace std;
#define int long long
#define uint unsigned long long
#define endl "\n"
const int mod = 1e9+7;
#define inf 1e18
//*************************************SIEVE OF ERASTHOTHENES***************************************************************************
const int N=1e6;
int check[N+1];
vector<int> primes;
void sieve(){
   check[0]=0;
   check[1]=0;
   for(int i=2;i<=N;i++){
      check[i]=i;
   }
 
   for(int i=2;i*i<=N;i++){
      if(check[i]==i){
         for(int j=i*i;j<=N;j+=i){
            if(check[j]==j) check[j]=i;
         }
      }
   }
 
   for(int i=2;i<=N;i++){
      if(check[i]==i) primes.push_back(i);
   }
 
}
 
// ********************************************MODULAR EXPONENTIATION*********************************************************************
int power_expo(int x, int y, int m)
{
   int res = 1;
   while (y > 0)
   {
      if (y & 1)
         res = (((res % m) * (x % m)) % m);
      y = (y >> 1);
      x = (((x % m) * (x % m)) % m);
   }
   return (res % m);
}
 
// ********************************************************************DSU**************************************************************
class dsu
{
public:
   vector<int> size, parent;
   dsu(int n)
   {
      size.resize(n + 1);
      parent.resize(n + 1);
      for (int i = 0; i <= n; i++) parent[i] = i;
      for (int i = 0; i <= n; i++) size[i] = 1;
   }
 
   int findUP(int node)
   {
      if (parent[node] == node)
         return node;
      return parent[node] = findUP(parent[node]);
   }
 
   void unionBySize(int u, int v)
   {
      int up = findUP(u);
      int vp = findUP(v);
 
      if (up == vp)
         return;
 
      if (size[up] > size[vp])
      {
         size[up] += size[vp];
         parent[vp] = up;
      }
      else
      {
         size[up] += size[vp];
         parent[vp] = up;
      }
   }
};
 
// ********************************************************************LONGEST PREFIX SUFFIX***********************************************
vector<int> lps(string &s){
   int n=s.length();
   vector<int> ans(n);
   int pre=0,suff=1;
   while(suff<n){
      // match
      if(s[pre]==s[suff]){
         s[suff]=pre+1;
         pre++;
         suff++;
      }
      else{
         // no match
         if(pre==0){
            s[suff]=0;
            suff++;
         }
         else pre=ans[pre-1];
      }
   }
   return ans;
}
// **************************************************************MAIN FUNCTION*********************************************************************************************
void solve(){
 
   int n,m;
   cin>>n>>m;
 
   vector<set<int>> adj(n+1);
   // vector<int> indegree(n+1);
   for(int i=0;i<m;i++){
      int u,v;
      cin>>u>>v;
      adj[u].insert(v);
      // indegree[v]++;
   }
 
   
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
   pq.push({0,1});
   // stops,node
   vector<int> stop(n+1),parent(n+1);
   for(int i=1;i<=n;i++) parent[i]=-1;
   stop[1]=0;
   while(!pq.empty()){
      int node=pq.top().second;
      int stops=pq.top().first;
      pq.pop();
      if(stops>stop[node]) continue;
      for(auto it:adj[node]){
         if((stops-1)<stop[it]){
            stop[it]=stops-1;
            parent[it]=node;
            pq.push({stops-1,it});
         }
      }
   }
 
 
   if(parent[n]==-1) cout<<"IMPOSSIBLE"<<endl;
   else{
      // cout<<"YES"<<endl;
 
      vector<int> vec;
      int node=n;
      while(node!=-1){
         vec.push_back(node);
         node=parent[node];
      }
      // vec.push_back(node);
      reverse(vec.begin(),vec.end());
      // cout<<vec.size()<<endl;
      cout<<1+stop[n]*(-1)<<endl;
      for(auto it:vec) cout<<it<<" ";
      cout<<endl;
      // for(auto it:stop) cout<<it<<" ";
      // cout<<endl;
      // for(auto it:parent) cout<<it<<" ";
      // cout<<endl;
   }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
   
   
 
 
 
 
 
 
 
}
 
 
 
int32_t main()
{ 
 
   ios_base::sync_with_stdio(false);
   // std::cin.tie(NUint);
   // sieve();
   // uint t;
   // std::cin >> t;
   // while (t--)
   // {
         solve();
   // }
 
   return 0;
}