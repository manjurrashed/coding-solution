class Solution {
public:
    void helper(string &digits, unordered_map<char, vector<char>> &phone, int level, vector<string> &result, string &array) {
        
        if (level == digits.length()) {
            //cout << array << endl;
            result.push_back(array);
        }
        vector<char> keys = phone[digits[level]];
        //cout << level << endl;
        
        for (auto key : keys) {
            array += key;
            helper(digits, phone, level + 1, result, array);
            array.pop_back();
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.length() == 0)
            return result;
        
        unordered_map<char, vector<char>> phone;
        phone['1'] = {};
        phone['2'] = {'a', 'b', 'c'};
        phone['3'] = {'d', 'e', 'f'};
        phone['4'] = {'g', 'h', 'i'};
        phone['5'] = {'j', 'k', 'l'};
        phone['6'] = {'m', 'n', 'o'};
        phone['7'] = {'p', 'q', 'r', 's'};
        phone['8'] = {'t', 'u', 'v'};
        phone['9'] = {'w', 'x', 'y', 'z'};
        phone['0'] = {};

        
        string array;
        
        helper(digits, phone, 0, result, array);
        
        return result;
    }
};
