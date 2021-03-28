class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
	#if 0
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
	#endif
	int s = 1;
        if (nums.size() < 2)
            return nums.size();
        for (int f = 1; f < nums.size(); f++) {
            if (nums[f] != nums[s - 1])
                nums[s++] = nums[f];
        }
        nums.resize(s);
        return nums.size();
    }
};

