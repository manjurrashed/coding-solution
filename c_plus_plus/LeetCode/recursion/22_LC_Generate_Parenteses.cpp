class Solution {
public:
    void helper(int o, int c, string str, vector<string> &result) {
        if (o == 0 && c == 0) {
            result.push_back(str);
        }
        if (o > 0)
            helper(o - 1, c, str + "(", result);
        if (c > o)
            helper(o, c - 1, str + ")", result);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string str;
        helper(n, n, str, result);
        return result;
    }
};

