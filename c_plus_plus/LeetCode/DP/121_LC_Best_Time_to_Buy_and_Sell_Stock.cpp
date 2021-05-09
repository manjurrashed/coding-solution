class Solution {
public:
    int maxProfit(vector<int>& prices) {
        #if 0
        int max_profit = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            for (int j = i + 1; j < prices.size(); j++) {
                max_profit = max(prices[j] - prices[i], max_profit);
            }
        }
        return max_profit;
        #endif
        #if 0
        if (prices.size() < 2) {
            return 0;
        }
        
        int profit = 0;
        int minPrice = INT_MAX;
        
        for (int i = 0; i < prices.size(); i++) {
            if (minPrice > prices[i]) {
                minPrice = prices[i];
            } else {
                if (profit < prices[i] - minPrice)
                    profit = prices[i] - minPrice;
            }
        }
        
        return profit;
        #endif
        #if 1
        int min_price = INT_MAX;
        int profit = 0;
        for (auto p : prices) {
            if (p < min_price)
                min_price = p;
            else {
                profit = max(p - min_price, profit);
            }

        }
        return profit;
        #endif
    }
};
