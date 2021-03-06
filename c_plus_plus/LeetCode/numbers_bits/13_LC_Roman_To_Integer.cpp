class Solution {
public:
    int romanToInt(string s) {
        //I, II, III, (IV), V, VI, VII, VIII, (IX), X
        //X, XX, XXX, (XL), L, LX, LXX, LXXX, (XC), C
        //C, CC, CCC, (CD), D, DC, DCC, DCCC, (CM), M
        //
        unordered_map<char, int> map = {{'I', 1},
                                        {'V', 5},
                                        {'X', 10},
                                        {'L', 50},
                                        {'C', 100},
                                        {'D', 500},
                                        {'M', 1000}};
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i + 1 < s.length() && map[s[i]] < map[s[i + 1]])
                sum -= map[s[i]];
            else
                sum += map[s[i]];
        }
        return sum;
    }
};
