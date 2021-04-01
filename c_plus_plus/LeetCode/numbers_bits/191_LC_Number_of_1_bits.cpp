class Solution {
public:
    int hammingWeight(uint32_t n) {
        return [](uint32_t x) { int cnt = 0; while (x) { cnt++; x = x & (x - 1); } return cnt; }(n);
    }
};
