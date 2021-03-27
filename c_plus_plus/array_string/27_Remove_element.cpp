class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = nums.size();
        for (int right = 0, left = 0; right < nums.size(); right++) {
            if (val == nums[right]) {
                cnt--;
            } else {
                nums[left++] = nums[right];
            } 
                
        }
        nums.resize(cnt);
        return nums.size();
    }
};
