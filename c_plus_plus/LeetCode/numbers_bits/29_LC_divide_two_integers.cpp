class Solution {
public:
    int divide(int dividend, int divisor) {
        //19 / 3 = 6
        //3, 6, 12, || 24 < 19
        //19 - 12 = 7
        //3, 6, || 12 < 7
        //7 - 6 = 1
	if (divisor == 0)
            return INT_MAX;
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if (divisor == 1)
            return dividend;
        
        long dd = dividend;
        long dr = divisor;
        
        int sign = 1;
        if (dd < 0) {
            sign = -sign;
            dd = -dd;
        }
        if (dr < 0) {
            sign = -sign;
            dr = -dr;
        }

        int sum = 0;
        while (dd >= dr) {
            long val = dr;
            int pow = 1;
            while (val + val < dd) {
                val += val;
                pow <<= 1;
            }
            sum += pow;
            dd -= val;
        }
        return sum*sign;
    }
};
