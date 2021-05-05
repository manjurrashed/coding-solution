class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n, true);
        int x = sqrt(n);
        for (int i = 2; i <= x; i++) {
            for (int j = i * i; j < n; j = j + i) {
                prime[j] = false;
            }
        }
        
        int cnt = 0;
        for (int i = 2; i < n; i++) {
            if (prime[i])
                cnt++;
        }
        return cnt;
    }
};
