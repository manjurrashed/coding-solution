class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> result;
        return helper(s, wordDict, "", result);
    }
    vector<string> helper(string s, vector<string>& wordDict, string str, vector<string> &result) {
        for (auto word : wordDict) {
            if (s == word) {
                result.push_back(str + s);
            } else if (s.length() > word.length() && s.compare(0, word.length(), word) == 0) {
                helper(s.substr(word.length()), wordDict, str + word + " ", result);
            }
        }
        return result;
    }
};
