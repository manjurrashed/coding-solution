class Solution {
public:
    int missingNumber(vector<int>& nums) {
	#if 0
	//time O(n) and space(n)
        unordered_set<int> set;
        for (auto x : nums)
            set.insert(x);
        
        for (int i = 0; i <= nums.size(); i++)
            if (set.find(i) == set.end())
                return i;
        return -1;
	#endif
        #if 0
        //time O(n), space O(1)
        int result = 0;
        for (int i = 0; i < nums.size(); i++)
            result = result ^ nums[i] ^ i;
        result ^= nums.size();
        return result;
        #endif;
        #if 0
        //time O(n), space O(1)
        int n = (nums.size() * (nums.size() + 1)) / 2;
        for (auto k : nums)
            n -= k;
        return n;
    }
};

