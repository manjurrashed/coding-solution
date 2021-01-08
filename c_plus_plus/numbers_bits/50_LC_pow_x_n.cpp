class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == -1) return 1/x;
        if (n == 1) return x;

        long num = n;
        if (n < 0) {
            num = -num;
        }

        double result = myPow(x, num / 2);
        result *= result;
        if (num % 2 == 1) 
            result *= x;

        if (n < -1)
            result = 1 / result;
        
	return result;
    }
};
