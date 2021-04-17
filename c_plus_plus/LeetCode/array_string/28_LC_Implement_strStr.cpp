class Solution {
public:
    int strStr(string haystack, string needle) {
        if (!needle.length())
            return 0;
        for (int i = 0; i < (int)haystack.length() - (int)needle.length() + 1; i++) {
            if (haystack[i] == needle[0]) {
                int j = 0;
                while(j < needle.length() && (haystack[i + j] == needle[j])) {
                    j++;
                }
                if (j == needle.length())
                    return i;
            }
            
        }
        return -1;
    }
};
