class Solution {
    vector<int> data;
    vector<int> stuff;
public:
    Solution(vector<int>& nums) {
        data = nums;
        stuff = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        stuff = data;
        return data;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int len = stuff.size();
        for (int i=len-1; i >= 0; --i) {
            swap(stuff[i], stuff[rand()%(i + 1)]);
        }
        return stuff;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
