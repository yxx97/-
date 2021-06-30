#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<functional>
using namespace std;


class Trie {
public:
    /** Initialize your data structure here. */
    vector<Trie*> next;
    bool isend ;
    Trie() :next(26,nullptr),isend(false){

    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* root = this;
        for(auto ch : word){
          
            if(root->next[ ch-'a']==nullptr) root->next[ ch-'a'] = new Trie();
            root = root->next[ ch-'a']; 
        }
        root->isend = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* root = this;
        for(auto ch : word){
            
            if(root->next[ ch-'a']==nullptr) return false;
            root = root->next[ ch-'a'];
        }
        return root->isend;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* root = this;
        for(auto ch : prefix){
            
            if(root->next[ ch-'a']==nullptr) return false;
            root = root->next[ ch-'a'];
        }
       return true;

    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */