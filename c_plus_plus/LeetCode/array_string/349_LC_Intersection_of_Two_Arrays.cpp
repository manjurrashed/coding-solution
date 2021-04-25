class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return intersection(nums2, nums1);
        }
        
        unordered_set<int> set;
        for (auto n : nums1) {
            set.insert(n);
        }
        
        vector<int> result;
        
        for (auto n : nums2) {
            if (set.count(n)) {
                result.push_back(n);
                set.erase(n);
            }
        }
        return result;
    }
};
