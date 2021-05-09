class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        #if 0
        string result = "";
        int idx = 0;
        while (strs.size() > 0) {
            char ch;
            if (strs[0] == "")
                return "";
            if (idx >= strs[0].length())
                return result;
            if (idx < strs[0].length())
                ch = strs[0][idx];
            for (int i = 1; i < strs.size(); i++) {
                if (idx >= strs[i].length() || ch != strs[i][idx])
                    return result;
            }
            result += ch;
            idx++;
        }
        return result;
        #endif
        #if 1
        string result = "";
        if (strs.size() < 1)
            return "";
        int idx = 0;
        while (true) {
            if (idx >= strs[0].length())
                    return result;
            for (int i = 1; i < strs.size(); i++) {
                if (idx >= strs[i].length() || strs[0][idx] != strs[i][idx])
                    return result;
            }
            result += strs[0][idx++];
        }
        return result;
        #endif
    }
};
