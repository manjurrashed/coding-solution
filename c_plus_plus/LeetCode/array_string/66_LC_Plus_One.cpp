class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        #if 0
        vector<int> result;
        int carry = 1;
        for (int i = digits.size() - 1; i > -1; i--) {
            result.push_back((digits[i] + carry) % 10);
            carry = (digits[i] + carry) / 10;
        }
        if (carry)
            result.push_back(carry);
        std::reverse(result.begin(), result.end());
        return result;
        #endif
        #if 1
        int sum = 1;
        for (int i = digits.size() - 1; i > -1; i--) {
            sum += digits[i];
            digits[i] = (sum > 9) ? sum - 10 : sum;
            sum =  (sum > 9) ? 1 : 0;
        }
        if (sum)
            digits.insert(digits.begin(), sum);
        return digits;
        #endif
    }
};
