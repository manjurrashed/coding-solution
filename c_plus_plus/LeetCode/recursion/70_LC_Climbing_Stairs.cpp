class Solution {
    unordered_map<int, int> map;
public:
    int climbStairs(int n) {
        #if 0
        //recursive
        if (n < 0)
            return 0;
        if (n == 0)
            return 1;
        return climbStairs(n - 1) + climbStairs(n - 2);
        #endif
        #if 0
        //recursive with memorization
        if (n < 0)
            return 0;
        if (n == 0)
            return 1;
        if (map.count(n))
            return map[n];
        map[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return map[n];
        #endif
        #if 1
        //iterative.
        int f1 = 0;
        int f2 = 1;
        for (int i = 1; i < n; i++) {
            int temp = f1 + f2;
            f1 = f2;
            f2 = temp;
        }
        return f1 + f2;
        #endif
    }
};
