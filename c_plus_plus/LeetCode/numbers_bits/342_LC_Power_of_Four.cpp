class Solution {
public:
    bool isPowerOfFour(int n) {
        #if 0
        if (n < 1)
            return false;
        while (n % 4 == 0) {
            n /= 4;
        }
        return n == 1;
        #endif
        #if 0
        int left = 0;
        int right = n / 4;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            double m = pow(4, mid);
            if (m == n)
                return true;
            if (m > n)
                right = mid - 1;
            else 
                left = mid + 1;
        }
        return false;
        #endif
        #if 1
        if (n < 1)
            return false;
        double m = log10(n)/log10(4);
        return m == int(m);
        #endif
    }
};
