class Solution {
public:
    int myAtoi(string s) {
        #if 0
        int idx = 0;
        while (s[idx] == ' ') idx++;
        bool neg = s[idx] == '-' ? true : false;
        idx = (neg) ? idx + 1 : idx;
        idx = (!neg && s[idx] == '+') ? idx + 1 : idx;
        int num = 0;
        cout << neg << endl;
        for ( auto ch : s.substr(idx)) {
            if (ch < '0' || ch > '9')
                break;
            int x = ch - '0';
            if (!neg && INT_MAX/10 - num < 0)
                    return INT_MAX;
            if (!neg && INT_MAX - 10*num <= x)
                    return INT_MAX;
            if (neg && (INT_MAX)/10 - num < 0)
                    return INT_MIN;
            if (neg && INT_MAX - 10*num <= x - 1)
                    return INT_MIN;
            num = 10*num + x;
        }
        return (neg ? -num : num);
        #endif
        #if 1
        int idx = 0;
        while (s[idx] == ' ') idx++;
        bool neg = s[idx] == '-' ? true : false;
        idx = (neg) ? idx + 1 : idx;
        idx = (!neg && s[idx] == '+') ? idx + 1 : idx;
        int num = 0;
        cout << neg << endl;
        for ( auto ch : s.substr(idx)) {
            if (ch < '0' || ch > '9')
                break;
            int x = ch - '0';
            if (num > INT_MAX/10 || INT_MAX - 10*num < x) {
                return (neg ? INT_MIN : INT_MAX);
            }
            num = 10*num + x;
        }
        return (neg ? -num : num);
        #endif
    }
};

