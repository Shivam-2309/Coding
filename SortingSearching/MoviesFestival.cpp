#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define pb push_back
#define sz(x) static_cast<ll>((x).size())
#define pyes cout << "Yes\n"
#define pno cout << "No\n"
#define ce cout << '\n'
#define endl '\n'
#define fi first
#define se second
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end())
#define all(v) v.begin(), v.end()
#define mnv(v) *min_element(v.begin(), v.end())
#define mxv(v) *max_element(v.begin(), v.end())
#define vll vector<ll>
#define vp vector<pair<long long, long long>>
#define trav(v) for (auto it = v.begin(); it != v.end(); it++)
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
 
const ll mod7 = 1e9 + 7;
const ll mod9 = 998244353;
 
bool cmp(pair<ll, ll> &p1, pair<ll, ll> &p2){
  return p2.second > p1.second;
}
 
void solve(){
    ll n;
    cin >> n;
 
    vector<pair<ll, ll>> v(n);
    for(ll i=0; i<n; i++){
      cin >> v[i].first >> v[i].second;
    }
 
    sort(v.begin(), v.end(), cmp);
 
    // Now I have sorted the values based on the value of the ending indexes
    ll cnt = 0;
    ll i = 0;
    ll end_of_last_movie = -1;
 
    while(i < n){
      if(v[i].first >= end_of_last_movie){
        cnt++;
        end_of_last_movie = v[i].second;
        i++;
      }
      else{
        i++;
      }
    }
    cout << cnt;
}
// clear all data structures between test cases
// handle all corner cases
// confusing between n and m , i and j?
// uninitialized variables?
 
int main()
{
    ll t;
    t=1;
    while(t--){
      solve();
    }
   return 0;
}
