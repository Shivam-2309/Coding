#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie{
    Node* root;
    public:
    Trie(){
        root = new Node();
    }

    void insert(string word){
        int len = word.length();
        Node* node = root;

        for(int i=0; i<len; i++){
            if(!(node -> containsKey(word[i]))){
                node -> put(word[i], new Node());
            }
            node = node -> get(word[i]);
        }
        node -> setEnd();
    }

    bool search(string word){
        int len = word.length();
        Node* node = root;
        for(int i=0; i<len; i++){
            if(!(node -> containsKey(word[i]))){
                return false;
            }
            node = node -> get(word[i]);
        }

        return node -> isEnd();
    }

    bool prefixPresence(string word){
        int len = word.length();
        Node* node = root;
        for(int i=0; i<len; i++){
            if(!(node -> containsKey(word[i]))){
                return false;
            }
            node = node -> get(word[i]);
        }

        return true;
    }

};

class Queue{
    public:
    vector<int> arr;
    int start;
    int end;
    int currSize;
    int maxSize;

    Queue(){
        arr.resize(10000);
        start = -1;
        end = -1;
        currSize = 0;
        maxSize = 10000;
    }

    void push(int val){
        if(currSize == maxSize){
            cout << "Sorry the queue is full \n Exiting..." << endl;
            exit(1);
        }
        if(end == -1){
            start = 0;
            end = 0;
        }
        else{
            end = (end + 1)%maxSize;
        }
        arr[end] = val;
        currSize++;
    }

    void pop(){
        if(start == -1){
            cout << "Sorry it is empty \n Exiting..." << endl;
            exit(1);
        }

        if(currSize == 1){
            start = -1;
            end = -1;
        }
        else{
            start = (start + 1)%maxSize;
        }
        currSize--;
    }

    int getFront(){
        cout << arr[start] << endl;;
    }
};

int main(){
    Trie trie;
    trie.insert("shivam");
    trie.insert("shiwam");
    trie.insert("shivani");

    if(trie.search("shivam")){ cout << "YES shivam is Present" << endl; }
    else{ cout << "NO shivam is not present" << endl;}

    if(trie.search("shivaaaaam")){ cout << "YES this wierd word is present" << endl; }
    else { cout << "NO this weird word is not present" << endl; }
    
    return 0;
}