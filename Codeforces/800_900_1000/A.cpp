#include <iostream>
#include <unordered_map>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

int largest_subsequence_length(vector<int>& arr, int k) {
    int n = arr.size();
    for(int i=0; i<n; i++){
        arr[i] = arr[i]%k;
    }

    set<int> st;
    for(int i=0; i<n; i++) st.insert(arr[i]);

    int maxLen = 2;

    for(auto &it: st){
        int v = it;
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(arr[i] == v) cnt++;
        }

        maxLen = max(maxLen, cnt);
    }

    vector<int> t;
    for(auto &it: st){
        t.push_back(it);
    }

    map<int, vector<int>> mp;
    for(int i=0; i<n; i++){
        mp[arr[i]].push_back(i);
    }

    for(int i=0; i<t.size(); i++){
        for(int j=0; j<t.size(); j++){
            int num1 = t[i];
            int num2 = t[j];

            if(num1 == num2) continue;

            vector<int> v1 = mp[num1];
            vector<int> v2 = mp[num2];

            vector<pair<int, int>> v4;
            for(int i=0; i<v1.size(); i++){
                v4.push_back({v1[i], -1});
            }
            for(int i=0; i<v2.size(); i++){
                v4.push_back({v2[i], -2});
            }

            sort(v4.begin(), v4.end());

            bool f = true;
            // true -> find -1
            // false -> find -2
            int len = 0;
            int k = 0;
            while(true){
                if(f){
                    while(k < v4.size()){
                        if(v4[k].second == -1){
                            f = !f;
                            len++;
                            break;
                        }
                        k++;
                    }
                }
                else{
                    while(k < v4.size()){
                        if(v4[k].second == -2){
                            f = !f;
                            len++;
                            break;
                        }
                        k++;
                    }
                }
                if(k >= v4.size()) break;
            }

            maxLen = max(maxLen, len);
        }
    }

    return maxLen;
}

int main() {
    vector<int> arr = {2,2,2,2,2,2,2,2,2,2,5,2};
    int K = 3;
    cout << largest_subsequence_length(arr, K) << endl; 
    return 0;
}