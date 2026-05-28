class Trie{
    public:
        Trie* trie[26];
        bool isend;
        int bestind;

    Trie(){

        for (int i=0; i<26; i++) trie[i]=nullptr;
        isend = false;
        bestind = -1;
    }

    void updateBest(vector<string>& wc, int newI) {
        if (bestind == -1) {
            bestind = newI;
            return;
        }
        
        if (wc[newI].length() < wc[bestind].length()) {
            bestind = newI;
        } 
        else if (wc[newI].length() == wc[bestind].length()) {
            if (newI < bestind) bestind = newI;
        }
    }

    void insert(string& s, int i, vector<string>& wc){
        Trie* curr= this;
        curr->updateBest(wc,i);
        for (auto& c: s){
            int ind = c-'a';
            
            if (!curr->trie[ind]) curr->trie[ind] = new Trie();
            
            curr = curr->trie[ind];
            curr->updateBest(wc,i);
        }

        curr->isend = true;
        
    }

    int getprefix(string& s){
        Trie* curr= this;
        for (auto& c: s){
            int ind = c-'a';
            if (!curr->trie[ind]) return curr->bestind;
            curr = curr->trie[ind];
        }
        return curr->bestind;
    }
};


class Solution {
public:
    vector<int> stringIndices(vector<string>& wc, vector<string>& wq) {
        int nc = wc.size(), nq =  wq.size();
        vector<int> ans;
        Trie* root = new Trie();

        for (int i=0; i<nc;i++) {
            reverse(wc[i].begin(), wc[i].end());
            root->insert(wc[i],i, wc);
        }

        for (auto& i: wq) {
            reverse(i.begin(), i.end());
            ans.push_back(root->getprefix(i));
        }

        return ans;
    }
};