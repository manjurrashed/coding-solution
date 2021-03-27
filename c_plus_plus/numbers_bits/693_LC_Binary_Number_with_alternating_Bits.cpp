class Solution {
public:
    bool hasAlternatingBits(int n) {
        #if 0
        bool flag = n & 1;
        while (n) {
            if (flag != (n & 1))
                return false;
            n = n >> 1;
            flag = !flag;
        }
        return true;
        #else 
        
        while (n) {
            int x = n & 1;
            n >>= 1;
            if ((x ^ (n & 1)) == false)
                return false;
        }
        return true;
        
        #endif
    }
};

