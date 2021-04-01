class Solution {
public:
    void helper(unordered_map<int, int> &map, vector<vector<int>> &result, int index, vector<int>& nums) {
        if (index == nums.size()) {
            result.push_back(nums);
            return;
        }
        
        for (auto itr : map) {
            if (itr.second != 0) {
                map[itr.first]--;
                nums[index] = itr.first;
                helper(map, result, index + 1, nums);
                map[itr.first]++;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        //https://www.youtube.com/watch?v=nYFd7VHKyWQ&t=909s
        unordered_map<int, int> map;
        for (auto n : nums) {
            map[n]++;
        }

        vector<vector<int>> result;
        helper(map, result, 0, nums);

        return result;
    }
};
