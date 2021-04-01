class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> map;
        for (auto n : nums)
            map[n]++;
        sort(nums.begin(), nums.end(), [&](int a, int b) { return (map[a] == map[b]) ? a > b : map[a] < map[b]; });
        return nums;
    }
};
