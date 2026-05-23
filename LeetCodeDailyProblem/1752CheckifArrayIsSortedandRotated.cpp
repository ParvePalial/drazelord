class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(), dec=0;

        for (int i=0; i<n-1; i++){
            if (nums[i]>nums[i+1]) dec++;
        }
        if (nums[n-1]>nums[0]) dec++;
        return dec<=1;
    }
};

//total decresing max 1;
// index 0,n-1 match 