class Solution {
public:
    int singleNumber(vector<int>& nums) {
        #if 0
        unordered_set<int> set;
        for (auto n : nums) {
            if (set.find(n) == set.end())
                set.insert(n);
            else
                set.erase(n);
        }
        auto itr = set.begin();
        return *itr;
        #else
        int x = 0;
        for (auto n : nums)
            x = x ^ n;
        return x;
        #endif;
    }
};
