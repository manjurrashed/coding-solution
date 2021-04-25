class Solution {
public:
    bool isAnagram(string s, string t) {
        #if 0
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
        #endif
        #if 1
        int sa[256] = {0};
        int ta[256] = {0};
        for (auto ch : s)
            sa[ch]++;
        for (auto ch: t)
            ta[ch]++;
        for (int i = 0; i < 256; i++) {
            if (sa[i] != ta[i])
                return false;
        }
        return true;
        #endif
    }
};
