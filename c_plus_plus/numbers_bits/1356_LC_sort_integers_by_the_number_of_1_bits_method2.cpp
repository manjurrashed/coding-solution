class Solution {
public:
    int bitcount(int n) {
        int count = 0;
        while (n) {
            count++;
            n = n & (n - 1);
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> map;
        for (auto num : arr) {
            map.push_back({bitcount(num), num});
        }
        
        sort(map.begin(), map.end());
        
        vector<int> result;
        for (auto data : map) {
            result.push_back(data.second);
        }
        return result;
    }
};
