class Solution {
public:
    int solve(int i, int d, vector<int>& dp, vector<int>& arr){
        if (dp[i]!=-1) return dp[i];

        int best =0;

        for (int jump=1; jump<=d; jump++){
            if (i+jump<arr.size() && arr[i+jump]>=arr[i]) break;
            best = max(best, solve(i+jump, d, dp, arr)); // max(dp[i+jump],dp[i])+1;
        }
        for (int jump=1; jump<=d; jump++){
            if (i-jump>=0 && arr[i-jump]>=arr[i] )break;
            best = max(best, solve(i-jump, d, dp, arr));
        }

        return dp[i] = best+1;//????

    }

    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n);
        int ans=0;

        for (int i=0; i<n ;i++){
            ans = max(ans, solve(i,d,dp,arr));
        }

        return ans;
    }
};

/* base case->
1. if taller building
2. if outofbounds

i-d, i+d-> 
max() ^

solve????
jump form i to j

*/