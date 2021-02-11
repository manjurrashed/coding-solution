class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int sum = 0;
        int count = 0;
        map[0] = 1;
        for (auto n : nums) {            
            sum += n;
            if (map.find(sum - k) != map.end()) {
                count += map[sum -k];
            }
            map[sum]++;
        }
        return count;
    }
};
