class Solution {
public:
    void helper(vector<int> &nums, int level, vector<vector<int>> &result) {
        if (level + 1 == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = level; i < nums.size(); i++) {
            swap(nums[level], nums[i]);
            helper(nums, level + 1, result);
            swap(nums[level], nums[i]);
        }
    }
    void helper2(unordered_map<int, int> &map, int level, vector<int> &nums, vector<vector<int>> &result) {
        if (level == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (auto itr : map) {
            if (map[itr.first] == 0)
                continue;
            map[itr.first]--;
            nums[level] = itr.first;
            helper2(map, level + 1, nums, result);
            map[itr.first]++;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        #if 1
        vector<vector<int>> result;
        helper(nums, 0, result);
        return result;
        #else
        vector<vector<int>> result;
        unordered_map<int, int> map;
        for (auto n : nums)
            map[n]++;
        helper2(map, 0, nums, result);
        return result;
        #endif
    }
};

