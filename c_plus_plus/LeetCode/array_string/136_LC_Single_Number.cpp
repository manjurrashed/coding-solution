class Solution {
public:
    int singleNumber(vector<int>& nums) {
        #if 0
        int sum = 0;
        unordered_set<int> s;
        for (auto n : nums) {
            if (s.count(n)) {
                sum -= n;
                s.erase(n);
            } else {
                sum += n;
                s.insert(n);
            }
        }
        return sum;
        #endif
        #if 0
        int sum = 0;
        for (auto n : nums) {
            sum ^= n;
        }
        return sum;
        #endif
        #if 1
        unordered_set<int> s;
        for (auto n : nums) {
            if (s.count(n))
                s.erase(n);
            else
                s.insert(n);
        }
        return *s.begin();
        #endif
    }
};
