class Solution {
public:
    string say(string &str) {
        string ans;
        int cnt = 1;
        int n = str.length();
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && str[i] == str[i + 1]) {
                cnt++;
            } else {
                ans += std::to_string(cnt);
                ans += str[i];
                cnt = 1;
            }
        }
        return ans;
    }
    string countAndSay(int n) {
        string result = "1";
        n--;
        while (n--) {
            result = say(result);
        }
        return result;
    }
};
