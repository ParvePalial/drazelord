// class Solution {
// public:
//     int solve(int i, int count, int m, int M, vector<int>& dp, string s){
//         if (i>=s.size()) return 0;

//         if (dp[i]!=-1) return dp[i];

//         for (int j=m; j<=M; j++){
//             if (s[i+j]=='0') solve(i+j,count+1, m,M, dp, s);
//         }
//         return dp[i] += 1;

//     }
//     bool canReach(string s, int minJump, int maxJump) {
//         int n = s.size();
//         vector<int> dp(n);
//         solve(0,0,minJump, maxJump, dp,s);

//         for (auto i: dp) cout<<i<<" ";
//         return dp[n-1];
//     }
// };

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
 

        int n = s.size();
        vector<int> dp(n,0);
        dp[0]=1;
        int cnt = 0;

        for (int i=1; i<n; i++){
            if (i-minJump>=0 && dp[i-minJump]) cnt++;
            if (i-maxJump-1>=0 && dp[i-maxJump-1]) cnt--;

            dp[i] = (cnt>0) && s[i]=='0';
        }

        //for (auto i: dp) cout<<i<<" ";
        return dp[n-1];
    }
};

// sliding window approach
// Max-min => window  if (!=-1 then jump further).....