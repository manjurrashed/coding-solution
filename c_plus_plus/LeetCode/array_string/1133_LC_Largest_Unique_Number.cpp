class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        unordered_map<int, int> map;
        for (auto n : A) 
            map[n]++;
        int large = -1;
        for (auto m : map) {
            large = (m.second == 1) ? max(large, m.first) : large;
        }
        return large;
    }
};
