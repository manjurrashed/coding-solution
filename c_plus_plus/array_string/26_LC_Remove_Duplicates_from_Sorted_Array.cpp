class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = nums.size();
        for (int right = 1, left = 0; right < nums.size(); right++) {
            if (nums[left] != nums[right]) {
                nums[++left] = nums[right];
            } else {
                cnt--;
            }
        }
        nums.resize(cnt);
        return nums.size();
    }
};

