class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lowerocc(26,-1);
        vector<int> upperocc(26,-1);
        int n = word.size(),ans=0;

        for (int i=0; i<n; i++){
            int l = word[i]-'a';
            int u = word[i]-'A';
            if (l>=0 && l<26) lowerocc[l]=i;
            if (u>=0 && u<26 && upperocc[u]==-1) upperocc[u]=i;
        }

        for (int i=0; i<26;i++){
            if (lowerocc[i]!=-1 && upperocc[i]!=-1 && lowerocc[i]<upperocc[i]) ans++;
        }

        return ans;
    }
};