class Solution {
public:
    void helper( vector<int>& nums, int index, vector<int> &data, vector<vector<int>> &result) {
        
        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1]) continue;
            data.push_back(nums[i]);
            result.push_back(data);
            helper(nums, i + 1, data, result);
            data.pop_back();

        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> data;
        result.push_back(data);
            
        sort(nums.begin(), nums.end());
        
        helper(nums, 0, data, result);
        
        return result;
    }
};
