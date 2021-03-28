class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    //O(n3)
	#if 1
	int gmax = INT_MIN;
	for (int start = 0; start < nums.size(); start++) {
		for (int end = start; end < nums.size(); end++) {
			int sum = 0;
			for (int i = start ; i <= end; i++) {
				sum += nums[i];
			}
			gmax = max(gmax, sum);
		}
	}
  	return gmax;
	#endif
	//O(n2)
	#if 0
	vector<int> sum(nums.size() + 1, 0);
	for (int i = 1; i < sum.size(); i++) {
		sum[i] = sum[i - 1] + nums[i - 1];
	}
	int gmax = INT_MIN;
	for (int start = 0; start < sum.size() - 1; start++) {
		for (int end = start + 1; end < sum.size(); end++) {
			gmax = max(gmax, sum[end] - sum[start]);
		}
	}
	return gmax;
	#endif
	#if 0
	int gmax = INT_MIN;
	for (int idx = 0; idx < nums.size(); idx++) {
		int sum = 0;
		for (int i = idx; i < nums.size(); i++) {
			sum += nums[i];
			gmax = max(gmax, sum);
		}
	}
	return gmax;
	#endif
	//O(n) // Kadane's algorithm
	#if 0
	int lmax = 0;
	int gmax = INT_MIN;
	for (auto n : nums) {
		lmax = max(lmax + n, n);
		gmax = max(gmax, lmax);
	}
	return gmax;
	#endif
    }
};

