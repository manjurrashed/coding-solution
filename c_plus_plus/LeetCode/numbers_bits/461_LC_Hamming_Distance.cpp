class Solution {
public:
    int hammingDistance(int x, int y) {
        #if 0
        int cnt = 0;
        while (x | y) {
            cnt += (x & 1) ^ (y & 1);
            x >>= 1;
            y >>= 1;
        }
        return cnt;
        #endif
        #if 1
        int cnt = 0;
        int n = x ^ y;
        while (n) {
            n = n & (n - 1);
            cnt++;
        }
        return cnt;
        #endif
    }
};
