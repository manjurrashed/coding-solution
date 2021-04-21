class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        for (int i = 0; i < s.length(); i++) {
            for (auto word : wordDict) {
                if (i >= word.length() - 1 && 
                    dp[i - word.length() + 1] &&
                    s.compare(i - word.length() + 1, word.length(), word) == 0)
                    dp[i + 1] = true;
            }
        }
        
        return dp[s.length()];
    }
};
