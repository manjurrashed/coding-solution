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
	#if 0
	int s = 1;
        if (nums.size() < 2)
            return nums.size();
        for (int f = 1; f < nums.size(); f++) {
            if (nums[f] != nums[s - 1])
                nums[s++] = nums[f];
        }
        nums.resize(s);
        return nums.size();
	#endif
	#if 1
	 int s = 0;
        for (int f = 0; f < nums.size(); f++) {
            if (f + 1 < nums.size() && nums[f] != nums[f + 1] || f + 1 == nums.size())
                nums[s++] = nums[f];
        }
        nums.resize(s);
        return s;
	#endif
    }
};

