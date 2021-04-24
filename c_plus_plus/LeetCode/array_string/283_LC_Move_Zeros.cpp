class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        #if 0
        int b = 0;
        for (int f = 0; f < nums.size(); f++) {
            if (nums[f] != 0)
                nums[b++] = nums[f];
        }
        while (b < nums.size())
            nums[b++] = 0;
        #endif
        #if 1
        int b = 0;
        for (int f = 0; f < nums.size(); f++) {
            if (nums[f] != 0)
                std::swap(nums[b++], nums[f]);
        }
        #endif
    }
};
