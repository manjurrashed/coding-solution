class Solution {
public:
    bool contains(unordered_map<char, int> &map_t, unordered_map<char, int> &map_sub) {
        //Does map_t contain in map_sub?
        for (auto sm : map_t) {
            if (map_sub.find(sm.first) == map_sub.end())
                return false;
            if (sm.second > map_sub[sm.first])
                return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        unordered_map<char, int> map_t;
        for (auto ch : t)
            map_t[ch]++;
        
        int left = 0;
        int right = 0;
        string result = "";
        int min_len = INT_MAX;
        int min_idx = 0;
        
        unordered_map<char, int> map_sub;
        map_sub[s[right]]++;

        while (right < s.length()) {
            
            if (contains(map_t, map_sub)) {
                if (min_len > right - left + 1) {
                    min_len = right - left + 1;
                    min_idx = left;
                }
                if (map_sub[s[left]] > 1) {
                    map_sub[s[left]]--;
                } else {
                    map_sub.erase(s[left]);
                }
                left++;
            } else {
                right++;
                map_sub[s[right]]++;
            }
            
        }
        if (min_len != INT_MAX)
            result = s.substr(min_idx, min_len);
        return result;
    }
};

