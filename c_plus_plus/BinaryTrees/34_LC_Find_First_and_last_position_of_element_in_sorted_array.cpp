class Solution {
public:
    int findLeft(vector<int>& nums, int target, int left, int right) {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (target == nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        return right + 1;
    }
    int findRight(vector<int>& nums, int target, int left, int right) {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (target == nums[mid])
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left - 1;
    }
    int findVal(vector<int>& nums, int target, int left, int right) {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (target < nums[mid])
                right = mid - 1;
            else if (target > nums[mid])
                left = mid + 1;
            else
                return mid;
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int mid = findVal(nums, target, 0, nums.size() - 1);
        if (mid < 0)
            return {-1, -1};
        int left = findLeft(nums, target, 0, mid);
        int right = findRight(nums, target, mid, nums.size() - 1);
        return {left, right};
    }
};
