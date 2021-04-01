class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        #if 0
        for (int start = 0; start < nums.size() - 1; start++) {
            for (int end = start + 1; end < nums.size(); end++) {
                if (nums[start] + nums[end] == target)
                    return {start, end};
            }
        }
        return {};
        #endif
        #if 1
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(target -  nums[i]) != map.end())
                return {map[target -  nums[i]], i};
                
            map[nums[i]] = i;
        }
        return {};
        #endif
    }
};
