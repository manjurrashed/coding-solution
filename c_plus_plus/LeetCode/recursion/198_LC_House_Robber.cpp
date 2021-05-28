class Solution {
public:
    int helper(vector<int>& nums, int s) {
        if (s >= nums.size())
            return 0;
        return max(helper(nums, s + 1), nums[s] + helper(nums, s + 2));
    }
    int rob(vector<int>& nums) {
        #if 0
        return helper(nums, 0);
        #endif
        #if 1
        if (nums.size() < 1)
            return 0;
        int prev1 = 0;
        int prev2 = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int cur = max(prev2, prev1 + nums[i]);
            prev1 = prev2;
            prev2 = cur;
        }
        return prev2;
        #endif
    }
};
