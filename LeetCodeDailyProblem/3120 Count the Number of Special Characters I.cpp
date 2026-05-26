class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> big(26) ;
        vector<int> small(26) ;
        int ans =0;

        for (auto c: word){
            if (c-'a'>=0 && c-'a'<26) small[c-'a']++;
            if (c-'A'>=0 && c-'A'<26) big[c-'A']++;
        }

        for (int i=0; i<26; i++){
            if (big[i] && small[i]) ans++;
        }

        return ans;
    }
};