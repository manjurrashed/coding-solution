class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result;
        for (int i = 0; i <= num; i++) {
            auto bits = [](int x){ int cnt = 0; while (x) {cnt++; x = x & (x - 1); } return cnt; };
            result.push_back(bits(i));
        }
        return result;
    }
};
