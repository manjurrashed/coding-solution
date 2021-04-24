class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        #if 1
        multiset<long> window;
        for (int right = 0; right < nums.size(); right++) {
            if (right > k) window.erase(nums[right - k - 1]);
            auto safe = window.lower_bound((long)nums[right] - (long)t);
            if (safe != window.end() && *safe <= (long)nums[right] + (long)t) return true;
            window.insert(nums[right]);
        }
        return false;
        #endif
    }
};

