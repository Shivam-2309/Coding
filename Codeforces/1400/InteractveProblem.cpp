#include<bits/stdc++.h>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    int l = 1, r = 1000000;
    int ans = -1;
    while(l <= r){
        int mid = (l + r)/2;
        cout << mid << endl;
        cout << flush;
        string s; cin >> s;

        if(s == "<"){
            r = mid - 1;
        }
        else{
            ans = mid;
            l = mid + 1;
        }
    }

    cout << "! " << ans << endl;
    cout << flush;
}