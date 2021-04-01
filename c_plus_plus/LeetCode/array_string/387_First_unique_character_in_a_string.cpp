class Solution {
public:
    int firstUniqChar(string s) {
        #if 0
        for (int i = 0; i < s.length(); i++) {
            int cnt = 0;
            for (int j = 0; j < s.length(); j++) {
                if (s[i] == s[j])
                    cnt++;
            }
            if (cnt == 1)
                return i;
        }
        return -1;
        #endif
        
        #if 0
        unordered_map<int, int> map;
        for (auto ch : s) {
            map[ch]++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (map[s[i]] == 1)
                return i;
        }
        return -1;
        #endif
        
        #if 0
        unique_ptr<int[]> map(new int[26]{0});
        for (auto ch : s)
            map[ch - 'a']++;
        for (int i = 0; i < s.length(); i++) {
            if (map[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
        #endif
        
        #if 0
        shared_ptr<int[]> map(new int[26]{0});
        for (auto ch : s) {
            map[ch - 'a']++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (map[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
        #endif
        
        #if 1
        vector<int> vec(26, 0);
        for (auto ch : s)
            vec[ch - 'a']++;
        for (int i = 0; i < s.length(); i++)
            if (vec[s[i] - 'a'] == 1)
                return i;
        return -1;
        #endif
    }
};
