class Solution {
public:
    void reverse(vector<int>& nums, int left, int right) {
        while (left < right) {
            std::swap(nums[left++], nums[right--]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        k = k > nums.size() ? k % nums.size() : k;
        reverse(nums, 0, static_cast<int>(nums.size()) - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, static_cast<int>(nums.size()) - 1);
    }
};
