class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        
        for (auto n : nums) {
            if (map[n] == 2)
                map.erase(n);
            else
                map[n]++;
        }
        
        auto itr = map.begin();
        return itr->first;
    }
};
