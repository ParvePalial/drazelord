#include <bits/stdc++.h>

using namespace std;

class Trie{
    public:
        vector<Trie*> trie;
        bool isend;
        Trie(){
            trie.resize(10);
            for (int i=0; i<10; i++) trie[i] = nullptr;
            isend = false;
        }

        void insert(int word){
            string s = to_string(word);
            Trie *curr = this;

            for (auto i: s){
                int ind = i-'0';
                if (!curr->trie[ind]) curr->trie[ind] = new Trie();
                curr = curr->trie[ind];
            }
            curr->isend = true;
        }

        int getpre(int word){
            string s = to_string(word);
            Trie *curr = this;
            int len =0;

            for (auto i: s){
                int ind = i-'0';
                if (!curr->trie[ind]) break; // curr->trie[ind] = new Trie();
                curr = curr->trie[ind];
                len++;
            }
            return len;
        }

};


class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie *root = new Trie();
        for (auto i: arr1){
            root->insert(i);
        }

        int ans = INT_MIN;
        for (auto i: arr2){
            ans = max(ans, root->getpre(i));
        }

        return ans;
    }
};


/*
    1 2 3 
    
    
*/