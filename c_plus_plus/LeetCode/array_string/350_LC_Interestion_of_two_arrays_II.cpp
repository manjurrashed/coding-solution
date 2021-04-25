class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        #if 0
        //time O(n), space O(n)
        if (nums1.size() < nums2.size())
            intersect(nums2, nums1);
        unordered_map<int, int> map;
        vector<int> result;
        for (auto n : nums2)
            map[n]++;
        for (auto n : nums1) {
            if (map.count(n) > 0) {
                map[n]--;
                if (map[n] == 0)
                    map.erase(n);
                result.push_back(n);
            }
        }
        return result;
        #endif
        #if 1
        //Time O(nlogn), Space O(1)
        vector<int> result;
        std::sort(nums1.begin(), nums1.end(), [](int a, int b) { return a < b; });
        std::sort(nums2.begin(), nums2.end(), [](int a, int b) { return a < b; });
        int s1 = 0;
        int s2 = 0; 
        while (s1 < nums1.size() && s2 < nums2.size()) {
            if (nums1[s1] < nums2[s2]) {
                s1++;
            } else if (nums2[s2] < nums1[s1]) {
                s2++;
            } else {
                result.push_back(nums1[s1]);
                s1++;
                s2++;
            }
        }
        return result;
        #endif
    }
};
