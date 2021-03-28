class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        #if 0
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
	#endif
	        
	int s = 0;
        for (int f = 0; f < nums.size(); f++) {
            if (val != nums[f])
                nums[s++] = nums[f];
        }
        nums.resize(s);
        return nums.size();
    }
};
