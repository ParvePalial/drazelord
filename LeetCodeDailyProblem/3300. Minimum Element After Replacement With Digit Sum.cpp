class Solution {
public:
    int sums(int i){
        int res=0;
        while(i){
            res += i%10;
            i/=10;
        }
        return res;
    }
    int minElement(vector<int>& nums) {
        int n  = nums.size(), ans = INT_MAX;

        for (auto i: nums){
            ans = min(sums(i), ans);
        }

        return ans;
    }
};

