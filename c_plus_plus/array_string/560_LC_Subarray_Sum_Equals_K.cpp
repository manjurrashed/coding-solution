class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        #if 0
        //O(n3)
        int count = 0;
        for (int start = 0; start < nums.size(); start++) {
            for (int end = start; end < nums.size(); end++) {
                int sum = 0;
                for (int i = start; i <= end; i++) {
                    sum += nums[i];
                }
                count = (sum == k) ? count + 1: count;
            }
        }
        return count;
        #endif
        #if 0
        //O(n2)
        int count = 0;
        for (int idx = 0; idx < nums.size(); idx++) {
            int sum = 0;
            for (int i = idx; i < nums.size(); i++) {
                sum += nums[i];
                count = (sum == k) ? count + 1 : count;
            }
        }
        return count;
        #endif
        #if 0
        int count = 0;
        vector<int> sum(nums.size() + 1);
        sum[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum[i + 1] = sum[i] + nums[i];
        }
        for (int start = 0; start < sum.size() - 1; start++) {
            for (int end = start + 1; end < sum.size(); end++) {
                count = (sum[end] - sum[start] == k) ? count + 1: count;
            }
        }
        return count;
        #endif
        #if 1
        //O(n)
        int count = 0;
        unordered_map<int, int> map;
        int sum = 0;
        for (auto n : nums) {
            map[sum]++;
            sum += n;
            if (map.find(sum - k) != map.end())
                count += map[sum -k];
        }
        return count;
        #endif
    }
};
