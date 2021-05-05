class Solution {
public:
    bool isPowerOfThree(int n) {
        #if 0
        int prod = 1;
        while (prod <= n) {
            if (prod == n)
                return true;
            if (INT_MAX / 3 < prod)
                return false;
            prod *= 3;
        }
        return false;
        #endif
        #if 0
        if (n < 1)
            return false;
        while (n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
        #endif
        #if 0
        int left = 0;
        int right = n / 3;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            double m = pow(3, mid);
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
        double m = log10(n) / log10(3);
        return m == int(m);
        #endif
    }
};
