class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        #if 1
        unordered_map<int, int> map;
        for (auto n : nums)
            map[n]++;
        int sum = 0;
        for (auto data : map) 
            sum += (data.second == 1) ? data.first : 0;
        return sum;
        #endif
    }
};

