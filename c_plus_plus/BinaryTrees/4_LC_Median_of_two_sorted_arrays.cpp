class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int size = nums1.size() + nums2.size();
        
        int start = 0;
        int end = nums1.size();

        int x1 = 0;
        int y1 = 0;
        
        while (start <= end) {
            x1 = (start + end) / 2;
            y1 = (size + 1) / 2 - x1;
            
            int maxLeftX = (x1 == 0) ? INT_MIN : nums1[x1 - 1];
            int minRightX = (x1 == nums1.size() ? INT_MAX : nums1[x1]);
            
            int maxLeftY = (y1 == 0) ? INT_MIN : nums2[y1 - 1];
            int minRightY = (y1 == nums2.size() ? INT_MAX : nums2[y1]);
            
            if (maxLeftX > minRightY) {
                end = x1 - 1;
            } else if (maxLeftY > minRightX) {
                start = x1 + 1;
            } else {
                if (size % 2 == 1)
                    return max(maxLeftX, maxLeftY);
                return ( max(maxLeftX, maxLeftY) +  min(minRightX, minRightY)) / 2.0;
            }
        }
        
        return -1;
    }
};
