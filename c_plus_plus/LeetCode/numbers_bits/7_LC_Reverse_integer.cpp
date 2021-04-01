class Solution {
public:
    int reverse(int x) {
        int r = 0;
        while (x) {
            //if (r + (x / 10) % 10 > INT_MAX/10)
            if (r > INT_MAX / 10 || (r == INT_MAX / 10 && (x % 10) > 7))
                return 0;
            //if (r + (x / 10) % 10 < INT_MIN/10)
            if (r < INT_MIN / 10 || (r == INT_MIN / 10 && (x % 10) < -8))
                return 0;
            r = 10*r + x%10;
            x = x / 10;
        }
        return r;
    }
};
