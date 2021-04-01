class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int sum = 0;
	// write the index of each number to the prefix sum's modules of k. 
	// if all the while array is consider then it's module is 0, so we need -1 initially
	//
        map[0] = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (k != 0)
                sum = sum % k;
            if (map.find(sum) != map.end()) {
                if (i - map[sum] > 1) 
                return true;
            } else {
                map[sum] = i;
            }
        }
        return false;

	#if 0
        vector<int> sum(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            sum[i + 1] = sum[i] + nums[i];
        }
        for (int start = 0; start < sum.size() - 2; start++) {
            for (int end = start + 2; end < sum.size(); end++) {
                if ((sum[end] - sum[start]) % k == 0)
                    return true;
            }
        }
        return false;
        #endif

    }
};

