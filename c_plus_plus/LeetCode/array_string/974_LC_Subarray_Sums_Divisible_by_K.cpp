class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int count = 0;
        unordered_map<int, int> map;
        int sum = 0;
        map[0] = 1;
        for (auto n : A) {
            sum = (sum + n) % K;
            sum = (sum < 0) ? sum + K: sum;
            count += map[sum];
            map[sum]++;
        }
        return count;
    }
};

