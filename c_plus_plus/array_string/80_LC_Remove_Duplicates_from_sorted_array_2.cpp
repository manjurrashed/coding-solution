class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3)
            return nums.size();
        
        int s = 2;
        for (int f = 2; f < nums.size(); f++) {
            if (nums[f] != nums[s - 2]) {
                nums[s++] = nums[f];
            }
        }
        nums.resize(s);
        return nums.size();
    }
};
