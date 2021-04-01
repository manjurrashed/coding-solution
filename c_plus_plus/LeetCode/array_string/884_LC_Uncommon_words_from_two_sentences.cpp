class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> result;
        unordered_map<string, int> map;
        char *buff;
        char *str = A.data();
        while (buff = strtok_r(str, " ", &str)) {
            map[buff]++;
        }
        
        str = B.data();
        while (buff = strtok_r(str, " ", &str)) {
            map[buff]++;
        }
        
        for (auto x : map) {
            if (x.second == 1)
                result.push_back(x.first);
        }

        return result;
    }
};

