class Solution {
public:
    string convertToBase7(int num) {
        if (!num) return "0";
        string str;
        bool neg = (num < 0) ? true: false;
        num = (num < 0) ? -num: num;
        while (num) {
            str += std::to_string(num % 7);
            num /= 7;
        }
        std::reverse(str.begin(), str.end());
        str = (neg) ? "-" + str : str;
        return str;
    }
};
