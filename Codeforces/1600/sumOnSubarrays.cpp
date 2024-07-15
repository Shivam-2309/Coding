/*
  ------------------------------------------
 |                                        |
 |      Code Crafted by Saurav     |
 |                                        |
  ------------------------------------------
    \        ,     ,        /
      \      |     |      /
         \   \___/   /
           \  -----  /
             \_____/
  
  Happy coding! 
*/
 
/* includes and all */
 
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#define print(v) do { \
                    cout << "vect--" << #v << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << v[i] << " "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;
 
/* write core logic here */
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> ans(n, -1);
 
    // for(int i = 0; i<n; i++){
    //     ans[i] = i+1;
    //     ans[i] *= -1;
    // }
 
    print(ans);
    vector<int> prf(n, -1);
 
    for(int i = 1; i<n; i++){
        prf[i] = prf[i-1] + ans[i];
    }
 
   
    print(prf);
 
    vector<int> store;
    int n_copy = n;
    int cnt = 0;
    while(k > 0  and cnt < 50){
        debug(k);
        if(k>n_copy){
            store.push_back(n_copy);
            k -= n_copy;
            n_copy --;
        }
        else{
            store.push_back(k);
            break;
        }
        cnt++;
    }
 
    print(store);
 
    print(ans);
    reverse(store.begin(), store.end());
 
    for(int i = 0 ; i<store.size(); i++){
        int curr = store[i];
        curr--;
        int cursum = 0;
        for(int j = 0; j<curr; j++){
            if(ans[j]<0) cursum += ans[j];
        }
        debug(cursum);
        ans[curr] = abs(cursum) + 1;
        debug(ans[curr]);
 
 
        for(int j = curr+1 ; j<n; j++){
            if(j>0) {
                ans[j] = abs(ans[j-1]);
                if(ans[j-1] == ans[j]) ans[j]++;
                ans[j] *= -1;
            }
        }
    }
 
    for(auto ele : ans){
        cout<<ele<<" ";
    }
 
    cout<<endl;
 
 
    
}
/* logic ends */
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}