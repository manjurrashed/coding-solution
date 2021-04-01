class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_set<int> set;
        for (auto n : nums) {
            if (set.find(n) == set.end())
                set.insert(n);
            else
                set.erase(n);
        }
        vector<int> result(set.begin(), set.end());
        return result;
    }
};

