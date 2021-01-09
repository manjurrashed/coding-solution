class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        unordered_set<int> set;
        for (auto x : nums)
            set.insert(x);
        for (int i = 1; i <= nums.size(); i++)
            if (set.find(i) == set.end())
                result.push_back(i);
        return result;
    }
};
