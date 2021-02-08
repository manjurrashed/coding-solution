class Solution {
public:
    void helper(vector<int>& nums, int index, vector<int> &data, vector<vector<int>> &result) {
        if (index == nums.size()) {
            result.push_back(data);
            return;
        }
        
        helper(nums, index + 1, data, result);
        data.push_back(nums[index]);
        helper(nums, index + 1, data, result);
        data.pop_back();

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> data;
        
        helper(nums, 0, data, result);
        
        return result;
    }
};
