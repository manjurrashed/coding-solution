class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> map;
        for (auto ch : s)
            map[ch]++;
        #if 1
        sort(s.begin(), s.end(), [&map](char a, char b){ return (map[a] == map[b]) ? a > b : map[a] > map[b]; });
        return s;
        #endif
        
        // the follow did not work
        //sort(map.begin(); map.end(), [](auto a, auto b){ return a.second > b.second; });
        //string s1 = "";
        /*for (auto data : map) {
            cout << "test";
            //while(data.second--)
            //    s1 += data.first;
        }*/
        //return s1;
    }
};
