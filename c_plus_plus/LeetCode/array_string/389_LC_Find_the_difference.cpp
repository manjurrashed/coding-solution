class Solution {
public:
    char findTheDifference(string s, string t) {
        #if 0
        unordered_map<char, int> map;
        for (auto ch : t)
            map[ch]++;
        for (auto ch : s) {
            map[ch]--;
            if (map[ch] == 0)
                map.erase(ch);
        }
        auto itr = map.begin();
        return itr->first;
        #endif
        
        #if 0
        char x = 0;
        for (auto ch : t)
            x = x ^ ch;
        for (auto ch : s)
            x = x ^ ch;
        return x;
        #endif
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        for (int i = 0; i < t.length(); i++)
            if (s[i] != t[i])
                return t[i];
        return 'a';
    }
};
