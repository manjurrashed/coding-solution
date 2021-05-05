class Solution {
public:
    int reverse(int x) {
	#if 0
        int r = 0;
        while (x) {
            if (r > INT_MAX / 10 || (r == INT_MAX / 10 && (x % 10) > 7))
                return 0;
            if (r < INT_MIN / 10 || (r == INT_MIN / 10 && (x % 10) < -8))
                return 0;
            r = 10*r + x%10;
            x = x / 10;
        }
        return r;
	#else
        int r = 0;
        while (x) {
            if (r >= INT_MAX / 10 + x % 10)
                return 0;
            if (r <= INT_MIN / 10 + x % 10)
                return 0;
            r = 10 * r + x % 10;
            x = x / 10;
        }
        return r;
	#endif
    }
};
