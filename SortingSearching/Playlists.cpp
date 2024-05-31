#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define endl "\n"
#define INF 1e18
#define all(x) (x).begin(), (x).end()
 
void solve(){
  ll n;
  cin >> n;
 
  vector<ll> v(n);
  for(ll i=0; i<n; i++){
    cin >> v[i];
  }
 
  ll maxLen = 0;
  set<ll> st;
  ll left = 0;
  ll right = 0;
 
  while(right < n){
    if(st.find(v[right]) == st.end()){
      st.insert(v[right]);
      maxLen = max(maxLen, right - left + 1);
      right++;
    }
    else{
      st.erase(v[left]);
      left++;
    }
  }
  cout << maxLen << endl;
}
 
signed main(){
    int tc;
    tc = 1;
    while(tc--){
        solve();
    }
    return 0;
}