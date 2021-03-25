class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        int n = nums.size();
        if (n == 0 || k == 0)
            return result;

        #if 0
        //brute force O(k(n-k))
        for (int i = 0; i < n - k + 1; i++) {
            int x = INT_MIN;
            for (int j = i; j < i + k; j++) {
                x = max(x, nums[j]);
            }
            result.push_back(x);
        }
        #else
        //optimal O(n)
        deque<int> dq;
        for (int i = 0; i < n; i++) {
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);
            if (dq.front() == i - k)
                dq.pop_front();
            if (i >= k - 1)
                result.push_back(nums[dq.front()]);
                
        }
        #endif
    
        return result;
    }
};

