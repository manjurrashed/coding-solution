class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        #if 0
        unordered_map<int, int> map;
        for (auto n: arr)
            map[n]++;
        vector<pair<int, int>> v(map.begin(), map.end());
        sort(v.begin(), v.end(), [](auto a, auto b){ return a.second < b.second; });
        for (int i = 1; i < v.size(); i++) {
            if (v[i].second == v[i - 1].second)
                return false;
        }
        return true;
        #endif
        
        unordered_map<int, int> map;
        unordered_set<int> set;
        for (auto n: arr)
            map[n]++;
        for (auto m : map)
            set.insert(m.second);
        return map.size() == set.size();
    }
};
